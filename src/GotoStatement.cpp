#include "GotoStatement.h"

GotoStatement::GotoStatement(int line) : lineToJump(line) {}

GotoStatement::~GotoStatement() {}

void GotoStatement::execute(ProgramState* state, std::ostream& outf) {
    // Call jump
    jump(state);
}

void GotoStatement::jump(ProgramState* state) {
    // Sets the program counter to whatever line it has to jump to
    state->setCounter(lineToJump);
}