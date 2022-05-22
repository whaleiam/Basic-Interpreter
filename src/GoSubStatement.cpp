#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int line, int currLine) : GotoStatement(line), stackLine(currLine) {}

GoSubStatement::~GoSubStatement() {}

void GoSubStatement::execute(ProgramState* state, std::ostream& outf) {
    // Call the parent execute function
    GotoStatement::execute(state, outf);

    // Then push a line number to the stack
    state->pushToStack(stackLine);
}