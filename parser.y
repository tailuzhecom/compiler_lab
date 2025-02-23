 /* filename -> parser.y */
%require "3.0.4"

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "cgen.h"

std::shared_ptr<Program> prog = NULL;

void yyerror(char *s, ...);
int yylex();
%}

%debug

%locations

%union {
    int intval;
    double floatval;
    char *strval;
    int subtok;
    ASTNode *node;
    Block *block_ptr;
    Sentence *sentence_ptr;
    IfStmt *ifstmt_ptr;
    WhileStmt *whilestmt_ptr;
    ForStmt *forstmt_ptr;
    DeclStmt *declstmt_ptr;
    AssignStmt *assignstmt_ptr;
    Expr *expr_ptr;
    std::string *str_ptr;
    ArgsList *argslist_ptr;
    IdList *idlist_ptr;
    ExprList *exprlist_ptr;
    CallStmt *callstmt_ptr;
    Factor *factor_ptr;
    BinExpr *binexpr_ptr;
    SingleExpr *singleexpr_ptr;
    ReturnStmt *returnstmt_ptr;
    ObjMember *objmember_ptr;
}

/* token*/
%token INT
%token FLOAT
%token DOUBLE
%token LONG
%token UNSIGNED
%token CLASS
%token SHORT
%token SIGNED
%token CHAR
%token VOID
%token BREAK
%token SWITCH
%token CASE
%token ELSE
%token FOR WHILE
%token IF
%token RETURN


%token LPAREN RPAREN LBRACKET RBRACKET ':'
%token <strval> IDENTITY
%token <intval> INT_NUMBER
%token <floatval> FLOAT_NUMBER
%token <strval> STRING


%left OR
%left AND
%left ASSIGN
%left '!'
%left '+' '-'
%left '*' '/' '%'
%left EQUAL LESS LESS_E GREATER GREATER_E

%type <strval> type_dec
%type <node> beg
%type <node> func class_decl
%type <node> case_list obj_call
%type <block_ptr> block
%type <sentence_ptr> sentence break_stmt switch_stmt
%type <ifstmt_ptr> if_stmt
%type <whilestmt_ptr> while_stmt
%type <forstmt_ptr> for_stmt
%type <declstmt_ptr> decl_stmt global_decl_stmt
%type <assignstmt_ptr> assign_stmt
%type <expr_ptr> expr
%type <argslist_ptr> args_list class_decl_stmt_list
%type <idlist_ptr> id_list
%type <callstmt_ptr> call_stmt
%type <exprlist_ptr> expr_list
%type <factor_ptr> factor
%type <binexpr_ptr> bin_expr
%type <singleexpr_ptr> single_expr
%type <returnstmt_ptr> return_stmt
%type <objmember_ptr> obj_member


%start beg

%%

beg: func { prog->Append(std::shared_ptr<ASTNode>($1)); }
   | beg func { prog->Append(std::shared_ptr<ASTNode>($2)); }
   | global_decl_stmt { prog->Append(std::shared_ptr<ASTNode>($1)); }
   | beg global_decl_stmt { prog->Append(std::shared_ptr<ASTNode>($2)); }
   | class_decl { prog->Append(std::shared_ptr<ASTNode>($1)); }
   | beg class_decl { prog->Append(std::shared_ptr<ASTNode>($2)); }
   |
   ;

/* 语法规则 */
//函数定义
func: type_dec IDENTITY LPAREN args_list RPAREN LBRACKET block RBRACKET { $$ = new Func($1, $2, std::shared_ptr<ArgsList>($4), std::shared_ptr<Block>($7)); }
    ;

// 函数定义时所使用的形参
args_list: type_dec IDENTITY { $$ = new ArgsList; $$->Append(VariableDef($1, $2)); printf("arg name: %s\n", $2); }
         | args_list ',' type_dec IDENTITY { $1->Append(VariableDef($3, $4)); printf("arg name: %s\n", $4); }
	 | { $$ = new ArgsList; }
	 ;
// 类声明
class_decl: CLASS IDENTITY LBRACKET class_decl_stmt_list RBRACKET ';' { $$ = new Class($2, std::shared_ptr<ArgsList>($4)); printf("class %s\n", $2); }

