CXX = g++
CPPFLAGS = -Wall -g -I$(LIB_DIR)
EXE_DIR = exe
LIB_DIR = lib
SRC_DIR = src
IMP_HDR = $(LIB_DIR)/Statement.h $(LIB_DIR)/ProgramState.h
MATH_HDR = $(LIB_DIR)/MathStatement.h $(IMP_HDR)
GO_HDR = $(LIB_DIR)/GotoStatement.h $(IMP_HDR)
OBJFILES = $(EXE_DIR)/ProgramState.o $(EXE_DIR)/Statement.o $(EXE_DIR)/LetStatement.o $(EXE_DIR)/PrintStatement.o $(EXE_DIR)/PrintAllStatement.o $(EXE_DIR)/MathStatement.o $(EXE_DIR)/AddStatement.o $(EXE_DIR)/SubStatement.o $(EXE_DIR)/MultStatement.o $(EXE_DIR)/DivStatement.o $(EXE_DIR)/GotoStatement.o $(EXE_DIR)/IfStatement.o $(EXE_DIR)/GoSubStatement.o $(EXE_DIR)/ReturnStatement.o $(EXE_DIR)/EndStatement.o

all: $(EXE_DIR)/.dirstamp interpreter

interpreter: $(SRC_DIR)/Interpreter.cpp $(OBJFILES)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(EXE_DIR)/ProgramState.o: $(SRC_DIR)/ProgramState.cpp $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/Statement.o: $(SRC_DIR)/Statement.cpp $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/LetStatement.o: $(SRC_DIR)/LetStatement.cpp $(LIB_DIR)/LetStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/PrintStatement.o: $(SRC_DIR)/PrintStatement.cpp $(LIB_DIR)/PrintStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/PrintAllStatement.o: $(SRC_DIR)/PrintAllStatement.cpp $(LIB_DIR)/PrintStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/MathStatement.o: $(SRC_DIR)/MathStatement.cpp $(LIB_DIR)/MathStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/AddStatement.o: $(SRC_DIR)/AddStatement.cpp $(LIB_DIR)/AddStatement.h $(MATH_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/SubStatement.o: $(SRC_DIR)/SubStatement.cpp $(LIB_DIR)/SubStatement.h $(MATH_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/MultStatement.o: $(SRC_DIR)/MultStatement.cpp $(LIB_DIR)/MultStatement.h $(MATH_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/DivStatement.o: $(SRC_DIR)/DivStatement.cpp $(LIB_DIR)/DivStatement.h $(MATH_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/GotoStatement.o: $(SRC_DIR)/GotoStatement.cpp $(LIB_DIR)/GotoStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/IfStatement.o: $(SRC_DIR)/IfStatement.cpp $(LIB_DIR)/IfStatement.h $(GO_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/GoSubStatement.o: $(SRC_DIR)/GoSubStatement.cpp $(LIB_DIR)/GoSubStatement.h $(GO_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/ReturnStatement.o: $(SRC_DIR)/ReturnStatement.cpp $(LIB_DIR)/ReturnStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(EXE_DIR)/EndStatement.o: $(SRC_DIR)/EndStatement.cpp $(LIB_DIR)/EndStatement.h $(IMP_HDR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm Interpreter
	rm -rf $(EXE_DIR)

$(EXE_DIR)/.dirstamp:
	mkdir -p $(EXE_DIR)
	touch $(EXE_DIR)/.dirstamp