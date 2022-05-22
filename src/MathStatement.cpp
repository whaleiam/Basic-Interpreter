#include "MathStatement.h"

MathStatement::~MathStatement() {}

void MathStatement::execute(ProgramState* state, std::ostream& outf) {
    a = state->getValue(variableName);
    int b;

    // If the second parameter passed is already a number
    // assign it to b
    if (atoi(variableName2.c_str())) {
        b = atoi(variableName2.c_str());
    }
    // Otherwise, find the variable's value
    else {
        b = state->getValue(variableName2);
    }

    // Update the variable's value
    state->updateVariables(variableName, math(b));

    // Passing a 0 to the setCounter function increments the Program's
    // line counter by 1
    state->setCounter(0);
}