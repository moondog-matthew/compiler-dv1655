%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"+"                     {return yy::parser::make_PLUSOP(yytext);}
"-"                     {return yy::parser::make_MINUSOP(yytext);}
"*"                     {return yy::parser::make_MULTOP(yytext);}
"("                     {return yy::parser::make_LP(yytext);}
")"                     {return yy::parser::make_RP(yytext);}

0|[1-9][0-9]*           {return yy::parser::make_INT(yytext);}

[ \t\n\r]+              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 return yy::parser::make_END();
%%