#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "MathStatement.h"

class SubStatement : public MathStatement {
public:
    SubStatement(std::string var, std::string var2) : MathStatement(var, var2){};
    ~SubStatement();

private:
    int math(int b);
};

#endif
