//
// Created by young on 2020/6/15.
//

#include "cgen.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

llvm::LLVMContext TheContext;
IRBuilder<> Builder(TheContext);
std::unique_ptr<Module> TheModule;
SymboTable symbol_table;
std::map<Type*, std::map<std::string, int> > class_mem_offset;


// 程序节点，AST的根节点
void Program::Append(ASTNode *b) {
    begs_.push_back(b);
}

Value *Program::Cgen() {
    std::cout << "program size: " << begs_.size() << std::endl;
    symbol_table.Enterscope();
    for (int i = 0; i < begs_.size(); i++) {
        begs_[i]->Cgen();
    }
    symbol_table.Exitscope();

    // 将生成的llvm ir打印到输出文件
    std::ofstream s(output_file_name_ + ".ll");
    if (!s) {
        std::cerr << "cannot open output file" << std::endl;
        exit(1);
    }
    std::ostream &s1 = s;
    raw_os_ostream os(s1);
    TheModule->print(os, nullptr);

}

// 初始化llvm环境
void Program::Init() {
    TheModule = make_unique<Module>("rush", TheContext);
//    InitializeNativeTarget();
//    InitializeNativeTargetAsmPrinter();
//    InitializeNativeTargetAsmPrinter();
    TheModule->setDataLayout(TheModule->getTargetTriple());
    FunctionType *print_type = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(TheContext),
            {llvm::Type::getInt8PtrTy(TheContext)},
            true);
    Function::Create(print_type, llvm::GlobalValue::ExternalLinkage, "printf", TheModule.get());
}


Value *Class::Cgen() {
    std::cout << "class def" << std::endl;
    std::cout << "class name: " << name_ << std::endl;
    std::cout << "class member:" << std::endl;

    StructType *class_type = StructType::create(TheContext, name_);
    for (int i = 0; i < member_varibles_->args_.size(); i++) {
        std::cout << "type: " << member_varibles_->args_[i].type_
                << " name: " << member_varibles_->args_[i].name_ << std::endl;
        class_mem_offset[class_type->getPointerTo()][member_varibles_->args_[i].name_] = i;
    }


    std::vector<Type*> member_types;
    for (int i = 0; i < member_varibles_->args_.size(); i++) {
        member_types.push_back(UtilConvertStrToType(member_varibles_->args_[i].type_));
    }
    class_type->setBody(member_types);
    return NULL;
}



Value *Sentence::Cgen() {
    std::cout << "NULL Sentence" << std::endl;
    return NULL;
}


// 声明语句

// 添加声明的变量
void DeclStmt::Append(std::string type, std::string name, Expr *init_val) {
    vars_.push_back(Variable(type, name, init_val));
}

Value *DeclStmt::Cgen() {
    // TODO
    std::cout << "decl_stmt" << std::endl;
    for (int i = 0; i < vars_.size(); i++) {
        std::cout << "type: " << vars_[i].type_ << " name: " << vars_[i].name_
            << " init_expr: " << std::endl;


        AllocaInst *var_ptr = Builder.CreateAlloca(UtilConvertStrToType(vars_[i].type_), nullptr, vars_[i].name_);
        symbol_table.AddItem(vars_[i].name_, var_ptr); // 将声明的变量加入符号表
        Value *init_val = nullptr;
        if (vars_[i].init_val_)
            init_val = vars_[i].init_val_->Cgen();
        else
            std::cout << "null expr" << std::endl;

        if (init_val)
            Builder.CreateStore(init_val, var_ptr);
    }
    return NULL;
}

std::vector<Variable> DeclStmt::GetVars() {
    return vars_;
}

void DeclStmt::SetTypeForAllVariables(std::string type) {
    for (int i = 0; i < vars_.size(); i++) {
        vars_[i].type_ = type;
    }
}


// 赋值语句
Value *AssignStmt::Cgen() {
    std::cout << "assign_stmt" << std::endl;
    if (obj_member_ == nullptr) // 如果变量是基本类型
        Builder.CreateStore(assign_expr_->Cgen(), symbol_table.Lookup(var_name_));
    else { // 如果变量是成员变量
        Builder.CreateStore(assign_expr_->Cgen(), obj_member_->Cgen());
    }


    return NULL;
}

