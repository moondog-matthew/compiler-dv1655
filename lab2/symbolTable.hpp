#ifndef SYMBOL_H
#define	SYMBOL_H

#include "Node.h"
#include <map>

using namespace std;

class Record {
public:
    string name; // class/method/variable/etc name
	string type; // what type it is 
	string recordType;
	int line_no;
	virtual string printRecord();
	Record(string name, string type, string record, int line_no);

};

class variableRecord : public Record {
public:
	variableRecord(string name, string type, int line_no);
};

class methodRecord : public Record {
protected:
	vector<variableRecord*> parameters;
	map<string, variableRecord*> variables;
public:
	methodRecord(string name, string type, int line_no);
	void addVariable(string varName, variableRecord* record);
	void addParameter(variableRecord* record);
	variableRecord* lookupVariable(string var);
	vector<variableRecord*> getParameters();
};

class classRecord : public Record {
protected:
	map<string, variableRecord*> variables;
	map<string, methodRecord*> methods;
public:
	classRecord(string name, string type, int line_no);
	void addVariable(string varName, variableRecord* var);
	void addMethod(string methName, methodRecord* method);
	variableRecord* lookupVariable(string varname);
	methodRecord* lookupMethod(string methname);
};


class Scope {
private:
	void deallocate();
public:
	int next = 0;
	int id; // for generate tree
	string scopename;
	Scope* parentScope;
    vector<Scope*> children; // Scope children
	vector<Record*> inScopeRecords; // all of the records (of various types) the scope contains

	Scope(Scope * parent, string scopename);
	~Scope();
	Record* lookup(string name, int lookup_type);
	void addRecord(Record* record);
	Scope* nextScope(string scopename = "");
	void printScope(int depth = 0);
	void generate_tree();
	virtual void generate_tree_content(int &count, ofstream *outStream);
	void reset();
	void reset_next_counter();
	int amount_declarations(string name);
};

class SymbolTable {
private:

	Scope* root;
	Scope* current;
	vector<string> duplicateDeclarations; // error strings to be used by semantic analysis

	void deallocate_ST();

public:
    // should the ST get populated in the constructor? If call populate_ST from here
    SymbolTable();
	SymbolTable(Node* node);
    ~SymbolTable() = default;
	Scope* get_root_scope() const;
	Scope* get_current_scope() const;

    void enter_scope(string scopename = "");
    // void enter_scope(string scopename);
    void exit_scope();
    void add_symbol(Record* record);
    Record* lookup_symbol(string recordName, int lookup_type);
	int lookup_dup(string recordName); // returns true if contains duplicate. vector contains nodes that are duplicates
    void reset_ST();
	void print_ST();
	void populate_ST(Node* node, Node* parent);
};

#endif // SYMBOL_H