// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>

class ProgramState {
public:
    ProgramState(int numLines);

    // You'll need to add a variety of methods here.  Rather than trying to
    // think of what you'll need to add ahead of time, add them as you find
    // that you need them.

    // Function returns the programCounter
    int getCounter() const;

    // Function returns boolean to see whether we hit the end of the
    // program
    bool endOfProgram();

    // Function to either increment the Program counter or provide a Line
    // to jump to
    void setCounter(int line);

    // This function is used to update the map containing the variables
    // (For LET statement)
    void updateVariables(std::string var, int value);

    // Returns the value of the variable
    int getValue(std::string var);

    // Function to print a variable's value to the output stream
    void writeToOutput(std::string var, std::ostream& outf);

    // Function to print every variable along with its associated value
    // to the output stream
    void writeAllToOutput(std::ostream& outf);

    // Called by GoSub Statement to specific line to return to
    void pushToStack(int line);

    // Called by return to return the most recent line pushed into the stack
    void returnToLine();

    // Called by END or . statement to end the program
    void endProgram();

private:
    int m_numLines, programCounter;

    // Map to store all the variables
    std::map<std::string, int> variableTracker;

    // Stack to store all the queued line numbers passed by GOSUB
    std::stack<int> lineTracker;
};

#endif
