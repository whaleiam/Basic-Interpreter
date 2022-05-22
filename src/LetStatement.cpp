// LetStatement.cpp:
#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(std::string variableName, int value) : m_variableName(variableName), m_value(value) {}

LetStatement::~LetStatement() {}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState* state, ostream& outf) {
    // Update the variable's value
    state->updateVariables(m_variableName, m_value);

    // Passing a 0 to the setCounter function increments the Program's
    // line counter by 1
    state->setCounter(0);
}
