#include "ProgramState.h"

ProgramState::ProgramState(int numLines) : m_numLines(numLines) { programCounter = 0; }

// Returns the current line when running through the program
int ProgramState::getCounter() const { return programCounter; }

// Function to return a bool to see if we reached the end of the
// program
bool ProgramState::endOfProgram() { return ((m_numLines - 1) == programCounter); }

// Function to either increment the Program counter or provide a Line
// to jump to
void ProgramState::setCounter(int line) {
    // If the parameter passed is a 0, increment the program counter by 1
    if (line == 0) {
        ++programCounter;
    }

    // Exit the program if we go out of bounds
    else if (line > m_numLines) {
        endProgram();
    }

    // Else the program counter jumps to whatever line is specified
    else {
        programCounter = line - 1;
    }
}

// Called if a LET statement is executed or any one
// of the math statements (Add, Sub, Mult, Div)
void ProgramState::updateVariables(std::string var, int value) {
    // Use an iterator block to see if the variable is already in the map
    std::map<std::string, int>::iterator it;
    it = variableTracker.find(var);

    // If the variable is found, then update its stored value
    // else insert the new variable into the map
    if (it != variableTracker.end()) {
        it->second = value;
    } else {
        variableTracker.insert(std::pair<std::string, int>(var, value));
    }
}  // FIN

// Returns the value of a given variable name
int ProgramState::getValue(std::string var) {
    // Use an iterator block to find the variable
    std::map<std::string, int>::iterator it;
    it = variableTracker.find(var);

    // If the variable is found, then return its stored value
    // else assign it the value of 0
    if (it != variableTracker.end()) {
        return it->second;
    }

    return 0;
}  // FIN

// Function to print a variable's value to the output stream
void ProgramState::writeToOutput(std::string var, std::ostream& outf) { outf << getValue(var) << std::endl; }  // FIN

// Function to print every variable along with its associated value
// to the output stream
void ProgramState::writeAllToOutput(std::ostream& outf) {
    // Use an iterator block to iterate through every variable stored in the map
    std::map<std::string, int>::iterator it;
    it = variableTracker.begin();

    // Loop to iterate through every item in the map and print out
    // the variable as well as its value
    while (it != variableTracker.end()) {
        outf << it->first << " ";
        writeToOutput(it->first, outf);

        // increment the iterator
        ++it;
    }
}  // FIN

// Called by GoSub Statement to record a specific line to return to
void ProgramState::pushToStack(int line) { lineTracker.push(line); }  // FIN

// Called by return to return the most recent line pushed into the stack
void ProgramState::returnToLine() {
    // Grab the line number from the top of the stack
    programCounter = lineTracker.top();
    // Remove the last line number from the stack
    lineTracker.pop();
}  // FIN

// Called by END or . statement to end the program
void ProgramState::endProgram() { programCounter = m_numLines - 1; }  // FIN