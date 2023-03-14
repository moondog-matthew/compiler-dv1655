%top{
#include "parser.tab.h"
#define YY_DECL yy::parser::symbol_type yylex()
#include "lib/Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"class"                     { return yy::parser::make_CLASS(yytext);  
                            //   printf("CLASS\n");
                            }
"static"                    { return yy::parser::make_STATIC(yytext); 
                            //   printf("STATIC\n");
                            }
"void"                      { return yy::parser::make_VOID(yytext);   
                            //   printf("VOID\n");
                            }
"main"                      { return yy::parser::make_MAIN(yytext);   
                            //   printf("MAIN\n");
                            }
"public"                    { return yy::parser::make_PUBLIC(yytext); 
                            //   printf("PUBLIC\n");
                            }
"return"                    { return yy::parser::make_RETURN(yytext); 
                            //   printf("RETURN\n");
                            }

"+"                         { return yy::parser::make_PLUSOP(yytext);  
                            //   printf("PLUSOP\n");
                            }
"-"                         { return yy::parser::make_MINUSOP(yytext); 
                            //   printf("MINUSUP\n");
                            }
"*"                         { return yy::parser::make_MULTOP(yytext);  
                            //   printf("MULOP\n");
                            }
"/"                         { return yy::parser::make_DIVOP(yytext);   
                            //   printf("DIVOP\n");
                            }
"("                         { return yy::parser::make_LP(yytext);      
                            //   printf("LP\n");
                            } 
")"                         { return yy::parser::make_RP(yytext);      
                            //   printf("RP\n");
                            } 
0|[1-9][0-9]*               { return yy::parser::make_INT(yytext);     
                            //   printf("INT\n");
                            }
"["                         { return yy::parser::make_LHB(yytext);     
                            //   printf("LHB\n");
                            }
"]"                         { return yy::parser::make_RHB(yytext);     
                            //   printf("RHB\n");
                            }
"{"                         { return yy::parser::make_LCB(yytext);     
                            //   printf("LCB\n");
                            }
"}"                         { return yy::parser::make_RCB(yytext);     
                            //   printf("RCB\n");
                            }
"="                         { return yy::parser::make_ASSIGN(yytext);  
                            //   printf("ASSIGN\n");
                            }
"=="                        { return yy::parser::make_EQ(yytext);      
                            //   printf("EQ\n");
                            }
"&&"                        { return yy::parser::make_AND(yytext);     
                            //   printf("AND\n");
                            }
"||"                        { return yy::parser::make_OR(yytext);      
                            //   printf("OR\n");
                            }
">"                         { return yy::parser::make_GT(yytext);      
                            //   printf("GREATER THAN\n");
                            }
"<"                         { return yy::parser::make_LT(yytext);      
                            //   printf("LESSER THAN\n");
                            }

"."                         { return yy::parser::make_PERIOD(yytext);      
                            //   printf("PERIOD IS VERY AMERICAN BUT OK\n");
                            }
","                         { return yy::parser::make_COMMA(yytext);       
                            //   printf("COMMA\n");
                            }
"!"                         { return yy::parser::make_EXCLAMATION(yytext); 
                            //   printf("NEGATION\n");
                            }
";"                         { return yy::parser::make_SEMICOLON(yytext);   
                            //   printf("SEMICOLON\n");
                            }

[ \t\n\r]+                  { } // Whitespaces

"int"                       { return yy::parser::make_INTTYPE(yytext);  
                            //   printf("INT\n");
                            }
"boolean"                   { return yy::parser::make_BOOLTYPE(yytext); 
                            //   printf("BOOL\n");
                            }
"String"                    { return yy::parser::make_STRING(yytext);   
                            //   printf("STR\n");
                            }

"if"                        { return yy::parser::make_IF(yytext);    
                            //   printf("IF\n");
                            } 
"else"                      { return yy::parser::make_ELSE(yytext);  
                            //   printf("ELSE\n");
                            }
"while"                     { return yy::parser::make_WHILE(yytext); 
                            //   printf("WHILE\n");
                            }

"new"                       { return yy::parser::make_NEW(yytext);    
                            //   printf(NEW"\n");
                            }
"true"                      { return yy::parser::make_TRUE(yytext);   
                            //   printf("TRUE\n");
                            }
"false"                     { return yy::parser::make_FALSE(yytext);  
                            //   printf("FALSE\n");
                            }
"this"                      { return yy::parser::make_THIS(yytext);   
                            //   printf("THIS\n");
                            }
"length"                    { return yy::parser::make_LENGTH(yytext); 
                            //   printf("LEN\n");
                            }
"System.out.println"        { return yy::parser::make_PRINT(yytext);  
                            //   printf("PRINT\n");
                            }

[a-zA-Z]+[a-zA-Z0-9\-_]*    { return yy::parser::make_IDENTIFIER(yytext);}

"//".*                      { } // ignore inline comments

.                           { 
                                if(!lexical_errors) 
                                    fprintf(stderr, "Lexical errors found! See the logs below: \n"); 
                                printf("Character %s is not recognized\n", yytext); 
                                lexical_errors = 1;
                            }

<<EOF>>                     return yy::parser::make_END();
%%