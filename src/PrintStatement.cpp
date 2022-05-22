// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName) : m_variableName(variableName) {}

PrintStatement::~PrintStatement() {}

void PrintStatement::execute(ProgramState* state, std::ostream& outf) {
    // Write out the value of the passed variable
    state->writeToOutput(m_variableName, outf);

    // Passing a 0 to the setCounter function increments the Program's
    // line counter by 1
    state->setCounter(0);
}
