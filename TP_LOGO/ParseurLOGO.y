%{
#include <stdio.h>
#include "LOGO.h"


void yyerror(const char *str){
	fprintf(stderr, "Erreur %s\n", str);
}

int yywrap(){
	return 1;
}
	
%}

%token TOK_FWD
%token TOK_RPT
%token TOK_LFT
%token TOK_RGT
%token TOK_NBR
%token TOK_RBD

%union{
	NODE node;
	TYPE type;
	int value;
}

%type <type> TOK_FWD TOK_RPT TOK_LFT TOK_RGT TOK_RBD
%type <node> FILE PROG INST
%type <value> TOK_NBR
%start FILE
%%

FILE : PROG{
	 root=$1; YYACCEPT; //Force la sortie
}
PROG : INST
	{$$=$1;	}
	|INST PROG
	{$$=addNode($2,$1);}

INST : TOK_FWD TOK_NBR
	{$$=newNode(NULL,NULL,$2,FORWARD);}
	|TOK_LFT TOK_NBR
	{$$=newNode(NULL,NULL,$2,LEFT);}
	|TOK_RGT TOK_NBR
	{$$=newNode(NULL,NULL,$2,RIGHT);}
	|TOK_RPT TOK_NBR '[' PROG ']'
	{$$=newNode(NULL,$4,$2,REPEAT);}
	|TOK_RBD
	{$$ = newNode(NULL,NULL,0,RAINBOW);}
%%

int main(){
yyparse();
creerSVG(root);
return 0;
}
