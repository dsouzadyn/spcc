%{
    #include <stdio.h>
    #include <string.h>
    extern char* yytext;
    int yylex();
    int sym[26];
    char stack[256][10];
    int top = 0;
    char i[2] = "0";
%}
%token INT VAR
%left '+' '-'
%left '*' '/'
%%
program:
       program statement ';' '\n'
        |
        ;
statement: VAR{push();} '=' expr {sym[$1] = $3; code_assign();}
        ;
expr:
    | INT {push();}
    | VAR {push();}              { $$ = sym[$1]; }
    | expr '+'{push();} expr { code();}
    | expr '-'{push();} expr { code();}
    | expr '*'{push();} expr { code();}
    | expr '/'{push();} expr { code();}
    ;
%%
void push() {
    if(yytext != ";")
        strcpy(stack[++top], yytext);
}
void pushr(char *s) {
    if(yytext != ";") {
        strcpy(stack[++top], s);
        i[0]++;
    }
}
char* pop() {
    return stack[top--];
}

void code() {
    char* op1 = pop();
    char* op2 = pop();
    char* op3 = pop();
    char temp[] = "temp";
    strcat(temp, i);
    printf("%s = %s %s %s\n", temp, op3, op2, op1);
    pushr(temp);
}

void code_assign() {
    char* op1 = pop();
    char* op2 = pop();
    printf("%s = %s\n", op1, op2);
}

void yyerror(char *s) { fprintf(stderr, "%s\n", s);}
int main() { yyparse(); return 0; }
