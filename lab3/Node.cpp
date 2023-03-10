#include "Node.hpp"

Node::Node() {
		type = "uninitialised";
		value = "uninitialised"; 
	}   // Bison needs this.

void Node::print_tree(int depth) {
    for(int i=0; i<depth; i++){
        cout << "  ";
    }
    cout << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
    for(auto i=children.begin(); i!=children.end(); i++) {
        (*i)->print_tree(depth+1);
    }
}

void Node::generate_tree() {
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
void Node::generate_tree_content(int &count, ofstream *outStream) {
    id = count++;
    *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

    for (auto i = children.begin(); i != children.end(); i++)
    {
        (*i)->generate_tree_content(count, outStream);
        *outStream << "n" << id << " -> n" << (*i)->id << endl;
    }
}
string Node::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    for(auto const& child : children) {
        child->genIR(currentBlock, methods, BBnames);
    }
    return value;
}

/*
 * Expressions *
*/

//* IntVal *//
IntVal::IntVal(string t, string v, int l) { 
    type = t; value = v; lineno = l;
}
string IntVal::getVal() {
    return value;
}
string IntVal::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    return getVal();
}

//* Identifier *//
string Identifier::getVal() {
    return value;
}
string Identifier::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    return getVal();
}

//* PlusOP *//
string PlusOP::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name();
    /* ADD temp randmname to ST*/
    BBnames.insert(pair<string, string>(name, "int"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("+", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* MultOP *//
string MultOP::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "int"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("*", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* DivOP *//
string DivOP::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "int"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("/", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* GraeterThan *//
string GreaterThan::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "bool"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac(">", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* LessThan *//
string LessThan::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name();
    BBnames.insert(pair<string, string>(name, "bool"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("<", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* Equals *//
string Equals::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "int"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("==", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* Or *//
string Or::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "bool"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("||", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* And *//
string And::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "int"));
    string lhs_name = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string rhs_name = children[1]->genIR(currentBlock, methods, BBnames);
    ExprTac* in = new ExprTac("&&", lhs_name, rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

//* Expression *//
string Expression::getIden() {
    return children[0]->value;
}
//* ExpressionList *//
string ExpressionList::getIden() {
    return children[1]->value;
}

//* MethCall *//
string MethCall::getIden() {
    return children[1]->value;
}
string MethCall::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); // BB->getRandomName
    BBnames.insert(pair<string, string>(name, ""));
    string expr = children[0]->genIR(currentBlock, methods, BBnames); // still in same block, only statements create news
    string func = children[1]->genIR(currentBlock, methods, BBnames);
    // string param_num = to_string(ST->lookup(this->getIden()));
    // ExprTac* in = new ExprTac(func, param_num, name);
    // currentBlock->add_Tac(in);
    return name;
}

//* TrueVal *//
string TrueVal::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    return "true";
}
//* FalseVal *//
string FalseVal::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    return "false";
}

//* ThisOP *//
string ThisOP::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    return "this";
}

//* Negation *//
string Negation::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    string name = currentBlock->generate_name(); 
    BBnames.insert(pair<string, string>(name, "bool"));
    string rhs_name = children[0]->genIR(currentBlock, methods, BBnames);
    UnaryTac* in = new UnaryTac("!", rhs_name, name);
    currentBlock->add_Tac(in);
    return name;
}

/* 
   * Statements *
*/

//* IfStmt *//
string IfStmt::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {	
    BB* tBlock = new BB();
    BB* fBlock = currentBlock;
    BB* jBlock = new BB();
    tBlock->setTrue(jBlock);
    fBlock->setTrue(jBlock);
    currentBlock->setTrue(tBlock);
    currentBlock->setFalse(fBlock);

    string conName = children[0]->genIR(currentBlock, methods, BBnames); // boolean condition
    string tName = children[1]->genIR(tBlock, methods, BBnames);
    string fName = children[2]->genIR(fBlock, methods, BBnames); // if not true, do nothing

    currentBlock = jBlock; // return returnBlock
    return "";
}

//* IfElseStmt *//
string IfElseStmt::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {   
    BB* tBlock = new BB();
    BB* fBlock = new BB();
    BB* jBlock = new BB();
    tBlock->setTrue(jBlock);
    fBlock->setTrue(jBlock);
    currentBlock->setTrue(tBlock);
    currentBlock->setFalse(fBlock);

    string conName = children[0]->genIR(currentBlock, methods, BBnames); // boolean condition
    string tName = children[1]->genIR(tBlock, methods, BBnames);
    string fName = children[2]->genIR(fBlock, methods, BBnames);

    currentBlock = jBlock; // return returnBlock
    return "";
}

//* WhileStmt *//
string WhileStmt::genIR(BB* &currentBlock, vector<BB*> &methods, std::map<string, string> &BBnames) {
    BB* hBlock = new BB(); // header block
    BB* bBlock = new BB(); // body block
    BB* jBlock = new BB(); // jump block
    string hName = children[0]->genIR(hBlock, methods, BBnames);
    string bName = children[1]->genIR(bBlock, methods, BBnames);
    
    hBlock->setTrue(bBlock);
    hBlock->setFalse(jBlock);
    bBlock->setTrue(hBlock);
    currentBlock->setTrue(hBlock);
    currentBlock = jBlock; // return jumpBlock
}

/*
	* Method Declarations *

	? May want to divide into multple classes of method declarations later
*/

//* Parameter *//
string Parameter::getType() {
    string ret = children[0]->type;
    if (ret == "classType") {
        ret = children[0]->children[0]->value; // get class type that classType corralates to
    }
    return ret;
}
string Parameter::getIden() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
    return identifier->getVal();
}

//* ParameterList *//
string ParameterList::getType() {
    string ret = children[0]->type;
    if (ret == "classType") {
        ret = children[0]->children[0]->value; // get class type that classType corralates to
    }
    return ret;
}
string Parameter::getIden() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
    return identifier->getVal();
}

//* Method *//
string Method::getType() {
    return children[0]->type;
}
string Method::getIden() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
    return identifier->getVal();
}

// take empty vec as argument
void Method::getParameterList(vector<std::string> &vec) {
    getParam(children[2], vec);
}
// can be void because vector is passed as reference
void Method::getParam(Node* node, vector<string> &params) {
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

/*
	* Class Declarations *

	? May want to divide into multple classes of method declarations later
*/

string ClassDeclaration::getIden() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
    return identifier->getVal();
}

/*
	* Main Class Declaration *
*/

//* MainClassDeclaration *//
string MainClassDeclaration::getIdenName() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
    return identifier->getVal();
}
string MainClassDeclaration::getIdenPar() {
    Identifier* identifier = dynamic_cast<Identifier*>(children[1]);
    return identifier->getVal();
}