// 条件语句
void IfStmt::SetTrueBlock(Block *true_block) {
    true_block_ = true_block;
}

void IfStmt::SetFalseBlock(Block *false_block) {
    false_block_ = false_block;
}

void IfStmt::SetBoolExpr(Expr *bool_expr) {
    bool_expr_ = bool_expr;
}

Value *IfStmt::Cgen() {
    std::cout << "if_stmt" << std::endl;
    Function *curr_func = Builder.GetInsertBlock()->getParent();
    // if中判断条件表达式结果
    Value *cond_val = bool_expr_->Cgen();

    BasicBlock *then_block = BasicBlock::Create(TheContext, "then", curr_func);
    BasicBlock *else_block = BasicBlock::Create(TheContext, "else", curr_func);
    BasicBlock *merge_block = BasicBlock::Create(TheContext, "merge", curr_func);

    Builder.CreateCondBr(cond_val, then_block, else_block);

    Builder.SetInsertPoint(then_block);

    // env->enterscope();
    true_block_->Cgen();
    // env->exitscope();

    Builder.CreateBr(merge_block);

    // false chain
    Builder.SetInsertPoint(else_block);
    // env->enterscope();
    false_block_->Cgen();
    // env->exitscope();
    Builder.CreateBr(merge_block);

    Builder.SetInsertPoint(merge_block);
    PHINode *phi_node = Builder.CreatePHI(Type::getInt32Ty(TheContext), 2, "phi_val");
    phi_node->addIncoming(ConstantInt::get(TheContext, APInt(32, 1)), then_block);
    phi_node->addIncoming(ConstantInt::get(TheContext, APInt(32, 1)), else_block);
    return NULL;
}


// 返回语句
Value *ReturnStmt::Cgen() {
    std::cout << "return_stmt" << std::endl;
    Value *ret_val = expr_->Cgen();
    if (ret_val)
        Builder.CreateRet(ret_val);
    else
        Builder.CreateRetVoid();
    return nullptr;
}



// Break语句
Value *BreakStmt::Cgen() {
    std::cout << "break_stmt" << std::endl;
    return NULL;
}



// While语句
Value *WhileStmt::Cgen() {
    Function *curr_func = Builder.GetInsertBlock()->getParent();

	// condition block
	BasicBlock *cond_block = BasicBlock::Create(TheContext, "cond", curr_func);
	BasicBlock *body_block = BasicBlock::Create(TheContext, "body", curr_func);
	BasicBlock *end_block = BasicBlock::Create(TheContext, "", curr_func);
	Builder.CreateBr(cond_block);    // br cond;

	// codition block
	Builder.SetInsertPoint(cond_block);
	Value *cond_res = bool_expr_->Cgen(); // 条件值
	Builder.CreateCondBr(cond_res, body_block, end_block);

	// while body
	Builder.SetInsertPoint(body_block);

	symbol_table.Enterscope();
	block_->Cgen();
	symbol_table.Exitscope();

	Builder.CreateBr(cond_block);

	// end body
	Builder.SetInsertPoint(end_block);

    return NULL;
}

// For语句
Value *ForStmt::Cgen() {
    symbol_table.Enterscope();

    Function *curr_func = Builder.GetInsertBlock()->getParent();
    // 初始化语句
    if (init_sentence_)
        init_sentence_->Cgen();

    // condition block
    BasicBlock *cond_block = BasicBlock::Create(TheContext, "cond", curr_func);
    BasicBlock *body_block = BasicBlock::Create(TheContext, "body", curr_func);
    BasicBlock *end_block = BasicBlock::Create(TheContext, "", curr_func);
    Builder.CreateBr(cond_block);    // br cond;

    // codition block
    Builder.SetInsertPoint(cond_block);
    Value *cond_res = bool_expr_->Cgen(); // 条件值
    Builder.CreateCondBr(cond_res, body_block, end_block);

    // for body
    Builder.SetInsertPoint(body_block);
    symbol_table.Enterscope();
    loop_block_->Cgen();
    symbol_table.Exitscope();

    after_sentence_->Cgen(); // 执行完body后的处理语句
    Builder.CreateBr(cond_block);

    // end body
    Builder.SetInsertPoint(end_block);
    symbol_table.Exitscope();
    return NULL;
}


