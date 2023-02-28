#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

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
		
	virtual void execute(Node* node) {}; // make pure virtual later
	
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
};

class Identifier : public Node {
public:
	Identifier(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Identifier() = default;
	string getVal() {
		return value;
	}
};

class PlusOP : public Node {
public:
	PlusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PlusOP() = default;
};

class MinusOP : public Node {
public:
	MinusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MinusOP() = default;
};

class MultOP : public Node {
public:
	MultOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MultOP() = default;
};

class DivOP : public Node {
public:
	DivOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~DivOP() = default;
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
};

class LessThan : public Node {
public:
	LessThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LessThan() = default;
};

class Equals : public Node {
public:
	Equals(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Equals() = default;
};

class Or : public Node {
public:
	Or(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Or() = default;
};

class And : public Node {
public:
	And(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~And() = default;
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
};

class ExpressionList : public Node {
public:
	ExpressionList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ExpressionList() = default;

	int getNumArgs() {

	}
};

class MethCall : public Node {
public:
	MethCall(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethCall() = default;
	string getIden() {
		return children[1]->value;
	}

	int amount_of_arguments() {
		int amount = amArg(children[2], 0);
		return amount;
	}
	int amArg(Node* node, int depth) {
		if (dynamic_cast<Expression*>(node) != nullptr) {
			++depth;
			return depth; // Parameter class can only have 1 parameter
		}
		else if (dynamic_cast<ExpressionList*>(node) != nullptr) {
			int depth_1 = amArg(node->children[0], ++depth);
			return depth_1;
		}
		else {
			return depth;
		}
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
};

class IfElseStmt : public Node {
public:
	IfElseStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfElseStmt() = default;
};

class WhileStmt : public Node {
public:
	WhileStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~WhileStmt() = default;
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
		return children[0]->type;
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
		return children[0]->type;
	}
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
		return identifier->getVal();
	}

};

class Method : public Node {
private:
	// assign these values when creating the node? Because no fixed order. Getters and setters, to get them. 
	// Parameter* parameters;
	// MethodBody* method_body;
	// Expression* return_expr;
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
	int amount_of_parameters() {
		int amount = amPar(children[2], 0);
		return amount;
	}
	int amPar(Node* node, int depth) {
		if (dynamic_cast<Parameter*>(node) != nullptr) {
			++depth;
			return depth; // Parameter class can only have 1 parameter
		}
		else if (dynamic_cast<ParameterList*>(node) != nullptr) {
			int depth_1 = amPar(node->children[2], ++depth);
			return depth_1;
		}
		else {
			return depth;
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
private:
	// assign these values when creating the node? Because no fixed order. Getters and setters, to get them. 
	// VariableList* variables;
	// MethodDeclarations* methods;

public:
	ClassDeclaration(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ClassDeclaration() = default;
	string getIden() {
		Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
		return identifier->getVal();
	}

	// VariableList* getVars() {
	// 	return nullptr;
	// }
	// MethodDeclarations* getMethods() {
	// 	return nullptr;
	// }

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