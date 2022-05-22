#include "SubStatement.h"

SubStatement::~SubStatement() {}

// Sub's implementation of the math function returns a-b
int SubStatement::math(int b) { return a - b; }