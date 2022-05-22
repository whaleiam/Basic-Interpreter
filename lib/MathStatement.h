#ifndef MATH_STATEMENT_INCLUDED
#define MATH_STATEMENT_INCLUDED

#include "Statement.h"
#include <cstdlib>

class MathStatement : public Statement {
public:
    MathStatement(std::string var, std::string var2) : variableName(var), variableName2(var2){};
    ~MathStatement();
    virtual void execute(ProgramState* state, std::ostream& outf);

protected:
    // Helper function to perform the mathematical expression within execute
    virtual int math(int b) = 0;

    int a;

    // The 2 variables
    std::string variableName, variableName2;
};

#endif
