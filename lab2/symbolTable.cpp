#include "symbolTable.hpp"
#include "Node.h"

/*
	Records
*/

string Record::printRecord() {
		return "name: " + name + "; record: " + recordType + "; type: " + type + ";";
}
Record::Record(string name, string type, string record) : name(name), type(type), recordType(record) {}

variableRecord::variableRecord(string name, string type) : Record(name,type, "Variable") {}

methodRecord::methodRecord(string name, string type) : Record(name,type, "Method") {}

void methodRecord::addVariable(string varName, variableRecord* record) {
		variables[varName] = record;
}

void methodRecord::addParameter(variableRecord* record) {
	parameters.push_back(record);
}

variableRecord* methodRecord::lookupVariable(string var) {
		for (auto const &x : variables) {
			if (x.first == var ) {
				return x.second;
			}
		}
		return nullptr;
	}

classRecord::classRecord(string name, string type) : Record(name,type, "Class") {}

void classRecord::addVariable(string varName, variableRecord* var) {
		variables[varName] = var;
}

void classRecord::addMethod(string methName, methodRecord* method) {
		methods[methName] = method;
}

variableRecord* classRecord::lookupVariable(string varname) {
	for (auto const& x : variables) {
		if (x.first == varname) {
			return x.second;
		}
	}
	return nullptr;
}

methodRecord* classRecord::lookupMethod(string methname) {
	for (auto const& x : methods) {
		if (x.first == methname) {
			return x.second;
		}
	}
	return nullptr;
}

/*
	Scope
*/
void Scope::deallocate() {
	int sz = children.size();
	for (auto const& child : children) {
		child->deallocate();
		delete child;
	}
	children.clear();
	for (auto const& record : inScopeRecords) {
		delete record;
	}
	inScopeRecords.clear();
}

Scope::Scope(Scope * parent, string scopename) : parentScope(parent), scopename(scopename) {}

Scope::~Scope() {
	deallocate();
}

