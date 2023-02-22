#include "Node.h"


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
		/* push record to the current scope */
	}; 
    bool find_symbol(Record* record) {
		/*search scope for record. return nullptr if not found and record if found*/
	}; 
    bool check_scope(Record* record) {
		/*returns true if record is defined in current scope*/
	}; 
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
				// node->execute(node)
				populate_ST(*i);
				
			}
		}
	}; 
    
	void print_ST(Node node) { 
        
    }; 

};
