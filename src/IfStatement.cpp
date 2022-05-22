#include "IfStatement.h"

IfStatement::IfStatement(std::string var1, std::string operation, int b, int line) : GotoStatement(line) {
    var = var1;
    num2 = b;
    compOp = comparisonOperator(operation);
}

// Overwrite the execute function
void IfStatement::execute(ProgramState* state, std::ostream& outf) {
    // Obtain the value of var
    num1 = state->getValue(var);

    // If the statement comes out to be true, we can call the
    // jump function
    if (conditionTrue()) {
        GotoStatement::execute(state, outf);
    }
    // If the statement is false, just increment the program
    else {
        state->setCounter(0);
    }
}

// Assign an int value to compOp which well help determine which
// operation to use
int IfStatement::comparisonOperator(std::string op) {
    if (op == ">") {
        return 1;
    } else if (op == "<") {
        return 2;
    } else if (op == "=") {
        return 3;
    } else if (op == ">=") {
        return 4;
    } else if (op == "<=") {
        return 5;
    } else if (op == "<>") {
        return 6;
    }

    return 0;
}

// Evaluate the statement now that we know which operator to use
bool IfStatement::conditionTrue() {
    switch (compOp) {
    case 1:
        return (num1 > num2);

    case 2:
        return (num1 < num2);

    case 3:
        return (num1 == num2);

    case 4:
        return (num1 >= num2);

    case 5:
        return (num1 <= num2);

    case 6:
        return (num1 != num2);
    }
    return false;
}