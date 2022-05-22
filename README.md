# Homework

Please use this, only as a reference while grading William's HW #2.

## About
HW2 is a simple Interpreter for a very limited version of the well-known programming language BASIC (I totally did not just copy and paste this). The program itself contains a number of statement classes, many of which are inherited of one another, to perform the necessary executions the input requires it to do. 


## Inheritance
There are two major inheritances to point out (other than the given Statement class). In this implementation, all the mathematical operation statements inherit from MathStatement, and all the statements that perform line jumps inherit from the GotoStatement. 


### **Notice!**
This is important to note. At the time of working on the assignment, not much error consideration was put in when making the makefile. Hence, when _make clean_ is called, all the executables and object files will be deleted! Please put this into consideration if anything goes wrong during the grading process. Thank you.