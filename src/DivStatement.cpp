#include "DivStatement.h"

DivStatement::~DivStatement() {}

void DivStatement::execute(ProgramState* state, std::ostream& outf) {
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

    // If the denominator is 0, then terminate the program with a few
    // outgoing messages
    if (b == 0) {
        state->endProgram();
        outf << "Divide by zero exception" << std::endl;
        return;
    }

    // Update the variable's value
    state->updateVariables(variableName, math(b));

    // Passing a 0 to the setCounter function increments the Program's
    // line counter by 1
    state->setCounter(0);
}

// Div's implementation of the math function returns a/b
int DivStatement::math(int b) { return a / b; }