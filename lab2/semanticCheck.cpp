#include "semanticCheck.hpp"

SemanticAnalysis::SemanticAnalysis(Node* ast, SymbolTable* st) {
    this->AST_root = ast;
    this->ST = st;

    this->ST->reset_ST();
    // this->ST->print_ST();
    semantic_check(AST_root);
    print_errors();

}

void SemanticAnalysis::print_errors() {
    for (auto const& error : errors) {
        cout << error << endl;
    }
}

bool SemanticAnalysis::contains_error() const {
    if (errors.size() > 0) {
        return true;
    }
    return false;
}

string SemanticAnalysis::semantic_check(Node* node) {
    string error;
    if (dynamic_cast<GoalNode*>(node) != nullptr) {
        string mainclass = semantic_check(node->children[0]);
        string classdec= semantic_check(node->children[1]);

    }
    else if(dynamic_cast<MainClassDeclaration*>(node) != nullptr) {
        ST->enter_scope();
        ST->enter_scope();
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        ST->exit_scope();
        ST->exit_scope();
        return "void"; // hard coded
    }
    else if(dynamic_cast<ClassDeclaration*>(node) != nullptr) {
        ClassDeclaration* type = dynamic_cast<ClassDeclaration*>(node);
        ST->enter_scope();
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        ST->exit_scope();
        return type->getIden();
    }
    else if(dynamic_cast<ClassDeclarationMult*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if(dynamic_cast<Method*>(node) != nullptr) {
        Method* type = dynamic_cast<Method*>(node);
        ST->enter_scope();
        for (auto const& child : node->children) {
            string ret = semantic_check(child);
        }
        ST->exit_scope();
        string ret_type = semantic_check(node->children.back()); 
        if (ret_type != type->getType()) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Type mismatch: Return value type (type: "+ret_type +") and method type (type: "+type->getType() +")is not alligning.");
        }
        return type->getType();
    }
    else if(dynamic_cast<MethodDeclarations*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if(dynamic_cast<MethodBody*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if(dynamic_cast<Variable*>(node) != nullptr) {
        Variable* typeNode = dynamic_cast<Variable*>(node);
        return typeNode->getType();
    }
    else if(dynamic_cast<VariableList*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if(dynamic_cast<Parameter*>(node) != nullptr) {
        Parameter* typeNode = dynamic_cast<Parameter*>(node);
        return typeNode->getType();
    }
    else if(dynamic_cast<ParameterList*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if (dynamic_cast<ArrayType*>(node) != nullptr) {
        return "int[]";
    }
    else if (dynamic_cast<BoolType*>(node) != nullptr) {
        return "bool";
    }
    else if (dynamic_cast<IntType*>(node) != nullptr) {
        return "int";
    }
    else if(dynamic_cast<WhileStmt*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        string stmt = semantic_check(node->children[1]);
        if (expr != "bool") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: While statement has invalid expression, must be type bool");
        }
        return "";
    }
    else if(dynamic_cast<PrintStmt*>(node) != nullptr) {
        return "";
    }
    else if(dynamic_cast<AssignStmt*>(node) != nullptr) {
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != RHS) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: LHS and RHS must be of same type.");
        }
        return "";
    }
    else if(dynamic_cast<ArrayIndexAssign*>(node) != nullptr) {
        string arrayType =  semantic_check(node->children[0]);
        string indexType = semantic_check(node->children[1]);
        string RHS = semantic_check(node->children[2]);
        if (arrayType != RHS) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Can't assign " + RHS + " type to an int array.");
        }
        if (indexType != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: index is not of type int.");
        }
        return "";
    }
    else if(dynamic_cast<Statements*>(node) != nullptr) {
        for(auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }
    else if(node->type == "IF" || node->type == "IfElse" ){
        string expr = semantic_check(node->children[0]);
        string stmt = semantic_check(node->children[1]);
        if (expr != "bool") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: If statement has invalid expression, must be type bool");
        }
        return "";
    }
    else if (node->type == "AddExpression" || node->type == "SubExpression" || node->type == "MultExpression" || node->type == "DivExpression") { 
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != "int" || RHS != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Expression '" + node->type + "' is not supported between types" + LHS + "" + RHS);
        }
        return "int";
    }
    else if (node->type == "GreaterThan" || node->type == "LessThan") { 
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != "int" || RHS != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Expression '" + node->type + "' is not supported between types" + LHS + "" + RHS);
        } 
        return "bool";
    }
    else if (node->type == "Assign") { 
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != RHS) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Assignment between type '" + LHS + "' and type '" + RHS + " 'is not supported.");
        } 
        return "";
    }
    else if (node->type == "Equals" ) { 
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != RHS || LHS != "int" || LHS != "bool") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Operation '"+ node->type +"' between type '" + LHS + "' and type '" + RHS + " 'is not supported.");
        } 
        return "bool";
    }
    else if (node->type == "OR" || node->type == "AND") {
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != "bool" || RHS != "bool") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Operation '"+ node->type +"' between type '" + LHS + "' and type '" + RHS + " 'is not supported. Must be booleans.");
        } 
        return "bool";
    }
    else if (dynamic_cast<Index*>(node) != nullptr) {
        string iden = semantic_check(node->children[0]);
        string valindex = semantic_check(node->children[1]);
        if (valindex != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Can't take index with non-integers.");
        }
        return "int"; // We only have int arrays in mini Java?
        // return iden; 
    }
    else if (dynamic_cast<LengthOf*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        return "int";
    }
    else if (dynamic_cast<MethCall*>(node) != nullptr) {
        MethCall* methnode= dynamic_cast<MethCall*>(node);

        int counter = 0;
        // Make calls later !! Check for semantic errors
        if (node->children.size() == 3) {
            string expr = semantic_check(node->children[0]);
            string iden = semantic_check(node->children[1]);
            string exprlist = semantic_check(node->children[2]);
        }
        else if (node->children.size() == 2) {
            string expr = semantic_check(node->children[0]);
            string iden = semantic_check(node->children[1]);
        }
        string iden = methnode->getIden();
        Record* methrec = ST->lookup_symbol(iden);
        if (methrec == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined method: " + iden);
            return "";
        }
        else {
            string methrectype = methrec->type;
            return methrectype;
        }
    }
    else if (dynamic_cast<TrueVal*>(node) != nullptr) {
        return "bool";
    }
    else if (dynamic_cast<FalseVal*>(node) != nullptr) {
        return "bool";
    }
    else if (dynamic_cast<Identifier*>(node) != nullptr) { // check for usage of non-declared variables
        Identifier* iden = dynamic_cast<Identifier*>(node);
        string rettype = "";
        string var = iden->getVal();
        Record* idenRec = ST->lookup_symbol(var);
        if (idenRec == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable " + var);
            return "";
        }
        else {
            string rettype = idenRec->type;
            return rettype;
        }
    }
    else if (dynamic_cast<ThisOP*>(node) != nullptr) {
        Record* classrec = ST->lookup_symbol("this"); // refers to class
        if (classrec == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable 'this'.");
        }
    }
    else if (dynamic_cast<IntArray*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        if (expr != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: index is not of type int.");
        }
        return "int[]";
    }
    else if (dynamic_cast<IdenAlloc*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        if (expr != "Identifier") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Name must be identifier.");
        }
        return "bool";
    }
    else if (dynamic_cast<Negation*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        if (expr != "bool") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: expected negation of bool. Got: " + expr + ".");
        }
        return "bool";
    }
    else if (dynamic_cast<Expression*>(node) != nullptr) {
        string expr = semantic_check(node->children[0]);
        return "";
    }
    else if (dynamic_cast<ExpressionList*>(node) != nullptr) {
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        return "";
    }

    else if (dynamic_cast<IntVal*>(node) != nullptr) {
        return "int";
    }

    
    return "";
}