// 注意block中sentence的顺序
// block
block: sentence ';' { $$ = new Block; $$->Append(std::shared_ptr<Sentence>($1)); }
    | block sentence ';' { $1->Append(std::shared_ptr<Sentence>($2)); }
    | { $$ = new Block; }
    ;

// 句子种类
sentence: decl_stmt     { $$ = $1; }
    | assign_stmt       { $$ = $1; }
    | if_stmt		{ $$ = $1; }
    | return_stmt { $$ = $1; }
    | break_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | switch_stmt { $$ = $1; }
    | expr { $$ = $1; }
    | /* empty rule */  { $$ = new Sentence; }
    ;

// 变量声明，允许初始化时赋值
decl_stmt: type_dec id_list {
    	$$ = new DeclStmt($2->GetIds());
    	$$->SetTypeForAllVariables($1);
    	printf("declare statement\n");
    }
    ;


// 全局变量声明
global_decl_stmt: decl_stmt ';' { $$ = $1; printf("global declare statement\n"); }
		;

// class声明与定义，包括成员变量和成员函数
class_decl_stmt_list: type_dec IDENTITY ';' {
			$$ = new ArgsList;
		    	$$->Append(VariableDef($1, $2));
		    }
		    | class_decl_stmt_list type_dec IDENTITY ';' {
		    	$1->Append(VariableDef($2, $3));
		    }
		    | func
		    | func class_decl_stmt_list
                    |
		    ;

// if语句
if_stmt: IF LPAREN expr RPAREN LBRACKET block RBRACKET {
		$$ = new IfStmt; $$->SetBoolExpr(std::shared_ptr<Expr>($3));
		$$->SetTrueBlock(std::shared_ptr<Block>($6));
		printf("if statement\n");
	}
       | IF LPAREN expr RPAREN LBRACKET block RBRACKET ELSE LBRACKET block RBRACKET {
        	$$ = new IfStmt;
        	$$->SetBoolExpr(std::shared_ptr<Expr>($3));
        	$$->SetTrueBlock(std::shared_ptr<Block>($6));
        	$$->SetFalseBlock(std::shared_ptr<Block>($10));
        	printf("if-else statement\n");
        }
       ;

// while语句
while_stmt: WHILE LPAREN expr RPAREN LBRACKET block RBRACKET { $$ = new WhileStmt(std::shared_ptr<Expr>($3), std::shared_ptr<Block>($6)); printf("while statement\n"); }
          ;

// switch语句
switch_stmt: SWITCH LPAREN expr RPAREN LBRACKET case_list RBRACKET { $$ = new SwitchStmt; printf("switch statement\n"); }
	   ;
// for语句
for_stmt: FOR LPAREN decl_stmt ';' expr ';' assign_stmt RPAREN LBRACKET block RBRACKET {
		$$ = new ForStmt(std::shared_ptr<DeclStmt>($3), std::shared_ptr<Expr>($5), std::shared_ptr<AssignStmt>($7), std::shared_ptr<Block>($10));
		printf("for statement\n");
	}

// call语句
call_stmt: IDENTITY LPAREN expr_list RPAREN { $$ = new CallStmt($1, $3->GetExprList()); printf("call %s\n", $1); }

// 调用时的形参列表
expr_list: expr { $$ = new ExprList; $$->Append(std::shared_ptr<Expr>($1)); }
         | expr_list ',' expr { $1->Append(std::shared_ptr<Expr>($3)); }
	 |
	 ;

// switch语句中的case list
case_list: CASE factor ':' block	 { printf("case list\n"); }
	 | CASE factor ':' block case_list    { printf("case list\n"); }
         |
         ;

// 变量声明时标识符list
id_list: IDENTITY           { $$ = new IdList; $$->Append(Variable("", $1)); printf("iden: %s\n", $1);  }
    | id_list ',' IDENTITY { $1->Append(Variable("", $3)); printf("iden: %s\n", $3);  }
    | assign_stmt { $$ = new IdList; $$->Append(Variable("", $1->GetName(), $1->GetVal())); }
    | id_list ',' assign_stmt { $1->Append(Variable("", $3->GetName(), $3->GetVal())); }
    ;

// 赋值语句
assign_stmt: IDENTITY ASSIGN expr    { $$ = new AssignStmt($1, std::shared_ptr<Expr>($3)); printf("id: %s\n assignment\n", $1); }
    | obj_member ASSIGN expr	{ $$ = new AssignStmt(std::shared_ptr<ObjMember>($1), std::shared_ptr<Expr>($3)); $1->SetIsVar(true); }
    ;