// Switch语句
Value *SwitchStmt::Cgen() {
    std::cout << "switch_stmt" << std::endl;
    return NULL;
}

// 表达式语句
Value *Expr::Cgen() {
    std::cout << "Expr" << std::endl;
    return NULL;
}

// 二元运算表达式
Value *BinExpr::Cgen() {
    std::cout << "bin_expr" << std::endl;
    switch (op_) {
        case add_op:
            return Builder.CreateAdd(expr1_->Cgen(), expr2_->Cgen());
            break;
        case sub_op:
            return Builder.CreateSub(expr1_->Cgen(), expr2_->Cgen());
            break;
        case mul_op:
            return Builder.CreateMul(expr1_->Cgen(), expr2_->Cgen());
            std::cout << "op: mul" << std::endl;
            break;
        case div_op:
            return Builder.CreateFDiv(expr1_->Cgen(), expr2_->Cgen());
            break;
        case mod_op:
            // TODO
            return Builder.CreateFDiv(expr1_->Cgen(), expr2_->Cgen());
            break;
        case eq_op:
            return Builder.CreateICmpEQ(expr1_->Cgen(), expr2_->Cgen());
            break;
        case neq_op:
            return Builder.CreateICmpNE(expr1_->Cgen(), expr2_->Cgen());
            break;
        case less_op:
            return Builder.CreateICmpSLT(expr1_->Cgen(), expr2_->Cgen());
            break;
        case lesseq_op:
            return Builder.CreateICmpSLE(expr1_->Cgen(), expr2_->Cgen());
            break;
        case greater_op:
            Builder.CreateICmpSGT(expr1_->Cgen(), expr2_->Cgen());
            break;
        case greatereq_op:
            Builder.CreateICmpSGE(expr1_->Cgen(), expr2_->Cgen());
            break;
        case and_op:
            Builder.CreateAnd(expr1_->Cgen(), expr2_->Cgen());
            break;
        case or_op:
            Builder.CreateOr(expr1_->Cgen(), expr2_->Cgen());
            break;
        default:
            std::cout << "false op" << std::endl;
    }

    return NULL;
}

// 一元运算表达式
Value *SingleExpr::Cgen() {
    std::cout << "single_expr" << std::endl;
    switch (op_) {
        case not_op:
            return Builder.CreateNot(expr_->Cgen());
            break;
        case neg_op:
            return Builder.CreateNeg(expr_->Cgen());
            break;
        default:
            std::cout << "false op" << std::endl;
    }
    return NULL;
}

// 普通函数调用
Value *CallStmt::Cgen() {
    std::cout << "call_stmt" << std::endl;
    std::cout << "func_name: " << func_name_ << " val_num: " << vals_.size() << std::endl;
    Function *func = TheModule->getFunction(func_name_);
    if (func == nullptr)
        std::cout << "func is null" << std::endl;
    else
        std::cout << "func has declared" << std::endl;
    std::vector<Value*> vals;
    for (int i = 0; i < vals_.size(); i++) {
        vals.push_back(vals_[i]->Cgen());
    }
    return Builder.CreateCall(func, vals);
}

// 普通变量
Value *Identity::Cgen() {
    std::cout << "Identity: " << name_ << std::endl;
    Value *iden_ptr = nullptr;
    if (iden_ptr = symbol_table.Lookup(name_))
        return Builder.CreateLoad(iden_ptr, ""); //　返回变量对应的值
    else {
        std::cout << "Identity doesn't exist" << std::endl;
        return nullptr;
    }

}

// 类成员变量
Value *ObjMember::Cgen() {
    std::cout << "obj_member" << std::endl;
    Value *var = symbol_table.Lookup(var_name_);
    if (var == nullptr) {
        std::cout << "variable doesn't exist." << std::endl;
        return NULL;
    }

    if (class_mem_offset[var->getType()].count(member_name_)) {
        int offset = class_mem_offset[var->getType()][member_name_];
        std::vector<Value*> gep_list({ConstantInt::get(Type::getInt32Ty(TheContext), APInt(32, 0)),
                                      ConstantInt::get(Type::getInt32Ty(TheContext), APInt(32, offset))});
        Value *attr_ptr = Builder.CreateGEP(var, gep_list);
        return attr_ptr;
    }
    else {
        std::cout << "member doesn't exist." << std::endl;
        return NULL;
    }
    return NULL;
}

