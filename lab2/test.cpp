#include "symbolTable.hpp"
#include "semanticCheck.hpp"
#include <typeinfo>

struct Base {}; // non-polymorphic
struct Derived : Base {};
 
struct Base2 { virtual void foo() {} }; // polymorphic
struct Derived2 : Base2 {};

int main() {
    variableRecord* var1 = new variableRecord("var1", "int");
    variableRecord* var2 = new variableRecord("var2", "int");
    variableRecord* var3 = new variableRecord("var3", "int");
    variableRecord* var4 = new variableRecord("var4", "int");
    variableRecord* var11 = new variableRecord("var11", "int");
    variableRecord* var21 = new variableRecord("var21", "int");
    variableRecord* var31 = new variableRecord("var31", "int");
    variableRecord* var41 = new variableRecord("var41", "int");
    methodRecord* meth1 = new methodRecord("meth1", "int");
    
    meth1->addVariable("var1", var1);
    meth1->addParameter(var1);

    classRecord* Class1 = new classRecord("Class1", "string");
    // cout << Class1->printRecord() << endl;
    // Class1->addMethod("meth1", meth1);
    // Class1->addVariable("var1", var1);

    // cout << meth1->printRecord() << endl;
    // variableRecord* varLookup = Class1->lookupVariable("variable1");
    // methodRecord* methLookup = Class1->lookupMethod("method1");
    // varLookup = meth1->lookupVariable("kalas");

    // if (methLookup != nullptr) {
    //     cout << methLookup->printRecord() << endl;
    // }

    // Scope* scope1 = new Scope(nullptr);

    // scope1->addRecord(Class1);
    // scope1->addRecord(meth1);
    
    // Scope* scope2 = scope1->nextScope();
    // scope2->addRecord(var1);
    // Scope* scope3 = scope1->nextScope();
    // Scope* scope4 = scope2->nextScope();

    // scope3->addRecord(var2);
    // scope3->addRecord(var3);
    // scope4->addRecord(var4);

    // // scope1->printScope();

    // // scope2->reset();
    // scope1->printScope();

    // scope1->generate_tree();
    // Record* recLookup = scope1->lookup("meth1");
    // if (recLookup != nullptr) {
    //     cout << recLookup->printRecord() << endl;
    // }

    SymbolTable ST; 

    ST.add_symbol(var1);
    ST.add_symbol(var2);
    ST.enter_scope("Scope1");
    ST.add_symbol(var3);
    ST.enter_scope("Scope2");
    ST.add_symbol(var4);
    ST.exit_scope();
    ST.enter_scope("Scope3");
    ST.add_symbol(meth1);
    ST.exit_scope();
    ST.enter_scope("Scope4");
    ST.add_symbol(Class1);
    ST.exit_scope();
    ST.exit_scope();
    ST.add_symbol(var11);
    ST.add_symbol(var21);
    
    ST.enter_scope("Scope5");
    ST.enter_scope("Scope6");
    ST.add_symbol(var31);
    ST.add_symbol(var41);

    
    // Record* recLookup = ST.lookup_symbol("meth1");
    // if (recLookup != nullptr) {
    //     cout << recLookup->printRecord() << endl;
    // }
    ST.reset_ST();
    ST.enter_scope();
    ST.enter_scope();
    ST.exit_scope();
    ST.exit_scope();
    ST.enter_scope();
    ST.enter_scope();

    // ST.get_current_scope()->printScope();
    ST.print_ST();
    if(ST.lookup_symbol("var3")) {
        cout << "Works" << endl;
    }

}