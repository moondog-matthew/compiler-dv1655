#include "symbolTable.hpp"
#include "Node.h"

/*
	Records
*/

string Record::printRecord() {
		return "name: " + name + "; record: " + recordType + "; type: " + type + ";";
}
Record::Record(string name, string type, string record, int line_no) : name(name), type(type), recordType(record), line_no(line_no) {}

variableRecord::variableRecord(string name, string type, int line_no) : Record(name,type, "Variable", line_no) {}

methodRecord::methodRecord(string name, string type, int line_no) : Record(name,type, "Method", line_no) {}

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

vector<variableRecord*> methodRecord::getParameters() {
	return this->parameters;
}

classRecord::classRecord(string name, string type, int line_no) : Record(name,type, "Class", line_no) {}

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

int Scope::amount_declarations(string name) {
	int amountInScope = 0;
	int sz = inScopeRecords.size();
	for (int i = 0; i < sz; ++i) {
		if (inScopeRecords[i]->name == name) {
			++amountInScope; // index of the record containing the name
			if (amountInScope > 1) {
				if(dynamic_cast<methodRecord*>(inScopeRecords[i]) != nullptr) {
					for (int j = 0; j < i; ++j) {
						if (inScopeRecords[i]->name == inScopeRecords[j]->name && dynamic_cast<methodRecord*>(inScopeRecords[j]) == nullptr) {
							--amountInScope;
						}
					}
				}
				else {
					for (int j = 0; j < i; ++j) {
						if (inScopeRecords[i]->name == inScopeRecords[j]->name && dynamic_cast<methodRecord*>(inScopeRecords[j]) != nullptr) {
							--amountInScope;
						}
					}
				}
			}
		}
	}
	return amountInScope;
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
	populate_ST(node, nullptr);
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

void SymbolTable::populate_ST(Node* node, Node* parent) {
	/*
		Populate the ST by performing a single left-to-right traversal of the AST. 
	*/
	string name;
	string type;
	string parent_name;
	if (node != nullptr) {
		for(auto const& child : node->children) {
			if(dynamic_cast<MainClassDeclaration*>(child) != nullptr) {
				MainClassDeclaration* cl = dynamic_cast<MainClassDeclaration*>(child);
				name =  cl->getIdenName();
				type = name;
				classRecord* classSymbol = new classRecord(name, type, child->lineno); 
				add_symbol(classSymbol);
				enter_scope(name);
				add_symbol(new variableRecord("this", type, child->lineno)); // this
				add_symbol(new methodRecord("main", "void", child->lineno)); // hardcoded  due to limited grammar
				enter_scope("main");
				add_symbol(new variableRecord(cl->getIdenPar(), "String[]", child->lineno)); // hardcoded due to limited grammar
				exit_scope();
				exit_scope();
			}
			else if(dynamic_cast<ClassDeclaration*>(child) != nullptr) {
				ClassDeclaration* cl = dynamic_cast<ClassDeclaration*>(child);
				name =  cl->getIden();
				type = name; // exception, see ppt
				classRecord* classSymbol = new classRecord(name, type, cl->lineno); 
				add_symbol(classSymbol);
				enter_scope(name);
				add_symbol(new variableRecord("this", type, cl->lineno)); // this hardcoded
				populate_ST(child, child);
				exit_scope();
			}
			else if(dynamic_cast<Method*>(child) != nullptr) {
				Method* method = dynamic_cast<Method*>(child);
				name =  method->getIden();
				type = method->getType();
				if (type == "classType") {
					type = child->children[0]->children[0]->value; // Get the class name
				}
				methodRecord* methrec = new methodRecord(name, type, method->lineno);
				add_symbol(methrec);
				ClassDeclaration* classdec = dynamic_cast<ClassDeclaration*>(parent);
				if (classdec != nullptr) {
					parent_name = classdec->getIden();
				}
				/* Add parameters as variables to method*/
				if (dynamic_cast<Parameter*>(method->children[2]) != nullptr || dynamic_cast<ParameterList*>(method->children[2]) != nullptr ) {
					vector<std::string> parameterList;
					method->getParameterList(parameterList);
					for(int i = 0; i < parameterList.size(); i += 2) {
						variableRecord* varrec = new variableRecord(parameterList[i], parameterList[i+1], 0); // name, type
						methrec->addParameter(varrec);
					}
				}			
				
				Record* rec = lookup_symbol(parent_name); // lookup the parents name
				classRecord* classrec = dynamic_cast<classRecord*>(rec);
				if (classrec != nullptr) {
					classrec->addMethod(name, methrec);
				}
				enter_scope(name);
				populate_ST(child, node);
				exit_scope();
			}
			else if (dynamic_cast<Parameter*>(child) != nullptr) {
				// can contain variables
				Parameter* par = dynamic_cast<Parameter*>(child);
				name =  par->getIden();
				type = par->getType();
				add_symbol(new variableRecord(name, type, child->lineno));
				populate_ST(child, node);
			}
			else if (dynamic_cast<ParameterList*>(child) != nullptr) {
				// can contain variables
				ParameterList* par = dynamic_cast<ParameterList*>(child);
				name =  par->getIden();
				type = par->getType();
				add_symbol(new variableRecord(name, type, child->lineno));
				populate_ST(child, node);
			}
			else if(dynamic_cast<Variable*>(child) != nullptr) {
				Variable* var = dynamic_cast<Variable*>(child);
				name =  var->getIden();
				type = var->getType();
				if (type == "classType") {
					type = var->getClassName();
				}

				add_symbol(new variableRecord(name, type, child->lineno));
			}
			else if(dynamic_cast<ClassDeclarationMult*>(child) != nullptr) {
				populate_ST(child, node);
			}
			else if(dynamic_cast<MethodDeclarations*>(child) != nullptr) {
				// can contain methods
				populate_ST(child, parent); // pass the parent, as this is called recursively 
			}
			else if(dynamic_cast<MethodBody*>(child) != nullptr) {
				// can contain variables
				populate_ST(child, node);
			}
			else if(dynamic_cast<VariableList*>(child) != nullptr) {
				// can contain variables
				populate_ST(child, node);
			}
		}
		
	}
} 

int SymbolTable::lookup_dup(string recordName) {
	return current->amount_declarations(recordName);
}
