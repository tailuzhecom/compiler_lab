//
// Created by young on 2020/6/15.
//

#ifndef LAB2_CGEN_H
#define LAB2_CGEN_H

#include <iostream>
#include <vector>
#include <string>

class Beg;
class Expr;


class ASTNode {
public:
    virtual void *cgen() = 0;
};

// 程序节点，AST的根节点
class Program : public ASTNode {
public:
    Program();
    void Append(ASTNode *b) {
        begs_.push_back(b);
    }

    void *cgen() {
        for (int i = 0; i < begs_.size(); i++) {
            begs_[i]->cgen();
        }
    }

private:
    std::vector<ASTNode*> begs_;
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
    std::string type_;
    std::string name_;
};

// 变量节点
class Variable {
public:
    std::string type_;
    std::string name_;
    int int_val_;
    float float_val_;
};

// 类节点
class Class : public ASTNode {
private:
    std::vector<VariableDef> member_varibles_;

public:
    void *cgen() {
        std::cout << "class def" << std::endl;
        return NULL;
    }
};

// 语句节点，作为AST一个类别汇总
class Sentence : public ASTNode {
public:
    void *cgen() {
        std::cout << "NULL Sentence" << std::endl;
        return NULL;
    }
};

// 声明语句
class DeclStmt : public Sentence {
public:
    // 添加声明的变量
    void AppendVariable(std::string type, std::string name, int val) {
        Variable tmp;
        tmp.type_ = type;
        tmp.name_ = name;
        tmp.int_val_ = val;
        vars_.push_back(tmp);
    }

    void *cgen() {
        // TODO
        std::cout << "decl_stmt" << std::endl;
        return NULL;
    }
private:
    std::vector<Variable> vars_;
};

// 赋值语句
class AssignStmt : public  Sentence {
public:
    AssignStmt() {}
    AssignStmt(std::string var_name, int assign_val_) {
        var_name_ = var_name;
        assign_val_ = assign_val_;
    }

    void *cgen() {
        std::cout << "assign_stmt" << std::endl;
        return NULL;
    }

private:
    std::string var_name_;
    int assign_val_;
};

// 条件语句
class IfStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "if_stmt" << std::endl;
        return NULL;
    }
private:
};

// 返回语句
class ReturnStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "return_stmt" << std::endl;
        return NULL;
    }

private:
    Expr *expr_;
};

// Break语句
class BreakStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "break_stmt" << std::endl;
        return NULL;
    }

private:
};

// While语句
class WhileStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "while_stmt" << std::endl;
        return NULL;
    }

private:
};

// For语句
class ForStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "for_stmt" << std::endl;
        return NULL;
    }

private:
};

// Switch语句
class SwitchStmt : public Sentence {
public:
    void *cgen() {
        std::cout << "switch_stmt" << std::endl;
        return NULL;
    }
private:
};

// 表达式语句
class Expr : public Sentence {
public:
    void *cgen() {
        std::cout << "Expr" << std::endl;
        return NULL;
    }
private:
};

class Factor : public Expr {
public:
private:
};

// 二元运算表达式
class BinExpr : public Expr {
public:
    void *cgen() {
        std::cout << "bin_expr" << std::endl;
        return NULL;
    }
private:
    int op_;
    Expr *expr1_;
    Expr *expr2_;
};

// 一元运算表达式
class SingleExpr : public Expr {
public:
    void *cgen() {
        std::cout << "single_expr" << std::endl;
        return NULL;
    }
private:
    int op_;
    Expr *expr_;
};

// 字符串常量
class StringConst : public Expr {
public:
private:
    std::string string_val_;
};

// 整型常量
class IntConst : public Factor {
public:
private:
    int int_val_;
};

// 浮点数常量
class FloatConst : public Factor {
public:
private:
    float float_val_;
};

// 普通函数调用
class CallStmt : public Factor {
public:
    void *cgen() {
        std::cout << "call_stmt" << std::endl;
        return NULL;
    }

private:
    std::string func_name_;
    std::vector<Expr*> vals_;
};

// 普通变量
class Identity : public Factor {
public:
    void *cgen() {
        std::cout << "identity" << std::endl;
        return NULL;
    }

private:
    std::string var_name_;
};

// 类成员变量
class ObjMember : public Factor {
public:
    void *cgen() {
        std::cout << "obj_member" << std::endl;
        return NULL;
    }

private:
    std::string var_name_;
    std::string member_name_;
};

// 类函数调用
class ObjCall : public Factor {
public:
    void *cgen() {
        std::cout << "obj_call" << std::endl;
        return NULL;
    }
private:
    std::string obj_name_;
    CallStmt *call_stmt_;
};



// 函数体展开
class Statement : public ASTNode {
public:
    void Append(Sentence *s) {
        sentence_.push_back(s);
    }

    void *cgen() {
        std::cout << "Statements" << std::endl;
        for (int i = 0; i < sentence_.size(); i++) {
            sentence_[i]->cgen();
        }
        return NULL;
    }

private:
    std::vector<Sentence*> sentence_;
};

// 函数节点
class Function : public ASTNode {
public:
    Function(std::string name) {
        // TODO: 成员初始化
        func_name_ = name;
    }

    void *cgen() {
        // TODO
        std::cout << "function" << std::endl;
        return NULL;
    }

private:
    std::string return_type_;
    std::string func_name_;
    std::vector<VariableDef> args_;
};




#endif //LAB2_CGEN_H
