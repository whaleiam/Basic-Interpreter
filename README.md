# Basic Interpreter
Basic Interpreter is a simple C++17 program that simulates an Interpreter for a very limited version of the well-known programming language **BASIC**. The program itself contains a number of statement classes, many of which are inherited from one another, to perform the necessary executions the input requires it to do. 


## About
As mentioned, this is an Interpreter for a very limited version of **BASIC**. Therefore, the only statements that are supported are as follows:
1. Arithmetic Statements - (ADD, SUB, MULT, DIV)
2. Print Statements - (PRINT, PRINTALL)
3. Jump Statements - (GOTO, GOSUB, RETURN)
4. Conditional Statements - (IF)


## Run
In order to run the program, you need at least C++17 `g++` (default) compiler. In addition, while you can use the provided text file, you are welcome to create your own text file with you own custom sequence of **BASIC** instructions and pass that as an argument when runningg the program.
Open a _Terminal_ console in the same directory as the project and do as follows:
```shell
$ make all
$ ./interpreter *your file name here*
```
Run make clean to clean your directory of all object files
