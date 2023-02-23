#include "Node.h"
#include <map>

/*
	Records
*/

class Record {
public:
    string name; // class/method/variable/etc name
	string type; // what type it is 
	string recordType;

	virtual string printRecord() {
		return "name: " + name + "; record: " + recordType + "; type: " + type + ";";
	}

	Record(string name, string type, string record) : name(name), type(type), recordType(record) {}

};

class variableRecord : public Record {
public:
	variableRecord(string name, string type) : Record(name,type, "Variable") {}
};

class methodRecord : public Record {
protected:
	vector<variableRecord*> parameters;
	map<string,variableRecord*> variables;
public:

	methodRecord(string name, string type) : Record(name,type, "Method") {}

	void addVariable(string varName, variableRecord* record) {
		variables[varName] = record;
	}

	void addParameter(variableRecord* record) {
		parameters.push_back(record);
	}

	variableRecord* lookupVariable(string var) {
		for (auto const &x : variables) {
			if (x.first == var ) {
				return x.second;
			}
		}
		return nullptr;
	}

};

class classRecord : public Record {
protected:
	map<string, variableRecord*> variables;
	map<string,methodRecord*> methods;
public:
	classRecord(string name, string type) : Record(name,type, "Class") {}

	void addVariable(string varName, variableRecord* var) {
		variables[varName] = var;
	}
	
	void addMethod(string methName, methodRecord* method) {
		methods[methName] = method;
	}
	
	variableRecord* lookupVariable(string varname) {
		for (auto const& x : variables) {
			if (x.first == varname) {
				return x.second;
			}
		}
		return nullptr;
	}
	
	methodRecord* lookupMethod(string methname) {
		for (auto const& x : methods) {
			if (x.first == methname) {
				return x.second;
			}
		}
		return nullptr;
	}
};

/*
	Scope
*/

class Scope {
public:
	int next = 0;
	int id; // for generate tree
	string scopename;
	Scope* parentScope;
    vector<Scope*> children; // Scope children
	vector<Record*> inScopeRecords; // all of the records (of various types) the scope contains

	Scope(Scope * parent, string scopename) : parentScope(parent), scopename(scopename) {}

	~Scope() {
		reset();
	}

	Record* lookup(string name)	{
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

	void addRecord(Record* record) {
		inScopeRecords.push_back(record);
	}

	Scope* nextScope(string scopename) {
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

	void reset() {
		int sz = children.size();
		for (auto const& child : children) {
			child->reset();
			delete child;
		}
		children.clear();
		for (auto const& record : inScopeRecords) {
			delete record;
		}
		inScopeRecords.clear();
	}

	void printScope(int depth=0) {

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

	void generate_tree() {
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

	virtual void generate_tree_content(int &count, ofstream *outStream) {
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
    SymbolTable() {
        root = new Scope(nullptr, "Program");
		current = root;
    }

	SymbolTable(Node* node) {
		root = new Scope(nullptr, "Program");
		current = root;
		populate_ST(node);
	}

    ~SymbolTable() {
		reset_ST();
	}; // write this later, deallocate all the nodes

    void enter_scope(string scopename) {
		/* start/push a new nested scope */
		current = current->nextScope(scopename);
	}; 

    void exit_scope() {
		/* exist/pop the curent scope */
		current = current->parentScope;
	}; 

    void add_symbol(Record* record) {
		current->addRecord(record);
	}; 
    Record* lookup_symbol(string recordName) {
		/*search scope for record. return nullptr if not found and record if found*/
		return current->lookup(recordName);
	}; 

    void reset_ST() {
		/* 
			Reset the symbol table.
			- Preparation for new traversal.
		*/
		root->reset();
	}; 
    
	void print_ST() { 
        root->printScope();
		root->generate_tree();
    };

	void populate_ST(Node* node) {
		/*
			Populate the ST by performing a single left-to-right traversal of the AST
		*/
		string name;
		string type;
		if (node != nullptr) {
			for(auto const& child : node->children) {
				// cout << node->type << " " << node->value << endl;
				if(dynamic_cast<MainClassDeclaration*>(child) != nullptr) {
					name =  child->children[0]->value;
					type = name;
					add_symbol(new classRecord(name, type));
					// enter_scope(name);
				}
				else if(dynamic_cast<ClassDeclaration*>(child) != nullptr) {
					name =  child->children[0]->value;
					type = name; // exception, see ppt
					add_symbol(new classRecord(name, type));
					// enter_scope(name);
				}
				else if(dynamic_cast<Method*>(child) != nullptr) {
					name =  child->children[1]->value;
					type = child->children[0]->type;
					add_symbol(new methodRecord(name, type));
					// enter_scope(name);
				}
				else if(dynamic_cast<Variable*>(child) != nullptr) {
					name =  child->children[1]->value;
					type = child->children[0]->type;
					add_symbol(new variableRecord(name, type));
					// enter_scope(name);
				}
				
				populate_ST(child);
				
			}
			
		}
	};  

};
