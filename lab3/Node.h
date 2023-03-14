
#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include "BB.hpp"
using namespace std;

class Node {
public:
	int id, lineno;
	string type, value;
	vector<Node*> children;
	Node(string t, string v, int l) : type(t), value(v), lineno(l){}
	Node()
	{
		type = "uninitialised";
		value = "uninitialised"; 
	}   // Bison needs this.
	virtual ~Node() = default;

	virtual void print_tree(int depth=0) {
		for(int i=0; i<depth; i++){
			cout << "  ";
		}
		cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
		for(auto i=children.begin(); i!=children.end(); i++) {
			(*i)->print_tree(depth+1);
		}
	}
  
	virtual void generate_tree() {
		std::ofstream outStream;
		char* filename = "tree.dot";
	  	outStream.open(filename);

		int count = 0;
		outStream << "digraph {" << std::endl;
		generate_tree_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();

		printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n", filename);
  	}

  	virtual void generate_tree_content(int &count, ofstream *outStream) {
	  id = count++;
	  *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

	  for (auto i = children.begin(); i != children.end(); i++)
	  {
		  (*i)->generate_tree_content(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << endl;
	  }
  	}
		
	virtual string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) {
		/*
			currentBlock : give a pointer to which block is currently being worked on
			methods : vector that contains all the methods in the program
			BBnames : map to later use to add all temporary variables in the ST
			id : used to give unique tempNmes
		*/
		
		for(auto const& child : children) {
			child->genIR(currentBlock, methods, BBnames, id, blockID);
		}
		return value;
	} 
	
};

/*
	Expressions
*/
class IntVal : public Node {
public:
	IntVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntVal() = default;
	string getVal() {
		return value;
	}
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		return getVal();
	}
};

class Identifier : public Node {
public:
	Identifier(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Identifier() = default;
	string getVal() {
		return value;
	}
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		return getVal();
	}
};

class PlusOP : public Node {
public:
	PlusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PlusOP() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id);  // generate a unique name
		BBnames.insert(pair<string, string>(name, "int")); // for the 
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // children 0 visited, currentBlock is passed on, expressions do not create new blocks
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID); // // children 2 visited, currentBlock is passed
		ExprTac* in = new ExprTac("+", lhs_name, rhs_name, name); // create the new tac that will be added to the CFG, contains a temporary variable
		(*currentBlock)->add_Tac(in); // add to tac_instructions of the block
		return name;
	}
};

