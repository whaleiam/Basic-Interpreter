#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"

class PrintAllStatement : public Statement {
public:
    PrintAllStatement();
    ~PrintAllStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
