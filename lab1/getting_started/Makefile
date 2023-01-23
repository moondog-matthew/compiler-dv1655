compiler: lex.yy.c parser.tab.o main.cpp
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cpp -std=c++14
parser.tab.o: parser.tab.c
		g++ -g -w -c parser.tab.c -std=c++14
parser.tab.c: parser.y
		bison parser.y
lex.yy.c: lexer.l parser.tab.c
		flex lexer.l
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.h tree.dot tree.pdf
		rm -R compiler.dSYM