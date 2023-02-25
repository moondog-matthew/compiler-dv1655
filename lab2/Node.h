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
	
	// virtual void semanticCheck() = 0; // Pure virtual, needs to be overwritten
	
	virtual void execute(Node* node) {}; // make pure virtual later
	
	virtual string report_semantic_error() const = 0;
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
	virtual string report_semantic_error() const {
		return "";
	};
};

class Identifier : public Node {
public:
	Identifier(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Identifier() = default;
	string getVal() {
		return value;
	}
	virtual string report_semantic_error() const {
		return "";
	};
};

class PlusOP : public Node {
public:
	PlusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PlusOP() = default;
	virtual string report_semantic_error() const override {
		// if (dynamic_cast<IntVal*>(children[0]) != nullptr) {
		// 	return "@error at line: " + to_string(lineno) + ". Semantic Error: Invalid PlusOP, LHS is not of type integer." ;
		// }
		// else if (dynamic_cast<IntVal*>(children[1]) != nullptr) {
		// 	return "@error at line: " + to_string(lineno) + ". Semantic Error: Invalid PlusOP, RHS is not of type integer." ;
		// }
		cout << "Enters" << endl;
		return "";
	}
};

class MinusOP : public Node {
public:
	MinusOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MinusOP() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class MultOP : public Node {
public:
	MultOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MultOP() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class DivOP : public Node {
public:
	DivOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~DivOP() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class AssignExpr : public Node {
public:
	AssignExpr(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignExpr() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class GreaterThan : public Node {
public:
	GreaterThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GreaterThan() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class LessThan : public Node {
public:
	LessThan(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LessThan() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Equals : public Node {
public:
	Equals(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Equals() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Or : public Node {
public:
	Or(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Or() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class And : public Node {
public:
	And(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~And() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Index : public Node {
public:
	Index(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Index() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class LengthOf : public Node {
public:
	LengthOf(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~LengthOf() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class MethCall : public Node {
public:
	MethCall(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethCall() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Expression : public Node {
public:
	Expression(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Expression() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class ExpressionList : public Node {
public:
	ExpressionList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ExpressionList() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class TrueVal : public Node {
public:
	TrueVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~TrueVal() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class FalseVal : public Node {
public:
	FalseVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~FalseVal() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class ThisOP : public Node {
public:
	ThisOP(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ThisOP() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IntArray : public Node {
public:
	IntArray(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntArray() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IdenAlloc : public Node {
public:
	IdenAlloc(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IdenAlloc() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Negation : public Node {
public:
	Negation(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Negation() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

/*
	Statements
*/

class NonStmt : public Node {
public:
	NonStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~NonStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class Statements : public Node {
public:
	Statements(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Statements() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IfStmt : public Node {
public:
	IfStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IfElseStmt : public Node {
public:
	IfElseStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IfElseStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class WhileStmt : public Node {
public:
	WhileStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~WhileStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class PrintStmt : public Node {
public:
	PrintStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~PrintStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class AssignStmt : public Node {
public:
	AssignStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~AssignStmt() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class ArrayIndexAssign : public Node {
public:
	ArrayIndexAssign(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ArrayIndexAssign() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

/*
	Types
*/

class ArrayType : public Node {
public:
	ArrayType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ArrayType() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class BoolType : public Node {
public:
	BoolType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~BoolType() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IntType : public Node {
public:
	IntType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IntType() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class IdenType : public Node {
public:
	IdenType(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~IdenType() = default;
	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class VariableList : public Node {
public:
	VariableList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~VariableList() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class MethodVariable : public Node {
public:
	MethodVariable(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodVariable() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class MethodStmt : public Node {
public:
	MethodStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodStmt() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};


/*
	Method Declarations

	May want to divide into multple classes of method declarations later
*/

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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class MethodDeclarations : public Node {
public:
	MethodDeclarations(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodDeclarations() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}

	// VariableList* getVars() {
	// 	if (children.size() > 1) {
	// 		if (dynamic_cast<VariableList*>(children[1]) != nullptr) {
	// 			return dynamic_cast<VariableList*>(children[1]);
	// 		}
	// 	}
	// 	return nullptr;
	// }
	// MethodDeclarations* getMethods() {
	// 	if (children.size() == 2) {
	// 		if (dynamic_cast<MethodDeclarations*>(children[1]) != nullptr) {
	// 			return dynamic_cast<MethodDeclarations*>(children[1]);
	// 		}
	// 	}
	// 	else if (children.size() == 3){
	// 		return dynamic_cast<MethodDeclarations*>(children[2]);
	// 	}
	// 	return nullptr;
	// }

};

class ClassDeclarationMult : public Node {
public:
	ClassDeclarationMult(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ClassDeclarationMult() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
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

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};

class GoalNode : public Node {
public:
	GoalNode(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GoalNode() = default;

	virtual string report_semantic_error() const override {
		return "";
		// return type + " " + value + " "+ to_string(lineno) + " " + "" +"\t\t IMPLEMENT";
	}
};



#endif