#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "GotoStatement.h"

class IfStatement : public GotoStatement {
public:
    IfStatement(std::string var1, std::string operation, int b, int line);
    void execute(ProgramState* state, std::ostream& outf);

private:
    // This function will determine which comparison operator to use
    int comparisonOperator(std::string op);

    // Returns a bool value to determine whether the if condition
    // is true or not
    bool conditionTrue();

    // The 2 numbers being compared
    int num1, num2;

    // This integer will correspond to a respective comparison operation
    /*  1. >
     *  2. <
     *  3. =
     *  4. >=
     *  5. <=
     *  6. <>
     */
    int compOp;

    std::string var;
};

#endif