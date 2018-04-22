%{
    #include <stdlib.h>
    #include "y.tab.h"
    void yyerror(char *);
    extern int yylval;
%}

%%
[a-z] {
    yylval = *yytext - 'a'; return VARIABLE;
}
[0-9]+ {
    yylval = atoi(yytext); return INTEGER;
}

[-+()=/*\n] { return *yytext; }

[ \t] ;

.   yyerror("invalid character");
%%
int yywrap() { return 1; }


