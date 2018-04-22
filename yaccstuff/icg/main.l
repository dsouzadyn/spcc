%{
    #include "y.tab.h"
    extern int yylval;
    void yyerror(char *s);
%}
%%
[a-z]       { yylval = *yytext - 'a'; return VAR; }
[0-9]+      { yylval = atoi(yytext); return INT;}
[-+()=/*;\n] { return *yytext; }
[ \t]   ;
.           {yyerror("Syntax error");}
%%
int yywrap() { return 1; }
