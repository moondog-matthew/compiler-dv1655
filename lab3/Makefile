compiler: lex.yy.c parser.tab.o main.cpp
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cpp lib/symbolTable.cpp lib/semanticCheck.cpp lib/BB.cpp lib/CFG.cpp lib/Tac.cpp lib/BC.cpp -std=c++14
parser.tab.o: parser.tab.c
		g++ -g -w -c parser.tab.c -std=c++14
parser.tab.c: lib/parser.y
		bison lib/parser.y -v # -Wcounterexamples
lex.yy.c: lib/lexer.l parser.tab.c
		flex lib/lexer.l

tree: 
		dot -Tpdf tree.dot -otree.pdf
st-tree: 
		dot -Tpdf st-tree.dot -ost-tree.pdf

cfg-tree:
		dot -Tpdf CFG-tree.dot -oCFG-tree.pdf

clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf st-tree.dot st-tree.pdf
		rm -f *.output *.out *.pdf *.dot
		# rm -R compiler.dSYM