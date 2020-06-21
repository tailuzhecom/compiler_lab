//
// Created by young on 2020/6/15.
//

#ifndef LAB2_CGEN_H
#define LAB2_CGEN_H

#include <iostream>
#include <vector>
#include <string>

#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_os_ostream.h"
#include <fstream>

using namespace llvm;

class Beg;
class Expr;
class Block;
class ObjMember;

// 符号表
class SymboTable {
public:
    void Enterscope(); // 进入作用域
    void Exitscope(); // 退出作用域
    void AddItem(const std::string &name, Value* val); // 添加变量
    Value* Lookup(const std::string &name); // 在所有范围查找变量
    Value* Probe(const std::string &name); // 在最新的作用查找变量
    void clear();

private:
    std::vector<std::map<std::string, Value*> > table_;
};

class ASTNode {
public:
    virtual Value *Cgen() = 0;
};

// 程序节点，AST的根节点
class Program : public ASTNode {
public:
    Program(const std::string &file_name = "output.ll") : output_file_name_(file_name) {
        std::cout << "Program create" << std::endl;
        Init();
    }
    ~Program() { std::cout << "Program destroy" << std::endl; }
    void Init();
    void Append(std::shared_ptr<ASTNode> b);

    Value *Cgen();

private:
    std::vector<std::shared_ptr<ASTNode> > begs_;
    std::string output_file_name_;
};

class Beg : public ASTNode {
public:
    Beg();
    void Show();

private:
    std::string name_;
};

// 变量定义节点
class VariableDef {
public:
    VariableDef() {}
    VariableDef(std::string type, std::string name) : type_(type), name_(name) {}
    std::string type_;
    std::string name_;
};

// 变量节点
class Variable {
public:
    Variable() {}
    Variable(std::string type, std::string name, std::shared_ptr<Expr> init_val = NULL) : type_(type), name_(name), init_val_(init_val) {}
    std::string type_;
    std::string name_;
    std::shared_ptr<Expr> init_val_;
};

// 形参列表
class ArgsList {
public:
    void Append(VariableDef arg);
    std::vector<VariableDef> args_;
};

// iden列表，用于声明，不包含类型，初值可选
class IdList {
public:
    IdList() {}

    void Append(Variable var) {
        ids_.push_back(var);
    }

    std::vector<Variable> GetIds() { return ids_; }

private:
    std::vector<Variable> ids_;
};

// 类节点
class Class : public ASTNode {
public:
    Class(std::string name, std::shared_ptr<ArgsList> memeber_list) : name_(name), member_varibles_(memeber_list) {}
    Value *Cgen();

private:
    std::string name_;
    std::shared_ptr<ArgsList> member_varibles_;
};

// 语句节点，作为AST一个类别汇总
class Sentence : public ASTNode {
public:
    Value *Cgen();
};

// 声明语句
class DeclStmt : public Sentence {
public:
    // 添加声明的变量
    DeclStmt() {}
    DeclStmt(const std::vector<Variable> &vars) : vars_(vars) {}
    ~DeclStmt() { std::cout << "DeclStmt destroy" << std::endl; }

    void Append(std::string type, std::string name, std::shared_ptr<Expr> init_val);
    // 设置vars_中的所有变量的类型为type
    void SetTypeForAllVariables(std::string type);
    Value *Cgen();
    std::vector<Variable> GetVars();

private:
    std::vector<Variable> vars_;
};

// 赋值语句
class AssignStmt : public Sentence {
public:
    AssignStmt() {}
    AssignStmt(std::string var_name, std::shared_ptr<Expr> assign_expr) {
        var_name_ = var_name;
        assign_expr_ = assign_expr;
    }

    AssignStmt(std::shared_ptr<ObjMember> obj_member, std::shared_ptr<Expr> assign_expr) :
        obj_member_(obj_member), assign_expr_(assign_expr) {}

    ~AssignStmt() { std::cout << "AssignStmt destroy" << std::endl; }
    std::string GetName() { return var_name_; }
    std::shared_ptr<Expr> GetVal() { return assign_expr_; }

    Value *Cgen();

private:
    std::string var_name_;
    std::shared_ptr<ObjMember> obj_member_ = nullptr;
    std::shared_ptr<Expr> assign_expr_;
};

// 条件语句
class IfStmt : public Sentence {
public:
    IfStmt() : true_block_(NULL), false_block_(NULL), bool_expr_(NULL) {}
    ~IfStmt() { std::cout << "IfStmt destroy" << std::endl; }
    void SetTrueBlock(std::shared_ptr<Block> true_block);
    void SetFalseBlock(std::shared_ptr<Block> false_block);
    void SetBoolExpr(std::shared_ptr<Expr> bool_expr);

    Value *Cgen();

private:
    std::shared_ptr<Expr> bool_expr_;
    std::shared_ptr<Block> true_block_;
    std::shared_ptr<Block> false_block_;
};

// 返回语句
class ReturnStmt : public Sentence {
public:
    ReturnStmt(std::shared_ptr<Expr> expr) : expr_(expr) {}
    ~ReturnStmt() { std::cout << "ReturnStmt destroy" << std::endl; }
    Value *Cgen();

private:
    std::shared_ptr<Expr> expr_;
};

// Break语句
class BreakStmt : public Sentence {
public:
    Value *Cgen();

private:
};

