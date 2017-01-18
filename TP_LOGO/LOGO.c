#include <stdlib.h>
#include <stdio.h>
#include "LOGO.h"
#include "SVG.h"


#define TAILLE 400

void creerSVG(NODE root){
	FILE *sortieSVG = fopen("logo.svg", "w");	
	double centreH = TAILLE/2;
	double centreV = TAILLE/2;
	CRAYON cray;
	
	cray = initCrayon(centreH,centreV,0);
	initSVG(sortieSVG, TAILLE);
	
	printf("Programme entré : \n\n");
	affichage(root, 0);
	printf("__________\n\n");
	
	ecrireSVG(root, sortieSVG, cray, 0);
	
	fermerSVG(sortieSVG);
	fermerCrayon(cray);
	fermerNode(root);
}

NODE newNode(NODE suivant, NODE subProg, int value, TYPE type){
	//printf("Nouvelle node\n");
	NODE ret = (NODE)malloc(sizeof(*ret));
	ret->type = type;
	ret->value = value;
	ret->suivant = suivant;
	ret->subProg = subProg;
	
	return ret;
}

NODE addNode(NODE instr,NODE program){
	//printf("Ajout node\n");
	if(program == NULL){
		program = instr;
	}
	if(suivant(program) != NULL){
		addNode(instr, suivant(program));
	}else{
		program->suivant = instr;
	}
	return program;
}

void fermerNode(NODE programme){
	if(suivant(programme) != NULL){
		fermerNode(programme->suivant);
	}
	if(ssProg(programme) != NULL){
		fermerNode(programme->subProg);
	}
	free(programme);
	//printf("Node libérée\n");
}
	
NODE suivant(NODE noeu){
	if(noeu != NULL){
		return noeu->suivant;
	}
}

NODE ssProg(NODE noeu){
	if(noeu != NULL){
		return noeu->subProg;
	}
}

int value(NODE noeu){
	if(noeu != NULL){
		return noeu->value;
	}
}

TYPE type(NODE noeu){
	if(noeu != NULL){
		return noeu->type;
	}
}

void affichage(NODE noeu, int tab){
	
	int i =0;
	if(noeu != NULL){
			for(i=0;i<tab;i++){
			printf("\t");
			}
			if(type(noeu) == 1){
				printf("REPEAT %d [\n ",value(noeu));
				NODE stock= NULL;
				stock = ssProg(noeu);
				affichage(stock,tab+1);
				for(i=0;i<tab+1;i++){
				printf("\t");
				}
				printf(" ]\n");
			}else if(type(noeu) == 4){
				printf("SPIRAL %d [\n ",value(noeu));
				NODE stock= NULL;
				stock = ssProg(noeu);
				affichage(stock,tab+1);
				for(i=0;i<tab+1;i++){
				printf("\t");
				}
				printf(" ]\n");
				
			}else{
				if(type(noeu) == 0){
					printf("FORWARD ");
				}else if(type(noeu) == 2){
					printf("LEFT ");
				}else if(type(noeu) == 3){
					printf("RIGHT ");
				}
				printf("%d\n",value(noeu));
			}
		affichage(suivant(noeu), tab);
	}
}



