#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "GotoStatement.h"

class GoSubStatement : public GotoStatement {
public:
    GoSubStatement(int line, int currLine);
    ~GoSubStatement();
    void execute(ProgramState* state, std::ostream& outf);

private:
    // Provide a line number to push into the stack, which we can
    // pop out when hitting a return statement
    int stackLine;
};

#endif
