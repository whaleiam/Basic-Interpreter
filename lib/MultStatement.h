#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "MathStatement.h"

class MultStatement : public MathStatement {
public:
    MultStatement(std::string var, std::string var2) : MathStatement(var, var2){};
    ~MultStatement();

private:
    int math(int b);
};

#endif