Record* Scope::lookup(string name)	{
	/*
		From a given name, see if it exists in the scope.
	*/
	int inScope = -1;
	int sz = inScopeRecords.size();
	for (int i = 0; i < sz; ++i) {
		if (inScopeRecords[i]->name == name) {
			inScope = i; // index of the record containing the name
		}
	}
	if(inScope != -1) {
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

void Scope::addRecord(Record* record) {
	inScopeRecords.push_back(record);
}

Scope* Scope::nextScope(string scopename) {
	Scope* nextScope;
	int sz = children.size();
	if (next == sz) {
		nextScope = new Scope(this, scopename);
		children.push_back(nextScope);
	}
	else {
		nextScope = children[next];
	}

	this->next++;
	return nextScope;
}

void Scope::printScope(int depth) {

	// cout << "Scope: " << depth << endl;
	string indent = "";
	for(int i=0; i < depth; ++i) { indent += "	"; }

	int rec_sz = inScopeRecords.size();
	for (int i = 0; i < rec_sz; ++i) {
		cout << indent << inScopeRecords[i]->printRecord() << endl;
	}

	int sz = children.size();
	for (int i = 0; i < sz; ++i) {
		children[i]->printScope(depth+1);
	}
}

void Scope::generate_tree() {
	std:ofstream outStream;
	char* filename = "st-tree.dot"; // Outfile name
	outStream.open(filename);
	int count = 0;
	outStream << "digraph {" << std::endl;
	generate_tree_content(count, &outStream);
	outStream << "}" << std::endl;
	outStream.close();
	printf("\nBuilt a parse-tree at %s. Use 'make st-tree' to generate the pdf version.\n", filename);
}

void Scope::generate_tree_content(int &count, ofstream *outStream) {
	id = count++;
	*outStream << "n" << id << " [label=\"" << "Symbol Table" << ":" << scopename;
	for(auto const& record : inScopeRecords) {
		*outStream << "\n" << record->printRecord();
	}
	*outStream << "\"];" << endl;
	for (auto i = children.begin(); i != children.end(); i++)
	{
		(*i)->generate_tree_content(count, outStream);
		*outStream << "n" << id << " -> n" << (*i)->id << endl;
	}
}

void Scope::reset() {
	this->reset_next_counter();
	for (auto const& child : children) {
		child->reset();
	}
}

void Scope::reset_next_counter() {
	this->next = 0;
}

/*
	Symbol Table
*/

void SymbolTable::deallocate_ST() {
	/* Deallocate the ST tree. Used in the destructor*/
	delete root;
}

SymbolTable::SymbolTable() {
	root = new Scope(nullptr, "Program");
	current = root;
}

SymbolTable::SymbolTable(Node* node) {
	root = new Scope(nullptr, "Program");
	current = root;
	populate_ST(node);
}

Scope* SymbolTable::get_root_scope() const {
	return this->root;
}

Scope* SymbolTable::get_current_scope() const {
	return this->current;
}

void SymbolTable::enter_scope(string scopename) {
	/* start/push a new nested scope */
	current = current->nextScope(scopename);
}; 

void SymbolTable::exit_scope() {
	/* exist/pop the curent scope */
	current = current->parentScope;
}; 

void SymbolTable::add_symbol(Record* record) {
	current->addRecord(record);
}; 

Record* SymbolTable::lookup_symbol(string recordName) {
	/*search scope for record. return nullptr if not found and record if found*/
	return current->lookup(recordName);
}; 

void SymbolTable::reset_ST() {
	/* 
		Reset the symbol table. Used to traverse to go to root again and reset the next counter.
		- Preparation for new traversal.
	*/
	this->current = this->root;
	this->root->reset();
}; 

void SymbolTable::print_ST() { 
	root->printScope();
	root->generate_tree();
};

void SymbolTable::populate_ST(Node* node) {
	/*
		Populate the ST by performing a single left-to-right traversal of the AST. 
	*/
	string name;
	string type;
	if (node != nullptr) {
		for(auto const& child : node->children) {
			// cout << node->type << " " << node->value << endl;
			if(dynamic_cast<MainClassDeclaration*>(child) != nullptr) {
				MainClassDeclaration* cl = dynamic_cast<MainClassDeclaration*>(child);
				name =  cl->getIdenName();
				type = name;
				add_symbol(new classRecord(name, type));
				enter_scope(name);
				add_symbol(new variableRecord("this", type)); // this
				add_symbol(new methodRecord("main", "void")); // hardcoded  due to limited grammar
				enter_scope("main");
				add_symbol(new variableRecord(cl->getIdenPar(), "String[]")); // hardcoded due to limited grammar
				exit_scope();
				exit_scope();
			}
			else if(dynamic_cast<ClassDeclaration*>(child) != nullptr) {
				ClassDeclaration* cl = dynamic_cast<ClassDeclaration*>(child);
				name =  cl->getIden();
				type = name; // exception, see ppt
				add_symbol(new classRecord(name, type));
				enter_scope(name);
				add_symbol(new variableRecord("this", type)); // this hardcoded
				populate_ST(child);
				exit_scope();
			}
			else if(dynamic_cast<Method*>(child) != nullptr) {
				Method* method = dynamic_cast<Method*>(child);
				name =  method->getIden();
				type = method->getType();
				add_symbol(new methodRecord(name, type));
				enter_scope(name);
				populate_ST(child);
				exit_scope();
			}
			
			else if (dynamic_cast<Parameter*>(child) != nullptr) {
				// can contain variables
				Parameter* par = dynamic_cast<Parameter*>(child);
				name =  par->getIden();
				type = par->getType();
				add_symbol(new variableRecord(name, type));
				populate_ST(child);
			}
			else if (dynamic_cast<ParameterList*>(child) != nullptr) {
				// can contain variables
				ParameterList* par = dynamic_cast<ParameterList*>(child);
				name =  par->getIden();
				type = par->getType();
				add_symbol(new variableRecord(name, type));
				populate_ST(child);

			}
			else if(dynamic_cast<Variable*>(child) != nullptr) {
				Variable* var = dynamic_cast<Variable*>(child);
				name =  var->getIden();
				type = var->getType();
				add_symbol(new variableRecord(name, type));
			}
			else if(dynamic_cast<ClassDeclarationMult*>(child) != nullptr) {
				populate_ST(child);
			}
			else if(dynamic_cast<MethodDeclarations*>(child) != nullptr) {
				// can contain methods
				populate_ST(child);
			}
			else if(dynamic_cast<MethodVariable*>(child) != nullptr) {
				// can contain variables
				populate_ST(child);
			}
			else if(dynamic_cast<MethodStmt*>(child) != nullptr) {
				// can contain variables
				populate_ST(child);
			}
			else if(dynamic_cast<MethodVariable*>(child) != nullptr) {
				// can contain variables
				populate_ST(child);
			}
			else if(dynamic_cast<VariableList*>(child) != nullptr) {
				// can contain variables
				populate_ST(child);
			}
		}
		
	}
} 