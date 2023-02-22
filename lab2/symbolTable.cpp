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
		return "name: " + name + " record: " + recordType + " type: " + type;
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
	// string scopeName;
	Scope* parentScope;
    vector<Scope*> children; // Scope children
	vector<Record*> inScopeRecords; // all of the records (of various types) the scope contains

	Scope(Scope * parent) : parentScope(parent) {}

	~Scope() {
		reset();
	}

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
			nextScope = new Scope(this);
			children.push_back(nextScope);
		}
		else {
			nextScope = children[next];
		}
	
		this->next++;
		return nextScope;
	}

	void reset() {
		resetScope(this);
	}

	void resetScope(Scope* node) {
		int sz = children.size();
		for (int i = 0; i < sz; ++i) {
			resetScope(children[i]);
		}
		delete node;
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

	void generate_scope() {
		std:ofstream outStream;
		char* filename = "tree.dot"; // Outfile name
		outStream.open(filename);
		int count = 0;
		outStream << "digraph {" << std::endl;
		generate_scope_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();
		printf("\nBuilt a parse-tree at %s. Use 'make st-tree' to generate the pdf version.", filename);
	}

	virtual void generate_scope_content(int &count, ofstream *outStream) {
		int id = count++;
	  	*outStream << "n" << id << " [label=\"" << "Symbol Table" << ":" << "placeholder" << "\"];" << endl;

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
        root = new Scope(nullptr);
		current = root;
    }

    ~SymbolTable() {

	}; // write this later, deallocate all the nodes

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
				// node->execute(node)
				populate_ST(*i);
				
			}
		}
	}; 
    
	void print_ST() { 
        root->printScope();
    }; 

};