// 类函数调用
Value *ObjCall::Cgen() {
    std::cout << "obj_call" << std::endl;
    return NULL;
}

// 函数体展开
void Block::Append(Sentence *s) {
    sentence_.push_back(s);
}

Value *Block::Cgen() {
    std::cout << "block" << std::endl;
    for (int i = 0; i < sentence_.size(); i++) {
        sentence_[i]->Cgen();
    }
    return NULL;
}


// 函数节点
Value *Func::Cgen() {
    // TODO
    std::cout << "function" << std::endl;

    std::cout << "return_type: " << return_type_ << " func: " << func_name_ << std::endl;
    std::cout << "args list:" << std::endl;

    for (int i = 0; i < args_->args_.size(); i++) {
        std::cout << "arg_type: " << args_->args_[i].type_
                << " arg_name: " << args_->args_[i].name_ << std::endl;
    }


    // cgen
    // 设置形参类型
    symbol_table.Enterscope();
    std::vector<Type*> args_type_list;
    for (int i = 0; i < args_->args_.size(); i++) {
        args_type_list.push_back(UtilConvertStrToType(args_->args_[i].type_));
    }

    // 创建函数
    FunctionType *func_type = FunctionType::get(UtilConvertStrToType(return_type_), args_type_list, false);
    Function * func = Function::Create(func_type, Function::ExternalLinkage, func_name_, TheModule.get());

    unsigned idx = 0;

    BasicBlock *entry_block = BasicBlock::Create(TheContext, "entry", func);
    Builder.SetInsertPoint(entry_block);

    for (auto &arg : func->args()) {
        // arg.setName(args_->args_[idx].name_); // 设置形参名字
        Value *arg_ptr = Builder.CreateAlloca(args_type_list[idx], nullptr, args_->args_[idx].name_); // 为形参创建变量
        Builder.CreateStore(&arg, arg_ptr);
        symbol_table.AddItem(args_->args_[idx].name_, arg_ptr); // 添加形参到符号表
        idx++;
    }

    block_->Cgen();
    symbol_table.Exitscope();
    return NULL;
}


void ArgsList::Append(VariableDef arg) {
    args_.push_back(arg);
}

Value *IntConst::Cgen() {
    std::cout << "IntConst: " << int_val_ <<std::endl;
    return ConstantInt::get(TheContext, APInt(32, int_val_));
}

Value *FloatConst::Cgen() {
    std::cout << "FloatConst: " << float_val_ <<std::endl;
    return ConstantFP::get(TheContext, APFloat(float_val_));
}


Type *UtilConvertStrToType(const std::string &type_str) {
    if (type_str == "int")
        return Type::getInt32Ty(TheContext);
    else if (type_str == "bool")
        return Type::getInt1Ty(TheContext);
    else if (type_str == "string")
        return Type::getInt8Ty(TheContext)->getPointerTo(); // TODO
    else if (type_str == "void")
        return Type::getVoidTy(TheContext);
    else if (type_str == "double")
        return Type::getDoubleTy(TheContext);
    else if (type_str == "float")
        return Type::getFloatTy(TheContext);
    else
        return TheModule->getTypeByName(type_str);
}

void SymboTable::Enterscope() {
    table_.push_back(std::map<std::string, Value*>());
}

void SymboTable::Exitscope() {
    table_.erase(table_.end() - 1);
}

void SymboTable::AddItem(const std::string &name, Value *val) {
    table_[table_.size() - 1][name] = val;
}

Value *SymboTable::Lookup(const std::string &name) {
    for (int i = table_.size() - 1; i >= 0 ; i--) {
        auto res = table_[i][name];
        if (res)
            return res;
    }
    return nullptr;
}

Value *SymboTable::Probe(const std::string &name) {
    if (table_.size() == 0)
        return nullptr;

    auto res = table_[table_.size() - 1][name];
    if (res)
        return res;
    return nullptr;
}

void SymboTable::clear() {
    table_.clear();
}

Value *StringConst::Cgen() {
    return Builder.CreateGlobalStringPtr(string_val_);
}
