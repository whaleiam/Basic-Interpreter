#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement() {}

PrintAllStatement::~PrintAllStatement() {}

void PrintAllStatement::execute(ProgramState* state, std::ostream& outf) {
    // Write everything to the passed output stream
    state->writeAllToOutput(outf);

    // Passing a 0 to the setCounter function increments the Program's
    // line counter by 1
    state->setCounter(0);
}