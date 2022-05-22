#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "MathStatement.h"

class DivStatement : public MathStatement {
public:
    DivStatement(std::string var, std::string var2) : MathStatement(var, var2){};
    ~DivStatement();

    // Override the parent execute function as it needs to handle when the
    // denominator is 0
    void execute(ProgramState* state, std::ostream& outf);

private:
    int math(int b);
};

#endif
