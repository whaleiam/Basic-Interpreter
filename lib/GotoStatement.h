#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"

// Not only will this class handle the GOTO statement, but it
// will also serve as a parent class for both the IF and GOSUB
// statements
class GotoStatement : public Statement {
public:
    GotoStatement(int line);
    ~GotoStatement();

    // Virtual function since child classes will most likely need to override it
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    // Handle jumping the Program Counter which will remain the same
    // in all derived class statements
    void jump(ProgramState* state);

    // The line to jump to
    int lineToJump;
};

#endif