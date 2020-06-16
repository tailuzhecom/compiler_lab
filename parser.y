 /* filename -> parser.y */
%require "3.0.4"

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "cgen.h"

Program *prog = NULL;

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
    Statement *stmt_ptr;
    Sentence *sentence_ptr;
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

%type <intval>  id_list
%type <node>  bin_expr factor beg call_stmt
%type <node> func class_decl global_decl_stmt
%type <node> case_list obj_member obj_call  single_expr
%type <stmt_ptr> statement
%type <sentence_ptr> sentence decl_stmt assign_stmt if_stmt return_stmt break_stmt while_stmt for_stmt switch_stmt expr


%start beg

%%

beg: func { prog->Append($1); }
   | func beg { prog->Append($1); }
   | global_decl_stmt { prog->Append($1); }
   | global_decl_stmt beg { prog->Append($1); }
   | class_decl { prog->Append($1); }
   | class_decl beg { prog->Append($1); }
   |
   ;

/* 语法规则 */
//函数定义
func: type_dec IDENTITY LPAREN args_list RPAREN LBRACKET statement RBRACKET { $$ = new Function($2); }
    ;

// 函数定义时所使用的形参
args_list: type_dec IDENTITY { printf("arg name: %s\n", $2); }
         | type_dec IDENTITY ',' args_list { printf("arg name: %s\n", $2); }
	 |
	 ;
// 类声明
class_decl: CLASS IDENTITY LBRACKET class_decl_stmt_list RBRACKET ';' { $$ = new Class; printf("class %s\n", $2); }

// 注意statement中sentence的顺序
// block
statement: sentence ';' { $$ = new Statement; $$->Append($1); }
    | statement sentence ';' { $1->Append($2); }
    | { $$ = new Statement; }
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
decl_stmt: type_dec id_list { $$ = new DeclStmt; printf("declare statement\n"); }
    | type_dec assign_stmt  { printf("declare statement & assignment\n"); }
    ;


// 全局变量声明
global_decl_stmt: decl_stmt ';' { $$ = $1; printf("global declare statement\n"); }
		;

// class声明与定义，包括成员变量和成员函数
class_decl_stmt_list: global_decl_stmt
		    | global_decl_stmt class_decl_stmt_list	
		    | func
		    | func class_decl_stmt_list
                    | 
		    ;

// if语句
if_stmt: IF LPAREN expr RPAREN LBRACKET statement RBRACKET { $$ = new IfStmt; printf("if statement\n"); }
       | IF LPAREN expr RPAREN LBRACKET statement RBRACKET ELSE LBRACKET statement RBRACKET { $$ = new IfStmt; printf("if-else statement\n"); }
       ;

// while语句
while_stmt: WHILE LPAREN expr RPAREN LBRACKET statement RBRACKET { $$ = new WhileStmt; printf("while statement\n"); }
          ;

// switch语句
switch_stmt: SWITCH LPAREN expr RPAREN LBRACKET case_list RBRACKET { $$ = new SwitchStmt; printf("switch statement\n"); }
	   ;
// for语句
for_stmt: FOR LPAREN decl_stmt ';' expr ';' assign_stmt RPAREN LBRACKET statement RBRACKET { $$ = new ForStmt; printf("for statement\n"); }

// call语句
call_stmt: IDENTITY LPAREN expr_list RPAREN { $$ = new CallStmt; printf("call %s\n", $1); }

// 调用时的形参列表
expr_list: expr
         | expr ',' expr_list 
	 |
	 ;

// switch语句中的case list
case_list: CASE factor ':' statement	 { printf("case list\n"); }
	 | CASE factor ':' statement case_list    { printf("case list\n"); }
         |
         ;

// 标识符list
id_list: IDENTITY           { printf("iden: %s\n", $1);  }
    | IDENTITY ',' id_list { printf("iden: %s\n", $1);  }
    | assign_stmt 
    | assign_stmt ',' id_list
    ;

// 赋值语句
assign_stmt: IDENTITY ASSIGN expr    { $$ = new AssignStmt; printf("id: %s\n assignment\n", $1); }
    ;

// return语句
return_stmt: RETURN expr { $$ = new ReturnStmt; printf("return statement\n"); }

// break语句
break_stmt: BREAK { $$= new BreakStmt; printf("break statement\n"); }

// 对象的变量
obj_member: IDENTITY '.' IDENTITY { printf("obj: %s mem: %s\n", $1, $3); }

// 对象call
obj_call: IDENTITY '.' call_stmt { printf("obj: %s\n", $1); }

// 表达式
expr: LPAREN expr RPAREN { $$ = new Expr; }
    | factor    { $$ = new Expr; }
    | bin_expr  { $$ = new Expr; }
    | single_expr { $$ = new Expr; }
    | STRING 	{ $$ = new Expr; printf("string const: %s\n", $1); }
    ;

// 表达式中的factor，为常量或者标识符
factor: INT_NUMBER      { printf("int const: %d\n", $1); }
    | FLOAT_NUMBER      { printf("float const: %d\n", $1); }
    | call_stmt   
    | IDENTITY          { printf("iden factor: %s\n", $1); }
    | obj_member
    | obj_call
    ;

// 二元表达式
bin_expr: expr '+' expr     { printf("+\n"); }
    | expr '-' expr         { printf("-\n"); }
    | expr '*' expr         { printf("*\n"); }
    | expr '/' expr         { printf("/\n"); }
    | expr '%' expr	    { printf("%\n"); }
    | expr EQUAL expr	    { printf("==\n"); }
    | expr LESS expr	    { printf("<\n"); }
    | expr LESS_E expr	    { printf("<=\n"); }
    | expr GREATER expr	    { printf(">\n"); }
    | expr GREATER_E expr   { printf(">=\n"); }
    | expr AND expr	    { printf("&&\n"); }
    | expr OR expr 	    { printf("||\n"); }
    ;

// 一元表达式
single_expr: '!' expr { printf("not expr\n"); }
	  | '~' expr { printf("neg expr\n"); }
	  ;

// 符号类型
type_dec: INT       { printf("type: int\n"); }
    | DOUBLE	    { printf("type: double\n"); }
    | FLOAT         { printf("type: float\n"); }
    | SHORT         { printf("type: short\n"); }
    | LONG          { printf("type: long\n"); }
    | UNSIGNED LONG { printf("type: unsigned\n"); }
    | VOID	    { printf("type: void\n"); }
    | IDENTITY      { printf("type: class\n"); }
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

	prog = new Program;

	if(yyparse()) {
		exit(-1);
	}

	printf("\n\n");
	prog->cgen();
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
