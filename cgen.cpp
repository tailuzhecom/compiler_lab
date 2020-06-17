//
// Created by young on 2020/6/15.
//

#include "cgen.h"
#include <iostream>
#include <vector>
#include <string>


// 程序节点，AST的根节点
void Program::Append(ASTNode *b) {
    begs_.push_back(b);
}

void * Program::Cgen() {
    std::cout << "program size: " << begs_.size() << std::endl;
    for (int i = 0; i < begs_.size(); i++) {
        begs_[i]->Cgen();
    }
}


void *Class::Cgen() {
    std::cout << "class def" << std::endl;
    std::cout << "class name: " << name_ << std::endl;
    std::cout << "class member:" << std::endl;
    for (int i = 0; i < member_varibles_->args_.size(); i++) {
        std::cout << "type: " << member_varibles_->args_[i].type_
                << " name: " << member_varibles_->args_[i].name_ << std::endl;
    }

    return NULL;
}



void *Sentence::Cgen() {
    std::cout << "NULL Sentence" << std::endl;
    return NULL;
}


// 声明语句

// 添加声明的变量
void DeclStmt::Append(std::string type, std::string name, Expr *init_val) {
    vars_.push_back(Variable(type, name, init_val));
}

void *DeclStmt::Cgen() {
    // TODO
    std::cout << "decl_stmt" << std::endl;
    for (int i = 0; i < vars_.size(); i++) {
        std::cout << "type: " << vars_[i].type_ << " name: " << vars_[i].name_ << std::endl;
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
void *AssignStmt::Cgen() {
    std::cout << "assign_stmt" << std::endl;
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

void *IfStmt::Cgen() {
    std::cout << "if_stmt" << std::endl;
    bool_expr_->Cgen();
    true_block_->Cgen();
    if (false_block_)
        false_block_->Cgen();
    return NULL;
}


// 返回语句
void *ReturnStmt::Cgen() {
    std::cout << "return_stmt" << std::endl;
    return NULL;
}



// Break语句
void *BreakStmt::Cgen() {
    std::cout << "break_stmt" << std::endl;
    return NULL;
}



// While语句
void *WhileStmt::Cgen() {
    std::cout << "while_stmt" << std::endl;
    std::cout << "bool expr: " << std::endl;
    bool_expr_->Cgen();
    std::cout << "block: " << std::endl;
    block_->Cgen();
    return NULL;
}

// For语句
void *ForStmt::Cgen() {
    std::cout << "for_stmt" << std::endl;
    if (init_sentence_)
    std::cout << "init sentence:" << std::endl;
    init_sentence_->Cgen();
    std::cout << "bool expr:" << std::endl;
    bool_expr_->Cgen();
    std::cout << "after sentence" << std::endl;
    after_sentence_->Cgen();
    std::cout << "loop block:" << std::endl;
    loop_block_->Cgen();
    return NULL;
}


// Switch语句
void *SwitchStmt::Cgen() {
    std::cout << "switch_stmt" << std::endl;
    return NULL;
}

// 表达式语句
void *Expr::Cgen() {
    std::cout << "Expr" << std::endl;
    return NULL;
}

// 二元运算表达式

void *BinExpr::Cgen() {
    std::cout << "bin_expr" << std::endl;
    return NULL;
}

// 一元运算表达式
void *SingleExpr::Cgen() {
    std::cout << "single_expr" << std::endl;
    return NULL;
}

// 普通函数调用
void *CallStmt::Cgen() {
    std::cout << "call_stmt" << std::endl;
    std::cout << "func_name: " << func_name_ << " val_num: " << vals_.size() << std::endl;
    return NULL;
}

// 普通变量
void *Identity::Cgen() {
    std::cout << "identity" << std::endl;
    return NULL;
}

// 类成员变量
void *ObjMember::Cgen() {
    std::cout << "obj_member" << std::endl;
    return NULL;
}

// 类函数调用
void *ObjCall::Cgen() {
    std::cout << "obj_call" << std::endl;
    return NULL;
}

// 函数体展开
void Block::Append(Sentence *s) {
    sentence_.push_back(s);
}

void *Block::Cgen() {
    std::cout << "block" << std::endl;
    for (int i = 0; i < sentence_.size(); i++) {
        sentence_[i]->Cgen();
    }
    return NULL;
}


// 函数节点
void *Function::Cgen() {
    // TODO
    std::cout << "function" << std::endl;
    std::cout << "return_type: " << return_type_ << " func: " << func_name_ << std::endl;
    std::cout << "args list:" << std::endl;
    for (int i = 0; i < args_->args_.size(); i++) {
        std::cout << "arg_type: " << args_->args_[i].type_
                << " arg_name: " << args_->args_[i].name_ << std::endl;
    }
    block_->Cgen();
    return NULL;
}


void ArgsList::Append(VariableDef arg) {
    args_.push_back(arg);
}