class MinusOP : public Node {
public:
	MinusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MinusOP() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("-", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class MultOP : public Node {
public:
	MultOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MultOP() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("*", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class DivOP : public Node {
public:
	DivOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~DivOP() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("/", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class AssignExpr : public Node {
public:
	AssignExpr(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignExpr() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		string lhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		CopyTac* in = new CopyTac(lhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class GreaterThan : public Node {
public:
	GreaterThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GreaterThan() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac(">", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}

};

class LessThan : public Node {
public:
	LessThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LessThan() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id);
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("<", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class Equals : public Node {
public:
	Equals(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Equals() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("==", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class Or : public Node {
public:
	Or(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Or() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("||", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class And : public Node {
public:
	And(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~And() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ExprTac* in = new ExprTac("&&", lhs_name, rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class LengthOf : public Node {
public:
	LengthOf(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LengthOf() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int"));
		string y_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // what to take length of
		LengthTac* in = new LengthTac(y_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class Expression : public Node {
public:
	Expression(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Expression() = default;
	string getIden() {
		return children[0]->value;
	}
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name;
		string expr; 
		ExpressionTac* in;
		// name = (*currentBlock)->generate_name(++id); 
		expr = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		in = new ExpressionTac(expr);
		(*currentBlock)->add_Tac(in);
		return "";
	}
};

class ExpressionList : public Node {
public:
	ExpressionList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ExpressionList() = default;

	string getIden() {
		return children[1]->value;
	}
	/*
		GenIR to get multiple arguemtns
	*/
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name;
		string expr; 
		ExpressionTac* in;
		/*
			child[0] exprlist
			child[1] expression
		*/
		children[0]->genIR(currentBlock, methods, BBnames, id, blockID); 
		// name = (*currentBlock)->generate_name(++id); 
		expr = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		in = new ExpressionTac(expr);
		(*currentBlock)->add_Tac(in);
		return "";
	}

};

class MethCall : public Node {
public:
	MethCall(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethCall() = default;
	
	string getIden() {
		return children[1]->value;
	}
	void amount_of_arguments(Node* node, int &i) {
		if(dynamic_cast<Expression*>(node) != nullptr) {
			i += 1;
		}
		if(dynamic_cast<ExpressionList*>(node) != nullptr) {
			i += 1;
			amount_of_arguments(node->children[0], i);
		}
	}

	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); // BB->getRandomName
		// BBnames.insert(pair<string, string>(name, ""));
		string expr = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // still in same block, only statements create news
		string func = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		int param_num = 0; 
		if (children.size() > 2) {
			amount_of_arguments(children[2], param_num);
		}
		for (auto const& child : children) {
			child->genIR(currentBlock, methods, BBnames, id, blockID);
		}
		MethCallTac* in = new MethCallTac(func, to_string(param_num), name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class TrueVal : public Node {
public:
	TrueVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~TrueVal() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		return "true";
	}
};

class FalseVal : public Node {
public:
	FalseVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~FalseVal() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		return "false";
	}
};

class ThisOP : public Node {
public:
	ThisOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ThisOP() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		return "this";
	}
};

class IntArray : public Node {
public:
	IntArray(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntArray() = default;
	
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {	
		/* new int[i]*/
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int[]"));
		string i = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		NewArrTac* in = new NewArrTac(i, "int[]", name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class IdenAlloc : public Node {
public:
	IdenAlloc(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IdenAlloc() = default;
	
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		/*new IDEN()*/
		string name = (*currentBlock)->generate_name(++id); 
		string type = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		BBnames.insert(pair<string, string>(name, type));
		NewIdenTac* in = new NewIdenTac(type, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}

};

class Negation : public Node {
public:
	Negation(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Negation() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "bool"));
		string rhs_name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		UnaryTac* in = new UnaryTac("!", rhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

/*
	Statements
*/

class NonStmt : public Node {
public:
	NonStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~NonStmt() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {	
		return "";
	}
};

class Statements : public Node {
public:
	Statements(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Statements() = default;
};

class IfStmt : public Node {
public:
	IfStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfStmt() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {	
		
		blockID += 1;  
		BB* tBlock = new BB(blockID);
		blockID += 1;
		BB* jBlock = new BB(blockID);
		
		/* set the the block after the if-else branching */
		tBlock->setTrue(jBlock);
		// boolean condition
		string conName = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); 

		/*If case too see if nested*/		
		if ((*currentBlock)->getTrue() != nullptr) {
			BB* jumpPath = (*currentBlock)->getTrue(); // hBlock in whileStmt
			jBlock->setTrue(jumpPath);
		}
		// set true and false path to be directly to jump block
		(*currentBlock)->setTrue(tBlock);
		(*currentBlock)->setFalse(jBlock);  

		/*Fill tBlock by calling genIR on various children. Called by reference*/
		string tName = children[1]->genIR(&tBlock, methods, BBnames, id, blockID);
		
		// Add Tacs, unconditional and conditional jumps
		/*Split is conditional*/
		CondTac* splitTac = new CondTac(conName, jBlock->getName()); // default is to go to true
		(*currentBlock)->add_Tac(splitTac);
		/*True blocks is unconditional*/
		JumpTac* trueTac = new JumpTac(jBlock->getName());
		tBlock->add_Tac(trueTac);

		// continue to write to the block after the if branching
		*currentBlock = jBlock;
		return "";
	}
	
};

class IfElseStmt : public Node {
public:
	IfElseStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfElseStmt() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {

		blockID += 1; // this is "silvertejp" --> so no ID clash in nested if while cases
		BB* tBlock = new BB(blockID);
		blockID += 1;
		BB* fBlock = new BB(blockID);
		blockID += 1;
		BB* jBlock = new BB(blockID);

		/* set the the block after the if-else branching */
		tBlock->setTrue(jBlock);  
		fBlock->setTrue(jBlock); 

		string conName = children[0]->genIR(currentBlock, methods, BBnames, id, blockID); // boolean condition
		
		/* If-case to see if nested*/
		if ((*currentBlock)->getTrue() != nullptr) {
			BB* jumpPath = (*currentBlock)->getTrue(); // hBlock in whileStmt
			jBlock->setTrue(jumpPath);
		}

		/* Assign the true and false path for the current block */
		(*currentBlock)->setTrue(tBlock); 
		(*currentBlock)->setFalse(fBlock);
		BB* fBlockCopy = fBlock; // temporary storage to later retrieve falseBlock name from

		/*Fill fBlock and tBlock by calling genIR on various children. Called by reference*/
		string tName = children[1]->genIR(&tBlock, methods, BBnames, id, blockID); // generate true block
		string fName = children[2]->genIR(&fBlock, methods, BBnames, id, blockID); // generate false block

		// Add Tacs, unconditional and conditional jumps
		/*Split is conditional*/
		CondTac* splitTac = new CondTac(conName, fBlockCopy->getName()); // default is to go to true
		(*currentBlock)->add_Tac(splitTac);

		/*True and false blocks have unconditional*/
		JumpTac* trueTac = new JumpTac(jBlock->getName());
		tBlock->add_Tac(trueTac);
		JumpTac* falseTac = new JumpTac(jBlock->getName());
		fBlock->add_Tac(falseTac);

		// continue to write to the block after the while branch
		*currentBlock = jBlock;
		
		return "";
	}
};

class WhileStmt : public Node {
public:
	WhileStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~WhileStmt() = default;

	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		
		blockID += 1;  // To avoid ID clashes
		BB* hBlock = new BB(blockID); // header block
		blockID += 1;
		BB* bBlock = new BB(blockID); // body block
		blockID += 1;
		BB* jBlock = new BB(blockID); // jump block	

		hBlock->setTrue(bBlock); // if true, re-enter the while-loop
		hBlock->setFalse(jBlock); // if false, exit while loop, by going to next block
		bBlock->setTrue(hBlock); // in the true scenario, loop the while loop

		/*If case too see if nested*/		
		if ((*currentBlock)->getTrue() != nullptr) {
			BB* jumpPath = (*currentBlock)->getTrue(); // hBlock in whileStmt
			jBlock->setTrue(jumpPath);
		}
		(*currentBlock)->setTrue(hBlock); // set currentBlock to point to hblock

		/*Fill hBlock and bBlock by calling genIR on various children. Called by reference*/
		string hName = children[0]->genIR(&hBlock, methods, BBnames, id, blockID); // while condition
		string bName = children[1]->genIR(&bBlock, methods, BBnames, id, blockID); // the body

		// Add Tacs, unconditional and conditional jumps
		/*currentBlock to header block unconditional*/
		JumpTac* hTac = new JumpTac(hBlock->getName()); // default is to go to true
		(*currentBlock)->add_Tac(hTac);
		/*Header block to body block is condtional and reverse is non-conditional*/
		CondTac* header_body_split = new CondTac(hName, jBlock->getName());
		hBlock->add_Tac(header_body_split);
		JumpTac* backTac = new JumpTac(hBlock->getName());
		bBlock->add_Tac(backTac);
		
		// continue to write to the block after the while branch
		*currentBlock = jBlock;
		return "";
	}
};

class PrintStmt : public Node {
public:
	PrintStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PrintStmt() = default;
	
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string expr = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		PrintTac* in = new PrintTac(expr);
		(*currentBlock)->add_Tac(in);
		return "";
	}

};

class AssignStmt : public Node {
public:
	AssignStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignStmt() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		// still in same block, only statements create new blocks
		string lhs_name = children[1]->genIR(currentBlock, methods, BBnames, id, blockID); 
		CopyTac* in = new CopyTac(lhs_name, name);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

class ArrayIndexAssign : public Node {
public:
	ArrayIndexAssign(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ArrayIndexAssign() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		/*y[i] = z;*/
		string y = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		string i = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		string z = children[2]->genIR(currentBlock, methods, BBnames, id, blockID);

		ArrAccTac* in = new ArrAccTac(y,i,z);
		(*currentBlock)->add_Tac(in);
		return "";
	}
};

class Index : public Node {
  public:
	Index(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Index() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		
		string name = (*currentBlock)->generate_name(++id); 
		BBnames.insert(pair<string, string>(name, "int"));
		/*y[i]*/
		string y = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		string i = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);

		IndexTac* in = new IndexTac(name,y,i);
		(*currentBlock)->add_Tac(in);
		return name;
	}
};

/*
	Types
*/

class ArrayType : public Node {
public:
	ArrayType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ArrayType() = default;
};

class BoolType : public Node {
public:
	BoolType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~BoolType() = default;
};

class IntType : public Node {
public:
	IntType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntType() = default;
};

class IdenType : public Node {
public:
	IdenType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IdenType() = default;
};


/*
	Method Body
*/

class Variable : public Node {
public:
	Variable(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Variable() = default;

	string getType() {
		return children[0]->type;
	}
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}
	string getClassName() {
		return children[0]->children[0]->value;
	}
};

class VariableList : public Node {
public:
	VariableList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~VariableList() = default;
};

class MethodBody : public Node {
public:
	MethodBody(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodBody() = default;
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name;
		for (auto const& child: children) {
			name = child->genIR(currentBlock, methods, BBnames, id, blockID);
		}
		return name;
	}
};

/*
	Method Declarations

	May want to divide into multple classes of method declarations later
*/

class Parameter : public Node {
public:
	Parameter(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Parameter() = default;
	
	string getType() {
		string ret = children[0]->type;
		if (ret == "classType") {
			ret = children[0]->children[0]->value; // get class type that classType corralates to
		}
		return ret;
	}
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}

	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override  {
		string paramType = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		string paramName = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		ParTac* in = new ParTac(paramName);
		(*currentBlock)->add_Tac(in);
		return "";
	}
	
};

class ParameterList : public Node {
public:
	ParameterList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ParameterList() = default;
	
	string getType() {
		string ret = children[0]->type;
		if (ret == "classType") {
			ret = children[0]->children[0]->value; // get class type that classType corralates to
		}
		return ret;
	}
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override  {
		string paramType = children[0]->genIR(currentBlock, methods, BBnames, id, blockID);
		string paramName = children[1]->genIR(currentBlock, methods, BBnames, id, blockID);
		children[2]->genIR(currentBlock, methods, BBnames, id, blockID);
		ParTac* in = new ParTac(paramName);
		(*currentBlock)->add_Tac(in);
		return "";
	}
};

class Method : public Node {
public:
	Method(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Method() = default;
	string getType() {
		return children[0]->type;
	}
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}
	void getParameterList(vector<std::string> &vec) { // take empty vec as argument
		getParam(children[2], vec);
	}
	void getParam(Node* node, vector<string> &params) { // can be void because vector is passed as reference
		if (dynamic_cast<Parameter*>(node) != nullptr) {
			Parameter* par = dynamic_cast<Parameter*>(node);
			params.push_back(par->getIden());
			params.push_back(par->getType());
		}
		else if (dynamic_cast<ParameterList*>(node) != nullptr) {
			ParameterList* par = dynamic_cast<ParameterList*>(node);
			params.push_back(par->getIden());
			params.push_back(par->getType());
			getParam(node->children[2], params);
		}
	}
	
	string genIR(BB** currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames, int &id, int &blockID) override {
		string name;
		/* Create new block with unique ID and add to methods vector*/
		blockID += 1;
		BB* newBlock = new BB(blockID);
		methods.push_back(newBlock);
		// set the method name for the new block	
		newBlock->setMethodName(this->getIden());
		// Set the current block to the new block
		*currentBlock = newBlock;
		// iterate and generate the content for the children
		for (auto const& child : children) {
			name = child->genIR(currentBlock, methods, BBnames, id, blockID);
		}
		// Add the return value to current block
		ReturnTac* in = new ReturnTac(name); // the last iterated in the for-loop above will be return name
		(*currentBlock)->add_Tac(in);

		return "";
	}
	
};

class MethodDeclarations : public Node {
public:
	MethodDeclarations(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodDeclarations() = default;
};

/*
	Class Declaration
*/

class ClassDeclaration : public Node {

public:
	ClassDeclaration(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ClassDeclaration() = default;
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
		return identifier->getVal();
	}
};

class ClassDeclarationMult : public Node {
public:
	ClassDeclarationMult(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ClassDeclarationMult() = default;
};

/*
	Main Class Declaration
*/

class MainClassDeclaration : public Node {
public:
	MainClassDeclaration(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MainClassDeclaration() = default;
	string getIdenName() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
		return identifier->getVal();
	}
	string getIdenPar() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}
};

class GoalNode : public Node {
public:
	GoalNode(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GoalNode() = default;
};



#endif