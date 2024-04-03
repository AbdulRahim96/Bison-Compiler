%{
#include<stdlib.h>
#include<stdio.h>

int charCount=0;
int wordCount=0;
int lineCount=0;
int lib=0;
int Num=0;
int vars=0;
int if_kw =0;
int then_kw = 0;
int or_kw = 0;
int end_kw = 0;
int for_kw = 0;
int wr_kw = 0 ;
int round_br = 0;
int arithmetic_op = 0;
int comparison_op = 0;
int logical_op = 0;
int ingore_space = 0;
int func_kw = 0;
%}


%%
[a-z]+\(\)   {func_kw++;}
(#_HR|#_HIO)   {lib++;}
[0-9]+       {Num++;}
_[a-z]+       {vars++;}
If    {if_kw++;}
Then  {then_kw++;}
Or    {or_kw++;}
End   {end_kw++;}
For   {for_kw++;}
Write {wr_kw++;}
[()]$  {round_br++;}
\   {ingore_space++;}
[\+|\-|\*|/|%|\^]  {arithmetic_op++;}
==|>=|<=          {comparison_op++;}
!!|&&              {logical_op++;} 
. {return 0;}


%%

int yywrap() {return 1;}
int main (){
yylex();
printf("function %d and Num %d and vars %d and if_kw %d and then_kw %d and or_kw %d and end_kw %d and for_kw %d and wr_kw %d and round_br %d and arithmetic_op: %d and comparison_op: %d and logical_op: %d and spaces: %d" ,func_kw, Num, vars, if_kw, then_kw, or_kw, end_kw, for_kw, wr_kw, round_br, arithmetic_op, comparison_op, logical_op, ingore_space);
return 0;
}



