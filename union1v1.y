%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



int INT_TYPE = 1;
int FLOAT_TYPE = 2;

%}

%code requires {
   struct number
	{

	  int ival;
	  float fval;
	  int type;
	} n;
}


%union
{
   struct number num;
}
%start command
%token <num>FLOAT 
%token <num>INTEGER
%type <num> command exp 
%%

command : exp           
	| command exp
    ;

exp : INTEGER       {$$ = $1; printf("%d and of type:%d \n", $$.ival, $$.type);}
	| FLOAT         {$$ = $1; printf("%f and of type:%d \n", $$.fval, $$.type);}
    ;


%%

int main()
{ 
  return yyparse();
}


int yyerror(char *s)
{
   fprintf(stderr,"%s\n",s);
   return 0;
}