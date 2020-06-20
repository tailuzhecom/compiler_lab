LEX = flex
YYAC = bison
CC = g++

all: test

test: parser.tab.o scanner.o cgen.o
	$(CC) -o $@ parser.tab.o scanner.o cgen.o

cgen.o: cgen.cpp cgen.h

parser.tab.cpp parser.tab.h: parser.y
	$(YYAC) -d -o parser.tab.cpp parser.y

parser.tab.o: parser.tab.cpp parser.tab.h cgen.h

scanner.cpp: scanner.l
	$(LEX) -o $@ $<

scanner.o: scanner.cpp parser.tab.h

.PYHONY: clean

clean:
	-@ rm parser.tab.cpp parser.tab.hpp scanner.cpp  scanner.o parser.tab.o cgen.o test

ast: parser.tab.cpp parser.tab.h scanner.cpp

ll:
	cmake-build-debug/rush input

build: 
	llvm-as-6.0 < ./input.ll | lli-6.0
	


