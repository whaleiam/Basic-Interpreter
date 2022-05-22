#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "Statement.h"

class ReturnStatement : public Statement {
public:
    ReturnStatement();
    ~ReturnStatement();
    void execute(ProgramState* state, std::ostream& outf);
};

#endif