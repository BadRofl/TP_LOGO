%{
#include <stdio.h>
#include "LOGO.h"
#include "ParseurLOGO.tab.h"
%}

%%
(F|f)(O|o)(R|r)(W|w)(A|a)(R|r)(D|d)|FWD  return TOK_FWD; 
(R|r)(E|e)(P|p)(E|e)(A|a)(T|t)|RPT       return TOK_RPT;
(L|l)(E|e)(F|f)(T|t)|LFT 				 return TOK_LFT;
(R|r)(I|i)(G|g)(H|h)(T|t)|RGT   		 return TOK_RGT;
(S|s)(P|p)(I|i)(R|r)(A|a)(L|l)|SPI		 return TOK_SPIRAL;
(C|c)(E|e)(N|n)(T|t)(E|e)(R|r)|CEN		 return TOK_CENTER;
(C|c)(O|o)(L|l)(O|o)(R|r)|COL			 return TOK_COLOR;

"[" 							{return '[';}      
"]"	   							{return ']';} 
[0-9]+ {yylval.value=atoi(yytext); return TOK_NBR;}

"//".*    //Permet d'ajouter des commentaires
[ \t\n]+ //Ignore les espaces tabulations et retours à la ligne
%%