// While语句
class WhileStmt : public Sentence {
public:
    WhileStmt(std::shared_ptr<Expr> bool_expr, std::shared_ptr<Block> block) : bool_expr_(bool_expr), block_(block) {}
    Value *Cgen();

private:
    std::shared_ptr<Expr> bool_expr_;
    std::shared_ptr<Block> block_;
};

// For语句
class ForStmt : public Sentence {
public:
    ForStmt(std::shared_ptr<DeclStmt> init_sentence, std::shared_ptr<Expr> bool_expr, std::shared_ptr<AssignStmt> after_sentence, std::shared_ptr<Block> loop_block) :
        init_sentence_(init_sentence), bool_expr_(bool_expr), after_sentence_(after_sentence),
        loop_block_(loop_block) {}

    Value *Cgen();

private:
    std::shared_ptr<DeclStmt> init_sentence_;
    std::shared_ptr<Expr> bool_expr_;
    std::shared_ptr<AssignStmt> after_sentence_;
    std::shared_ptr<Block> loop_block_;
};

// Switch语句
class SwitchStmt : public Sentence {
public:
    Value *Cgen();
private:
};

// 表达式语句
class Expr : public Sentence {
public:
    Value *Cgen();
private:
};

class Factor : public Expr {
public:
private:
};

enum BinOp {
    add_op,
    sub_op,
    mul_op,
    div_op,
    mod_op,
    eq_op,
    neq_op,
    less_op,
    lesseq_op,
    greater_op,
    greatereq_op,
    and_op,
    or_op
};

// 二元运算表达式
class BinExpr : public Expr {
public:
    BinExpr(BinOp op, std::shared_ptr<Expr> expr1, std::shared_ptr<Expr> expr2) :
        op_(op), expr1_(expr1), expr2_(expr2) {}
    ~BinExpr() { std::cout << "BinExpr destroy" << std::endl; }
    Value *Cgen();

private:
    BinOp op_;
    std::shared_ptr<Expr> expr1_;
    std::shared_ptr<Expr> expr2_;
};

enum SingleOp {
    not_op,
    neg_op
};

// 一元运算表达式
class SingleExpr : public Expr {
public:
    SingleExpr(SingleOp op, std::shared_ptr<Expr> expr) : op_(op), expr_(expr) {}
    Value *Cgen();
private:
    int op_;
    std::shared_ptr<Expr> expr_;
};

// 字符串常量
class StringConst : public Expr {
public:
    StringConst(const std::string &s) : string_val_(s) {}
    Value *Cgen();
private:
    std::string string_val_;
};

// 整型常量
class IntConst : public Factor {
public:
    IntConst(int val) : int_val_(val) {}
    Value *Cgen();

private:
    int int_val_;
};

// 浮点数常量
class FloatConst : public Factor {
public:
    FloatConst(float val) : float_val_(val) {}
    Value *Cgen();

private:
    float float_val_;
};

// expr中的变量
class Identity : public Factor {
public:
    Identity(const std::string &name) : name_(name) {}
    Value *Cgen();

private:
    std::string name_;
};

// 普通函数调用
class CallStmt : public Factor {
public:
    CallStmt() {}
    CallStmt(std::string func_name, const std::vector<std::shared_ptr<Expr> > &vals) :
        func_name_(func_name), vals_(vals) {}

    Value *Cgen();

private:
    std::string func_name_;
    std::vector<std::shared_ptr<Expr> > vals_;
};

// 类成员变量
class ObjMember : public Factor {
public:
    ObjMember(const std::string &var_name, const std::string &member_name) :
        var_name_(var_name), member_name_(member_name){}
    void SetIsVar(bool is_var) { is_var_ = is_var; }
    Value *Cgen();

private:
    std::string var_name_;
    std::string member_name_;
    bool is_var_ = false;
};

// 类函数调用
class ObjCall : public Factor {
public:
    Value *Cgen();
private:
    std::string obj_name_;
    std::shared_ptr<CallStmt> call_stmt_;
};

// 函数体展开
class Block : public ASTNode {
public:
    void Append(std::shared_ptr<Sentence> s);

    Value *Cgen();

private:
    std::vector<std::shared_ptr<Sentence> > sentence_;
};

// 函数节点
class Func : public ASTNode {
public:
    Func(std::string return_type, std::string name, std::shared_ptr<ArgsList> args, std::shared_ptr<Block> block) {
        // TODO: 成员初始化
        return_type_ = return_type;
        func_name_ = name;
        args_ = args;
        block_ = block;
    }
    virtual ~Func() { std::cout << "Func destroy" << std::endl; }
    Value *Cgen();

private:
    std::string return_type_;   // 函数返回类型
    std::string func_name_; // 函数名字
    std::shared_ptr<ArgsList> args_; // 形参列表
    std::shared_ptr<Block> block_;  // 函数体
};

// 实参list
class ExprList {
public:
    ExprList() {}
    void Append(std::shared_ptr<Expr> expr) { expr_list_.push_back(expr); }
    std::vector<std::shared_ptr<Expr> > GetExprList() { return expr_list_; }

private:
    std::vector<std::shared_ptr<Expr> > expr_list_;
};



/////////////////////////////////////
// util function
/////////////////////////////////////

// 将string转换为llvm::Type*
Type* UtilConvertStrToType(const std::string &type_str);

#endif //LAB2_CGEN_H
