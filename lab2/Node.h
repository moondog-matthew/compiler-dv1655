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
	list<Node*> children;
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

		printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.", filename);
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
	
	virtual void ST_fill() { // fill the symbolTable, will only be called by root node?

		for(auto i = children.begin(); i != children.end(); ++i) {
			(*i)->ST_fill();
		}
	
	};
};

/*
	Expressions
*/
class IntVal : public Node {
public:
	IntVal(string t, string v, int l) { type = t; value = v; lineno = l;}
	
	virtual ~IntVal() = default;
};

class Identifier : public Node {
public:
	Identifier(string t, string v, int l) { type = t; value = v; lineno = l;}
	
	virtual ~Identifier() = default;
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

class MethCall : public Node {
public:
	MethCall(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethCall() = default;
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
};

class VariableList : public Node {
public:
	VariableList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~VariableList() = default;
};

class MethodVariable : public Node {
public:
	MethodVariable(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodVariable() = default;
};

class MethodStmt : public Node {
public:
	MethodStmt(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodStmt() = default;
};


/*
	Method Declarations

	May want to divide into multple classes of method declarations later
*/

class Method : public Node {
public:
	Method(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Method() = default;
};

class MethodDeclarations : public Node {
public:
	MethodDeclarations(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~MethodDeclarations() = default;
};

class Parameter : public Node {
public:
	Parameter(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~Parameter() = default;
};

class ParameterList : public Node {
public:
	ParameterList(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ParameterList() = default;
};


/*
	Class Declaration

	May want to divide into multple classes of class declarations later
*/

class ClassDeclaration : public Node {
public:
	ClassDeclaration(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~ClassDeclaration() = default;
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
};

class GoalNode : public Node {
public:
	GoalNode(string t, string v, int l) { type = t; value = v; lineno = l;}
	virtual ~GoalNode() = default;
};



/*
	Records
*/

class Record {
public:
    string name; // class/method/variable/etc name
	string type; // what type it is 
	void printRecord() {
		cout << name << " " << type << endl;
	}
};

/*
	Scope
*/

class Scope {
public:
	int next = 0;
	Scope* parentScope;
    vector<Scope*> children;
	vector<Record*> inScopeRecords;




	Record* lookup(string name)	{
		/*
			From a given name, see if it exists in the scope.
		*/
		int inScope;
		int sz = inScopeRecords.size();
		for (int i = 0; i < sz; ++i) {
			if (inScopeRecords[i]->name == name) {
				inScope = i; // index of the record containing the name
			}
		}
		if(inScope) {
			return inScopeRecords[inScope];
		}
		else {
			if (parentScope == nullptr) {
				return nullptr;
			}
			else {
				return parentScope->lookup(name);
			}
		}
	}

	void addRecord(Record* record) {
		inScopeRecords.push_back(record);
	}

	Scope* nextScope() {
		Scope* nextScope;
		int sz = children.size();
		if (next == sz) {
			nextScope = new Scope();
			nextScope->parentScope = this;  // make the node have the current scope as a parent
			children.push_back(nextScope);
		}
		else {
			nextScope = children[next];
		}
	
		this->next++;
		return nextScope;
	}
};


/*
	Symbol Table
*/

class SymbolTable {
private:

	Scope* root;
	Scope* current;

public:

    // should the ST get populated in the constructor? If call populate_ST from here
    SymbolTable() = default; 
    SymbolTable(Node* node) {
        root = new Scope();
		current = root;
    }

    ~SymbolTable() = default; // write this later, deallocate all the nodes

    /*
        Suggested operations from PPT
    */
    void enter_scope() {
		/* start/push a new nested scope */
		current = current->nextScope();
	}; 

    void exit_scope() {
		/* exist/pop the curent scope */
		current = current->parentScope;
	}; 

    void add_symbol(Record* record) {}; // push record to the current scope
    bool find_symbol(Record* record) {}; // search scope for record. return nullptr if not found and record if found
    bool check_scope(Record* record) {}; // returns true if record is defined in current scope
    void reset_ST() {
		/* 
			Reset the symbol table.
			- Preparation for new traversal.
		*/
	}; 

    /*
        Mandatory for the assignment
    */
    void populate_ST(Node* node) {
		/*
			Populate the ST by performing a single left-to-right traversal of the AST
		*/
		if (node != nullptr) {
			for(auto i = node->children.begin(); i != node->children.end(); i++) {
				// cout << node->type << " " << node->value << endl;
				populate_ST(*i);
				
			}
		}
	}; 
    
	void print_ST(Node node) { 
        
    }; 

};



#endif