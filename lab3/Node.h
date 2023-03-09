
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

extern std::map<string, string> BBnames; 

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
		
	virtual string genIR(BB* &currentBlock) {
		for(auto const& child : children) {
			child->genIR(currentBlock);
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
	string genIR(BB* &currentBlock) override {
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
	string genIR(BB* &currentBlock) override {
		return getVal();
	}
};

class PlusOP : public Node {
public:
	PlusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PlusOP() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("+", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class MinusOP : public Node {
public:
	MinusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MinusOP() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("-", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class MultOP : public Node {
public:
	MultOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MultOP() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("*", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class DivOP : public Node {
public:
	DivOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~DivOP() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("/", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class AssignExpr : public Node {
public:
	AssignExpr(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignExpr() = default;
};

class GreaterThan : public Node {
public:
	GreaterThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GreaterThan() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac(">", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}

};

class LessThan : public Node {
public:
	LessThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LessThan() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("<", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class Equals : public Node {
public:
	Equals(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Equals() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("==", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class Or : public Node {
public:
	Or(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Or() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "bool"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("||", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class And : public Node {
public:
	And(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~And() = default;
	string genIR(BB* &currentBlock) override {
		string name = "RAndomName"; // BB->getRandomName
		/* ADD temp randmname to ST*/
		BBnames.insert(pair<string, string>(name, "int"));
		string lhs_name = children[0]->genIR(currentBlock); // still in same block, only statements create news
		string rhs_name = children[1]->genIR(currentBlock);
		ExprTac* in = new ExprTac("&&", lhs_name, rhs_name, name);
		currentBlock->add_Tac(in);
		return name;
	}
};

class Index : public Node {
public:
	Index(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Index() = default;
};

class LengthOf : public Node {
public:
	LengthOf(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LengthOf() = default;
};

class Expression : public Node {
public:
	Expression(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Expression() = default;
	string getIden() {
		return children[0]->value;
		// return "";
	}
};

class ExpressionList : public Node {
public:
	ExpressionList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ExpressionList() = default;

	string getIden() {
		return children[1]->value;
	}
};

class MethCall : public Node {
public:
	MethCall(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethCall() = default;
	
	string getIden() {
		return children[1]->value;
	}
};

class TrueVal : public Node {
public:
	TrueVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~TrueVal() = default;
};

class FalseVal : public Node {
public:
	FalseVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~FalseVal() = default;
};

class ThisOP : public Node {
public:
	ThisOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ThisOP() = default;
};

class IntArray : public Node {
public:
	IntArray(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntArray() = default;
};

class IdenAlloc : public Node {
public:
	IdenAlloc(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IdenAlloc() = default;
};

class Negation : public Node {
public:
	Negation(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Negation() = default;
};

/*
	Statements
*/

class NonStmt : public Node {
public:
	NonStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~NonStmt() = default;
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
	string genIR(BB* &currentBlock) override {	
		BB* tBlock = new BB();
		BB* fBlock = currentBlock;
		BB* jBlock = new BB();
		tBlock->setTrue(jBlock);
		fBlock->setTrue(jBlock);
		currentBlock->setTrue(tBlock);
		currentBlock->setFalse(fBlock);

		string conName = children[0]->genIR(currentBlock); // boolean condition
		string tName = children[1]->genIR(tBlock);
		string fName = children[2]->genIR(fBlock); // if not true, do nothing

		currentBlock = jBlock; // return returnBlock
		return "";
	}
	
};

class IfElseStmt : public Node {
public:
	IfElseStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfElseStmt() = default;
	string genIR(BB* &currentBlock) override {
		
		BB* tBlock = new BB();
		BB* fBlock = new BB();
		BB* jBlock = new BB();
		tBlock->setTrue(jBlock);
		fBlock->setTrue(jBlock);
		currentBlock->setTrue(tBlock);
		currentBlock->setFalse(fBlock);

		string conName = children[0]->genIR(currentBlock); // boolean condition
		string tName = children[1]->genIR(tBlock);
		string fName = children[2]->genIR(fBlock);

		currentBlock = jBlock; // return returnBlock
		return "";
	}
};

class WhileStmt : public Node {
public:
	WhileStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~WhileStmt() = default;

	string genIR(BB* &currentBlock) override {
		BB* hBlock = new BB(); // header block
		BB* bBlock = new BB(); // body block
		BB* jBlock = new BB(); // jump block
		string hName = children[0]->genIR(hBlock);
		string bName = children[1]->genIR(bBlock);
		
		hBlock->setTrue(bBlock);
		hBlock->setFalse(jBlock);
		bBlock->setTrue(hBlock);
		currentBlock->setTrue(hBlock);
		currentBlock = jBlock; // return jumpBlock
	}
};

class PrintStmt : public Node {
public:
	PrintStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PrintStmt() = default;
};

class AssignStmt : public Node {
public:
	AssignStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignStmt() = default;
};

class ArrayIndexAssign : public Node {
public:
	ArrayIndexAssign(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ArrayIndexAssign() = default;
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
	
};

class MethodDeclarations : public Node {
public:
	MethodDeclarations(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodDeclarations() = default;
};


/*
	Class Declaration

	May want to divide into multple classes of class declarations later
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