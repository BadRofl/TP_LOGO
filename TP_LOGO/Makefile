CC = gcc
CFLAGS = -Wall

	
all : flex SVG.c LOGO.c CRAYON.c logo.o svg.o crayon.o
	$(CC) lex.yy.c ParseurLOGO.tab.c logo.o svg.o crayon.o -o LOGO -lm
	
test : svg.o logo.o crayon.o test.o
	$(CC) test.o logo.o svg.o crayon.o -o TESTS -lm

svg.o: SVG.c
	$(CC) -c SVG.c -o svg.o
	
logo.o: LOGO.c
	$(CC) -c LOGO.c -o logo.o

crayon.o: CRAYON.c
	$(CC) -c CRAYON.c -o crayon.o
	
test.o : TESTS.c
	$(CC) -c TESTS.c -o test.o
	
flex : bison
	flex LexiqueLOGO.l 

bison : 
	bison -d ParseurLOGO.y

clean: 
	\rm -rf *.o LOGO TESTS lex.yy.c ParseurLOGO.tab.*
