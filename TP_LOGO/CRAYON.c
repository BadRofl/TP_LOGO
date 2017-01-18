#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "CRAYON.h"

#define PI 3.14159

CRAYON initCrayon(double posH, double posV, double angle){
	 CRAYON cray = (CRAYON)malloc(sizeof(*cray));
	 
	 cray -> posH = posH;
	 cray -> posV = posV;
	 cray -> angle = angle;
	 
	 return cray;
	 
}

void fermerCrayon(CRAYON cray){
	if(cray != NULL){
		//printf("Crayon libéré\n");
		free(cray);
	}
}

double crayonPosH(CRAYON cray, int valeur){
	double posH = getposH(cray) + valeur * cos(getangle(cray));
	cray->posH = posH;
	
	return posH;
}

double crayonPosV(CRAYON cray, int valeur){
	double posV = getposV(cray) + valeur * sin(getangle(cray));
	cray->posV = posV;
	
	return posV;

}

double crayonAngleL(CRAYON cray, int valeur){
	double angle = getangle(cray) - ((PI*valeur)/180.0);
	cray->angle = angle;
	
	return angle;
}

double crayonAngleR(CRAYON cray, int valeur){
	double angle = getangle(cray) + ((PI*valeur)/180.0);
	cray->angle = angle;
	
	return angle;
}
	

double getposH(CRAYON cray){
	if(cray != NULL){
		return cray->posH;
	}
}

double getposV(CRAYON cray){
	if(cray != NULL){
		return cray->posV;
	}
}

double getangle(CRAYON cray){
	if(cray != NULL){
		return cray->angle;
	}
}


	 
	
