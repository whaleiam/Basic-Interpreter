#include "ReturnStatement.h"

ReturnStatement::ReturnStatement() {}

ReturnStatement::~ReturnStatement() {}

void ReturnStatement::execute(ProgramState* state, std::ostream& outf) {
    // Call to grab and pop the last line number from the stack
    state->returnToLine();
}