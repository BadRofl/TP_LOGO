#include <stdlib.h>
#include <stdio.h>
#include "LOGO.h"
#include "SVG.h"


int main(){
	printf("Programme de tests :\n");

	
	printf("Tests Nodes :\n");
	NODE prog4 = newNode(NULL, NULL, 20, FORWARD);
	NODE sssprog2 = newNode(NULL, NULL, 45, LEFT);
	NODE sssprog1 = newNode(sssprog2, NULL, 10, FORWARD);
	NODE ssprog1 = newNode(NULL, sssprog1, 10, REPEAT);
	NODE prog3 = newNode(prog4, ssprog1, 10, REPEAT);
	NODE prog2 = newNode(prog3, NULL, 30, LEFT);
	NODE prog1 = newNode(prog2, NULL, 90, RIGHT);
	NODE root = newNode(prog1, NULL, 10, FORWARD);
	
	printf("Tests Affichage :\n");
	affichage(root,0);
	
	printf("Tests Ecriture SVG :\n");
	creerSVG(root);
	
	return 0;
}
