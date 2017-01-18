#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LOGO.h"
#include "SVG.h"



void initSVG(FILE *svg, int taille){
	fprintf(svg,"<?xml version=\"1.0\" encoding=\"utf-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\; viewBox=\"-289 -510 589 1145\"><title>Dessin généré par un parseur LOGO</title>" , taille, taille);
}

void ecrireSVG(NODE root, FILE *svg, CRAYON cray){

	if(root!= NULL){
		if(type(root) != 4){
			if(type(root) == 0){
				double posH;
				double posV;
				double finH;
				double finV;
				
				int R = 50;
				int G = 50;
				int B = 200;
				
				posH = getposH(cray);
				posV = getposV(cray);
				
				finH = crayonPosH(cray,value(root));
				finV = crayonPosV(cray,value(root));
				
				fprintf(svg, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style =\"stroke:rgb(%d,%d,%d); fill:none; stroke-width: 1px\" />", posH, posV, finH, finV, R, G, B);
			
			}
			else if(type(root) == 2){
				//printf("LEFT\n");
				crayonAngleL(cray, value(root));
			}
			else if(type(root) == 3){
				//printf("RIGHT\n");
				crayonAngleR(cray, value(root));
				
			}
			else if(type(root) == 1){
				//printf("REPEAT\n");
				int i;
				for(i = 0; i<value(root); i++){
		
					ecrireSVG(ssProg(root), svg, cray);					
				}		
			}
			ecrireSVG(suivant(root), svg, cray);
		}
		mysteriousDrawing(svg);
	}
}


void fermerSVG(FILE *svg){
	
	fputs("</svg>\n", svg);
	fclose(svg);
	printf("Logo crée!\n");
	
}

