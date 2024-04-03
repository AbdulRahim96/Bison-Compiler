%{  
#include <stdlib.h>
#include <stdio.h>

int datatype = 0;
int vars = 0;
int digits = 0;
int terminator = 0;
int assignment_op = 0;
int comparison_op = 0;
int spaces = 0;
int string_kw = 0;
int wr_kw = 0;
int if_kw = 0;
int then_kw = 0;
int end_kw = 0;
int round_br = 0;
int arithmetic_op = 0;
int invalid = 0;
int lib = 0;
int func_kw = 0;

String TOKEN = "DATATYPE,Vars,arithmetic_op, Digit, terminator,";
%}

%%
(#_HR|#_HIO)   {lib++;}
\   {spaces++;}
\+|\-|\*|\/|\%|\^  {arithmetic_op++;}
=   {assignment_op++;}
==|>=|<= {comparison_op++;}
Num  {
    TOKEN += "DATATYPE,"

;}

Write   {TOKEN += "wr_kw,"}
If    {if_kw++;}
Then  {then_kw++;}
End   {end_kw++;}
\(|\)   {round_br++;}
:   {terminator++;}
[0-9]+  {digits++;}
_[a-z]+  {vars++;}
\".*\"   {string_kw++;}
. {invalid++;}
For {for_kw++;}
Or {or_kw++;}

%%
int yywrap() {return 1;}

int main ()
{

    //File Formate:
    char format[] = "Lexemes\t\tTokens\n\nIf\t\tif_kw\nThen\t\tthen_kw\nEnd\t\tend_kw\nNum\t\tdatatype\n_xvalue\t\tvars\n5\t\tdigits\n:\t\tterminator\n=\t\tassignment_op\n==\t\tcomparison_op\n+\t\tarithmetic_op\n\"same\"\t\tstring_kw\nWrite\t\twr_kw\n(\t\tround_br\n";
    printf("Lexemes\t\tTokens\n\nIf\t\tif_kw\nThen\t\tthen_kw\nEnd\t\tend_kw\nNum\t\tdatatype\n_xvalue\t\tvars\n5\t\tdigits\n:\t\tterminator\n=\t\tassignment_op\n==\t\tcomparison_op\n+\t\tarithmetic_op\n\"same\"\t\tstring_kw\nWrite\t\twr_kw\n(\t\tround_br\n");

    printf("\nfunction: ", func_kw);
    
    FILE *file;
    char filename[100] = "input.byte";
    char ch;

    file = fopen(filename, "r");
    
    yyin = file;
    yylex();

    // Closing the file
    fclose(file);

    int total = datatype + vars + assignment_op + terminator + digits + string_kw + if_kw + then_kw + end_kw + round_br + comparison_op + arithmetic_op + wr_kw;

    printf("TOKENS GENERATED: %d\n Datatype %d\n Spaces %d\n Variables: %d\n Assignment operator: %d\n Terminator: %d\n Digits: %d\n String: %d\n If: %d\n Then: %d\n End: %d\n Brackets: %d\n Comparison: %d\n for loop: %d\n Arithmetic Operator: %d\n Write: %d\n Lexical Error: %d", total, datatype, spaces, vars, assignment_op, terminator, digits, string_kw, if_kw, then_kw, end_kw, round_br, comparison_op, for_kw, arithmetic_op, wr_kw, invalid);

    //Writing File
    FILE *writeFile;
    char fileString[500];

    writeFile = fopen("Token.txt", "w");

    sprintf(fileString, "TOKENS GENERATED: %d\n Datatype %d\n Spaces %d\n Variables: %d\n Assignment operator: %d\n Terminator: %d\n Digits: %d\n String: %d\n If: %d\n Then: %d\n End: %d\n Brackets: %d\n Comparison: %d\n for loop: %d\n Arithmetic Operator: %d\n Write: %d\n Lexical Error: %d", total, datatype, spaces, vars, assignment_op, terminator, digits, string_kw, if_kw, then_kw, end_kw, round_br, comparison_op, for_kw, arithmetic_op, wr_kw, invalid);

    // Write the string to the file
        fprintf(writeFile, "%s\n--------------------\nSUMMERY\n--------------------\n%s", format, fileString);

        // Close the file
        fclose(writeFile);
        printf("\n\nFile 'Token.txt' created");

return 0;

}