// return语句
return_stmt: RETURN expr { $$ = new ReturnStmt(std::shared_ptr<Expr>($2)); printf("return statement\n"); }
	   | RETURN	 { $$ = new ReturnStmt(NULL); }
           ;
// break语句
break_stmt: BREAK { $$= new BreakStmt; printf("break statement\n"); }
	  ;
// 对象的变量
obj_member: IDENTITY '.' IDENTITY { $$ = new ObjMember($1, $3); printf("obj: %s mem: %s\n", $1, $3); }
          ;
// 对象call
obj_call: IDENTITY '.' call_stmt { printf("obj: %s\n", $1); }
        ;

// 表达式
expr: LPAREN expr RPAREN { $$ = $2; }
    | factor    { $$ = $1; }
    | bin_expr  { $$ = $1; }
    | single_expr { $$ = $1; }
    | STRING { $$ = new StringConst($1); printf("string const: %s\n", $1); }
    ;

// 表达式中的factor，为常量或者标识符
factor: INT_NUMBER      { $$ = new IntConst($1); printf("int const: %d\n", $1); }
    | FLOAT_NUMBER      { $$ = new FloatConst($1); printf("float const: %d\n", $1); }
    | call_stmt   	{ $$ = $1; }
    | IDENTITY          { $$ = new Identity($1); printf("iden factor: %s\n", $1); }
    | obj_member	{ $$ = $1; }
    | obj_call
    ;

// 二元表达式
bin_expr: expr '+' expr     { $$ = new BinExpr(add_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("+\n"); }
    | expr '-' expr         { $$ = new BinExpr(sub_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("-\n"); }
    | expr '*' expr         { $$ = new BinExpr(mul_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("*\n"); }
    | expr '/' expr         { $$ = new BinExpr(div_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("/\n"); }
    | expr '%' expr	    { $$ = new BinExpr(mod_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("%\n"); }
    | expr EQUAL expr	    { $$ = new BinExpr(eq_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("==\n"); }
    | expr LESS expr	    { $$ = new BinExpr(less_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("<\n"); }
    | expr LESS_E expr	    { $$ = new BinExpr(lesseq_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("<=\n"); }
    | expr GREATER expr	    { $$ = new BinExpr(greater_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf(">\n"); }
    | expr GREATER_E expr   { $$ = new BinExpr(greatereq_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf(">=\n"); }
    | expr AND expr	    { $$ = new BinExpr(and_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("&&\n"); }
    | expr OR expr 	    { $$ = new BinExpr(or_op, std::shared_ptr<Expr>($1), std::shared_ptr<Expr>($3)); printf("||\n"); }
    ;

// 一元表达式
single_expr: '!' expr { $$ = new SingleExpr(not_op, std::shared_ptr<Expr>($2)); printf("not expr\n"); }
	  | '~' expr { $$ = new SingleExpr(neg_op, std::shared_ptr<Expr>($2)); printf("neg expr\n"); }
	  ;

// 符号类型
type_dec: INT       { printf("type: int\n"); $$ = "int"; }
    | DOUBLE	    { printf("type: double\n"); $$ = "double"; }
    | FLOAT         { printf("type: float\n");  $$ = "float"; }
    | SHORT         { printf("type: short\n"); $$ = "short"; }
    | LONG          { printf("type: long\n"); $$ = "long"; }
    | UNSIGNED LONG { printf("type: unsigned\n"); $$ = "unsigned long"; }
    | VOID	    { printf("type: void\n"); $$ = "void"; }
    | IDENTITY      { printf("type: class\n"); $$ = $1; }
    ;
%%

int main(int argc, const char *args[])
{
	/* 将注释去掉就能看到stack具体是怎么工作的.. */
    	//yydebug = 1;

	extern FILE *yyin;
	if(argc > 1 && (yyin = fopen(args[1], "r")) == NULL) {
		fprintf(stderr, "can not open %s\n", args[1]);
		exit(1);
	}

	printf("input file: %s", args[1]);

	prog = std::make_shared<Program>(args[1]);

	if(yyparse()) {
		exit(-1);
	}

	printf("\n\n");
	prog->Cgen();
    return 0;
}

void yyerror(char *s, ...)
{
    extern int yylineno;

    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}