void mysteriousDrawing(FILE *svg){
	fprintf(svg, "<defs id=\"\"/><path id=\"path16\" d=\"m 70.999992,-137 -3.000001,22 -38.999999,28.999997 -40.999995,41 -31,39.0000002 -14,17.9999998 37.999995,-18.9999998 41.999999,-21.0000002 20.000001,-10 Q 3.9999936,19.999992 -18.000004,91 q -21.999998,72 -31.000001,148 -9.000002,75 -9.999994,146 l 3,126.99999 L -48,601 l 3,34 q -57,-119 -80,-211 -23.00001,-90 -26.00001,-154 -3,-62.00001 3,-94 l 6,-31 L -187,174.99999 -234,216 l -38,34 -14,13.00001 Q -294,149 -278,48.999998 -261,-51.000003 -232,-131.99999 -203,-213 -172,-272 q 29.99999,-58 51.99999,-89 l 22,-32 Q -31,-372 5.9999902,-338 42.999992,-304 56.999992,-264.99999 71.999996,-227 73,-192 l -2.000008,55\" style=\"fill:#1998d5\"/><path id=\"path18\" d=\"M -98.00001,-393 Q -31,-372 4.9999978,-338 42,-304 56.999992,-266 q -31,20.00001 -58.9999999,60 L -55.000006,-120 -96.000001,-28.000003 -124,44 -134.00001,75.000003 -33.000008,22.999993 Q -63.000004,94.000001 -72.999999,177 -84.00001,259 -81.000009,340 L -69.000006,488 -52.000005,594.99999 -45,635 q -57,-119 -80,-211 -23.00001,-90 -26.00001,-154 -3,-62.00001 3,-94 l 6,-31 L -187,174.99999 -234,216 l -38,34 -14,13.00001 Q -294,149 -278,48.999998 -261,-51.000003 -232,-131.99999 -203,-213 -172,-272 q 29.99999,-58 51.99999,-89 l 22,-32\" style=\"fill:#ffe96b\"/><path id=\"path20\" d=\"M -19.000008,-357 Q -68.000002,-303 -104,-236 q -35,66 -59,134.00001 L -200,25.000002 -220,118 l -5,39 31,-19 44,-29.00001 38.99999,-24.999996 17.000005,-11 Q -117.00001,141 -118,218 q -2.00001,77 8.99999,150.00001 l 25,133.99999 27.000007,97 L -45,635 q -57,-119 -80,-211 -23.00001,-90 -26.00001,-154 -3,-62.00001 3,-94 l 6,-31 L -187,174.99999 -234,216 l -38,34 -14,13.00001 Q -294,149 -278,48.999998 -261,-51.000003 -232,-131.99999 -203,-213 -172,-272 q 29.99999,-58 51.99999,-89 l 22,-32 q 47.000009,15 79.000002,36\" style=\"fill:#ee4043\"/><path id=\"path4144\" d=\"m 142.06291,-267.51691 c 31.3967,22.21053 22.26481,85.05305 -30.81995,78.50759 C 21.016452,-200.13445 10.173669,-301.37426 77.852628,-361.34824 7.079624,-388.50862 46.369291,-492.45406 144.95737,-486.78196 c 115.19526,6.62756 160.75488,123.28703 74.9884,200.1067 110.57744,58.10739 117.96678,243.450681 -49.9783,288.6247339 C 81.172666,25.833598 31.241559,-80.897237 44.018369,-152.93493 -64.64915,-49.092717 -156.45643,-156.98789 -41.190886,-275.43015 -249.91399,-374.14896 -53.289598,-596.4157 81.63239,-472.63777 l -8.189152,5.78294 C -41.11726,-570.66608 -242.7635,-364.96675 -21.152254,-278.2365 -158.09475,-159.84749 -48.688004,-36.451986 66.461495,-196.9545 18.449581,-63.476614 103.24011,0.66549769 166.0187,-10.148889 301.18372,-33.432732 346.25744,-210.60453 207.23249,-283.832 c 89.2272,-84.37164 19.45491,-186.59637 -64.49244,-190.30611 -90.028656,-3.97847 -121.849684,91.6903 -48.301055,109.61311 -149.900498,141.94901 99.959835,238.19118 47.623915,97.00809 z\" style=\"color:#000000;clip-rule:nonzero;display:inline;overflow:visible;visibility:visible;opacity:1;isolation:auto;mix-blend-mode:normal;color-interpolation:sRGB;color-interpolation-filters:linearRGB;solid-color:#000000;solid-opacity:1;fill:#1998d5;fill-opacity:1;fill-rule:nonzero;stroke:none;stroke-width:0.70679998;stroke-linecap:round;stroke-linejoin:round;stroke-miterlimit:4;stroke-dasharray:none;stroke-dashoffset:0;stroke-opacity:1;marker:none;marker-start:none;marker-mid:none;color-rendering:auto;image-rendering:auto;shape-rendering:auto;text-rendering:auto;enable-background:accumulate\"/><path id=\"rect4199\" d=\"m 73.2258,-467.01792 c -114.561973,-103.79324 -315.98379,102.05334 -94.37805,188.78142 -136.9425,118.38902 -27.535762,241.78452 87.61375,81.28201 C 18.449589,-63.47661 103.24,0.66494211 166.0186,-10.149452 301.18362,-33.433296 346.25744,-210.60452 207.2325,-283.832 c 89.22719,-84.37164 19.45415,-186.5971 -64.4932,-190.30684 -90.028653,-3.97847 -121.84893,91.69102 -48.3003,109.61383 -149.9005,141.94901 99.95979,238.19094 47.62387,97.00785 31.3967,22.21052 22.26579,85.05273 -30.81897,78.50726 C 21.017382,-200.13502 10.173703,-301.37366 77.852666,-361.34762 28.47199,-380.29833 32.686014,-436.6214 73.2258,-467.01792 Z\" style=\"opacity:1;fill:#ffffff;fill-opacity:1;fill-rule:evenodd;stroke:none;stroke-width:0.5;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:10;stroke-dasharray:none;stroke-dashoffset:5;stroke-opacity:1\"/><metadata id=\"metadata4207\"><rdf:RDF><cc:Work rdf:about=\"\"><dc:title/></cc:Work></rdf:RDF></metadata>");
	}
