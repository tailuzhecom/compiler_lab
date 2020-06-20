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

    void Init();
    void Append(ASTNode *b);

    Value *Cgen();

private:
    std::vector<ASTNode*> begs_;
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
    Variable(std::string type, std::string name, Expr *init_val = NULL) : type_(type), name_(name), init_val_(init_val) {}
    std::string type_;
    std::string name_;
    Expr *init_val_;
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
    Class(std::string name, ArgsList *memeber_list) : name_(name), member_varibles_(memeber_list) {}
    Value *Cgen();

private:
    std::string name_;
    ArgsList *member_varibles_;
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
    void Append(std::string type, std::string name, Expr *init_val);
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
    AssignStmt(std::string var_name, Expr *assign_expr) {
        var_name_ = var_name;
        assign_expr_ = assign_expr;
    }

    AssignStmt(ObjMember *obj_member, Expr *assign_expr) :
        obj_member_(obj_member), assign_expr_(assign_expr) {}

    std::string GetName() { return var_name_; }
    Expr *GetVal() { return assign_expr_; }

    Value *Cgen();

private:
    std::string var_name_;
    ObjMember *obj_member_ = nullptr;
    Expr *assign_expr_;
};

// 条件语句
class IfStmt : public Sentence {
public:
    IfStmt() : true_block_(NULL), false_block_(NULL), bool_expr_(NULL) {}

    void SetTrueBlock(Block *true_block);
    void SetFalseBlock(Block *false_block);
    void SetBoolExpr(Expr *bool_expr);

    Value *Cgen();

private:
    Expr *bool_expr_;
    Block *true_block_;
    Block *false_block_;
};

// 返回语句
class ReturnStmt : public Sentence {
public:
    ReturnStmt(Expr *expr) : expr_(expr) {}
    Value *Cgen();

private:
    Expr *expr_;
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
    WhileStmt(Expr *bool_expr, Block *block) : bool_expr_(bool_expr), block_(block) {}
    Value *Cgen();

private:
    Expr *bool_expr_;
    Block *block_;
};

// For语句
class ForStmt : public Sentence {
public:
    ForStmt(DeclStmt *init_sentence, Expr *bool_expr, AssignStmt *after_sentence, Block *loop_block) :
        init_sentence_(init_sentence), bool_expr_(bool_expr), after_sentence_(after_sentence),
        loop_block_(loop_block) {}

    Value *Cgen();

private:
    DeclStmt *init_sentence_;
    Expr *bool_expr_;
    AssignStmt *after_sentence_;
    Block *loop_block_;
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
    BinExpr(BinOp op, Expr *expr1, Expr *expr2) :
        op_(op), expr1_(expr1), expr2_(expr2) {}

    Value *Cgen();

private:
    BinOp op_;
    Expr *expr1_;
    Expr *expr2_;
};

enum SingleOp {
    not_op,
    neg_op
};

// 一元运算表达式
class SingleExpr : public Expr {
public:
    SingleExpr(SingleOp op, Expr *expr) : op_(op), expr_(expr) {}
    Value *Cgen();
private:
    int op_;
    Expr *expr_;
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
    CallStmt(std::string func_name, const std::vector<Expr*> &vals) :
        func_name_(func_name), vals_(vals) {}

    Value *Cgen();

private:
    std::string func_name_;
    std::vector<Expr*> vals_;
};

// 类成员变量
class ObjMember : public Factor {
public:
    ObjMember(const std::string &var_name, const std::string &member_name) :
        var_name_(var_name), member_name_(member_name) {}
    Value *Cgen();

private:
    std::string var_name_;
    std::string member_name_;
};

// 类函数调用
class ObjCall : public Factor {
public:
    Value *Cgen();
private:
    std::string obj_name_;
    CallStmt *call_stmt_;
};

// 函数体展开
class Block : public ASTNode {
public:
    void Append(Sentence *s);

    Value *Cgen();

private:
    std::vector<Sentence*> sentence_;
};

// 函数节点
class Func : public ASTNode {
public:
    Func(std::string return_type, std::string name, ArgsList *args, Block *block) {
        // TODO: 成员初始化
        return_type_ = return_type;
        func_name_ = name;
        args_ = args;
        block_ = block;
    }

    Value *Cgen();

private:
    std::string return_type_;   // 函数返回类型
    std::string func_name_; // 函数名字
    ArgsList *args_; // 形参列表
    Block *block_;  // 函数体
};

// 实参list
class ExprList {
public:
    ExprList() {}
    void Append(Expr *expr) { expr_list_.push_back(expr); }
    std::vector<Expr*> GetExprList() { return expr_list_; }

private:
    std::vector<Expr*> expr_list_;
};



/////////////////////////////////////
// util function
/////////////////////////////////////

// 将string转换为llvm::Type*
Type* UtilConvertStrToType(const std::string &type_str);

#endif //LAB2_CGEN_H
