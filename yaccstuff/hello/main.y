%{
#include <bits/stdc++.h>
%}

%token INT FLOAT STRING

%union {
    int ival;
    float fval;
    char *sval;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%%
grammar:
       INT grammar { cout << "yacc found an int:" << $1 << endl;}
        | FLOAT grammar { cout << "yacc found a float" << $1 << endl;}
        | STRING grammar { cout << "yacc found a string" << $1 << endl;}
        | INT {cout << "yacc found an int" << $1 << endl;}
        | FLOAT {cout << "yacc found a float" << $1 << endl;}
        | STRING {cout << "yacc found a string" << $1 << endl;}
        ;
%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;
using namespace std;
int main() {
    FILE *tyyin = fopen("inp.txt", "r");
    if(!tyyin) {
        cout << "could not open" << endl;
        return -1;
    }
    yyin = tyyin;
    do {
        yyparse();
    }while(!feof(yyin));
}

void yyerror(char *s) {
    cout << "Error!: " << s << endl;
    exit(-1);
}
