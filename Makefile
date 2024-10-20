
all: parser

parser: parser.o lex.yy.o
	gcc -o parser parser.o lex.yy.o -lfl

parser.o: parser.c
	gcc -c parser.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: calc_basic_lexical.l
	flex calc_basic_lexical.l

clean:
	rm -f *.o parser lex.yy.c
