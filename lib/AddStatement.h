#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "MathStatement.h"

class AddStatement : public MathStatement {
public:
    AddStatement(std::string var, std::string var2) : MathStatement(var, var2){};
    ~AddStatement();

private:
    // Override the math function in the parent class
    int math(int b);
};

#endif
