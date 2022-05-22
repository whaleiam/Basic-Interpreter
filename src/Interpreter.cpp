// Interpreter.cpp
#include "AddStatement.h"
#include "DivStatement.h"
#include "EndStatement.h"
#include "GoSubStatement.h"
#include "GotoStatement.h"
#include "IfStatement.h"
#include "LetStatement.h"
#include "MultStatement.h"
#include "PrintAllStatement.h"
#include "PrintStatement.h"
#include "ReturnStatement.h"
#include "Statement.h"
#include "SubStatement.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement*>& program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement* parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

int main() {
    cout << "Enter BASIC program file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    interpretProgram(infile, cout);
}

void parseProgram(istream& inf, vector<Statement*>& program) {
    program.push_back(NULL);

    string line;
    while (!inf.eof()) {
        getline(inf, line);
        program.push_back(parseLine(line));
    }
}

Statement* parseLine(string line) {
    Statement* statement;
    istringstream ss(line);
    int currLine;
    string type;

    // Take in the line number first
    ss >> currLine;
    ss >> type;

    if (type == "LET") {
        string var;
        int val;

        ss >> var;
        ss >> val;
        // Note:  Because the project spec states that we can assume the file
        //	  contains a syntactically legal program, we know that
        //	  any line that begins with "LET" will be followed by a space
        //	  and then a variable and then an integer value.
        statement = new LetStatement(var, val);
    }

    // Handles creating a new Print statement
    else if (type == "PRINT") {
        string var;
        ss >> var;

        statement = new PrintStatement(var);
    }

    // Handles creating a new Printall statement
    else if (type == "PRINTALL") {
        statement = new PrintAllStatement();
    }

    // Handles Math statements
    else if ((type == "ADD") || (type == "SUB") || (type == "MULT") || (type == "DIV")) {
        // Read in the first variable
        string var1;
        ss >> var1;

        // Read in the second value as a string
        std::string varString;
        ss >> varString;

        if (type == "ADD") {
            statement = new AddStatement(var1, varString);
        } else if (type == "SUB") {
            statement = new SubStatement(var1, varString);
        } else if (type == "MULT") {
            statement = new MultStatement(var1, varString);
        } else {
            statement = new DivStatement(var1, varString);
        }
    }

    // Handles Goto Statement
    else if (type == "GOTO") {
        int lineNum;
        ss >> lineNum;

        statement = new GotoStatement(lineNum);
    }
    // Handles If Statement
    else if (type == "IF") {
        string var, op, THEN;
        int val, lineNum;
        ss >> var;
        ss >> op;
        ss >> val;
        ss >> THEN;
        ss >> lineNum;

        statement = new IfStatement(var, op, val, lineNum);
    }

    // Handles GoSub Statement
    else if (type == "GOSUB") {
        int lineNum;
        ss >> lineNum;

        statement = new GoSubStatement(lineNum, currLine);
    }

    // Handles Return Statement
    else if (type == "RETURN") {
        statement = new ReturnStatement();
    }

    // The last keyword should be obvious given that the input
    // program will never have a keyword other than the 13 listed
    // Hence, creating a new END statement
    else {
        statement = new EndStatement();
    }

    return statement;
}  // FIN

void interpretProgram(istream& inf, ostream& outf) {
    vector<Statement*> program;
    parseProgram(inf, program);

    // Initialize a variable and assign it the value of the vector's size
    int sizeofVector = program.size();

    // Create a new ProgramState object
    // (the number of lines is also the size of the vector)
    ProgramState* run = new ProgramState(sizeofVector);

    // Loop through the program. This loop checks to see if the Program has reached the end.
    // If it hasn't, we go to a specific statement at index getCounter() which determines
    // which line we are on
    int x;
    while (!run->endOfProgram()) {
        x = run->getCounter() + 1;
        program[x]->execute(run, outf);
    }

    // Clean up
    for (int i = 0; i < sizeofVector; ++i) {
        delete program[i];
    }

    delete run;
}  // FIN