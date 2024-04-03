%{
#include <stdio.h>

int char_token = 0;
int if_token = 0;
int else_token = 0;
int print_token = 0;
int statement_token = 0;
int semicolon_token = 0;
int assign_token = 0;
int equals_token = 0;
int cbo_token = 0;
int cbc_token = 0;
int id_token = 0;
int invalid = 0;

%}

%%

char             {printf("token: charKW %s\n", yytext); char_token++;}
if               {printf("token: ifKW %s\n", yytext); if_token++;}
else             {printf("token: elseKW %s\n", yytext); else_token++;}
print:           {printf("token: printKW %s\n", yytext); print_token++;}
;                {printf("token: ; %s\n", yytext); semicolon_token++;}
%=               {printf("token: %= %s\n", yytext); assign_token++;}
==               {printf("token: == %s\n", yytext); equals_token++;}
\{                {printf("token: { %s\n", yytext); cbo_token++;}
\}                {printf("token: } %s\n", yytext); cbc_token++;}
_[a-zA-z0-9]+_    {printf("token: identifier %s\n", yytext); id_token++;}
'[a-zA-z0-9]+'    {printf("token: statement %s\n", yytext); statement_token++;}
[ \t\n]          ;
.                {printf("INVALID CHARACTER\n"); invalid++;}


%%

int yywrap() {
    return 1;
}


int main (){
    yylex();

    printf("char %d\n", char_token);
    printf("if %d\n", if_token);
    printf("else %d\n", else_token);
    printf("print %d\n", print_token);
    printf("semicolon %d\n", semicolon_token);
    printf("assign %d\n", assign_token);
    printf("equals %d\n", equals_token);
    printf("cbo %d\n", cbo_token);
    printf("cbc %d\n", cbc_token);
    printf("id %d\n", id_token);
    printf("statement %d\n", statement_token);
    
    return 0;
}