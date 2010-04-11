.PHONY: all clean rebuild test
.SUFFIXES: .cpp .o

# definitions

COMPILER = g++

COMPILER_FLAGS = -c -Wall -Wextra -Werror -Wunreachable-code -Wredundant-decls \
-Wwrite-strings -Wundef -Wendif-labels -Wcast-qual -pedantic -I$(HEADERS) \
$(DEFINES)

DEFINES =

DELETE = rm -f -v

FINAL_EXE = peachy.exe

HEADERS = ./includes

OBJECTS = additionexpression.o assignmentexpression.o class.o classfactory.o \
environment.o expression.o expressionfactory.o expressionsource.o \
filescriptsource.o function.o int.o intliteralexpression.o interpreter.o \
istreamscriptsource.o lexer.o log.o nullostream.o object.o peachy.o parser.o \
quitexpression.o replscriptsource.o runtime.o scope.o script.o scriptsource.o \
string.o stringliteralexpression.o stringscriptsource.o token.o tokenfactory.o \
tokensource.o variableexpression.o

SOURCE = ./src

TEST_COMPILER_FLAGS = -c -Wall -Wextra -Werror -Wunreachable-code \
-Wredundant-decls -Wwrite-strings -Wundef -Wendif-labels -Wcast-qual -pedantic \
-I$(HEADERS) -I$(TEST_HEADERS) $(DEFINES)

TEST_EXE = testpeachy.exe

TEST_HEADERS = ./tests/includes

TEST_OBJECTS = $(TESTS)/lexersuite.o $(TESTS)/testsuite.o

TEST_SOURCE = ./tests/src

TESTS = ./tests

# main targets

all: $(FINAL_EXE) $(TEST_EXE) test

$(FINAL_EXE): main.o $(OBJECTS)
	@echo Linking $(FINAL_EXE)
	$(COMPILER) -o $(FINAL_EXE) main.o $(OBJECTS)

$(TEST_EXE): $(TESTS)/testmain.o $(TEST_OBJECTS)
	@echo Linking $(TEST_EXE)
	$(COMPILER) -o $(TEST_EXE) $(TESTS)/testmain.o $(TEST_OBJECTS)

clean:
	@echo "Cleaning"
	$(DELETE) *.exe *.o $(TESTS)/*.o

rebuild: clean all

test: $(TEST_EXE)
	@echo "Testing"
	$(TEST_EXE)

# objects with entry points

main.o: $(SOURCE)/main.cpp $(HEADERS)/classfactory.h $(HEADERS)/environment.h \
$(HEADERS)/expression.h $(HEADERS)/expressionfactory.h \
$(HEADERS)/expressionsource.h $(HEADERS)/filescriptsource.h \
$(HEADERS)/interpreter.h $(HEADERS)/lexer.h $(HEADERS)/log.h \
$(HEADERS)/peachy.h $(HEADERS)/parser.h $(HEADERS)/replscriptsource.h \
$(HEADERS)/runtime.h $(HEADERS)/script.h $(HEADERS)/scriptsource.h \
$(HEADERS)/tokenfactory.h $(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/main.cpp

$(TESTS)/testmain.o: $(TEST_SOURCE)/testmain.cpp $(TEST_HEADERS)/lexersuite.h \
$(TEST_HEADERS)/testsuite.h
	$(COMPILER) $(TEST_COMPILER_FLAGS) -o $(TESTS)/testmain.o \
$(TEST_SOURCE)/testmain.cpp

# test intermediary objects

$(TESTS)/lexersuite.o: $(TEST_SOURCE)/lexersuite.cpp \
$(TEST_HEADERS)/lexersuite.h $(TEST_HEADERS)/testsuite.h
	$(COMPILER) $(TEST_COMPILER_FLAGS) -o $(TESTS)/lexersuite.o \
$(TEST_SOURCE)/lexersuite.cpp

$(TESTS)/testsuite.o: $(TEST_SOURCE)/testsuite.cpp $(TEST_HEADERS)/testsuite.h
	$(COMPILER) $(TEST_COMPILER_FLAGS) -o $(TESTS)/testsuite.o \
$(TEST_SOURCE)/testsuite.cpp

# main intermediary objects

additionexpression.o: $(SOURCE)/additionexpression.cpp \
$(HEADERS)/additionexpression.h $(HEADERS)/expression.h \
$(HEADERS)/expressiontype.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/additionexpression.cpp

assignmentexpression.o: $(SOURCE)/assignmentexpression.cpp \
$(HEADERS)/assignmentexpression.h $(HEADERS)/expression.h \
$(HEADERS)/expressiontype.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/assignmentexpression.cpp

class.o: $(SOURCE)/class.cpp $(HEADERS)/class.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/class.cpp

classfactory.o: $(SOURCE)/classfactory.cpp $(HEADERS)/class.h \
$(HEADERS)/classfactory.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/classfactory.cpp

environment.o: $(SOURCE)/environment.cpp $(HEADERS)/environment.h \
$(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/environment.cpp

expression.o: $(SOURCE)/expression.cpp $(HEADERS)/expression.h \
$(HEADERS)/expressiontype.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/expression.cpp

expressionfactory.o: $(SOURCE)/expressionfactory.cpp \
$(HEADERS)/additionexpression.h $(HEADERS)/assignmentexpression.h \
$(HEADERS)/expression.h $(HEADERS)/expressionfactory.h \
$(HEADERS)/intliteralexpression.h $(HEADERS)/log.h $(HEADERS)/quitexpression.h \
$(HEADERS)/variableexpression.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/expressionfactory.cpp

expressionsource.o: $(SOURCE)/expressionsource.cpp $(HEADERS)/expression.h \
$(HEADERS)/expressionfactory.h $(HEADERS)/expressionsource.h $(HEADERS)/log.h \
$(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/expressionsource.cpp

filescriptsource.o: $(SOURCE)/filescriptsource.cpp \
$(HEADERS)/filescriptsource.h $(HEADERS)/istreamscriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/filescriptsource.cpp

function.o: $(SOURCE)/function.cpp $(HEADERS)/function.h \
$(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/function.cpp

int.o: $(SOURCE)/types/int.cpp $(HEADERS)/class.h $(HEADERS)/classfactory.h \
$(HEADERS)/object.h $(HEADERS)/types/int.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/types/int.cpp

interpreter.o: $(SOURCE)/interpreter.cpp $(HEADERS)/additionexpression.h \
$(HEADERS)/assignmentexpression.h $(HEADERS)/class.h $(HEADERS)/classfactory.h \
$(HEADERS)/expressionsource.h $(HEADERS)/expressiontype.h \
$(HEADERS)/interpreter.h $(HEADERS)/interpreterexception.h $(HEADERS)/log.h \
$(HEADERS)/object.h $(HEADERS)/scope.h $(HEADERS)/stringliteralexpression.h \
$(HEADERS)/types/int.h $(HEADERS)/types/string.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/interpreter.cpp

intliteralexpression.o: $(SOURCE)/intliteralexpression.cpp \
$(HEADERS)/expression.h $(HEADERS)/expressiontype.h \
$(HEADERS)/intliteralexpression.h $(HEADERS)/log.h 
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/intliteralexpression.cpp

istreamscriptsource.o: $(SOURCE)/istreamscriptsource.cpp \
$(HEADERS)/istreamscriptsource.h $(HEADERS)/log.h $(HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/istreamscriptsource.cpp

lexer.o: $(SOURCE)/lexer.cpp $(HEADERS)/lexer.h $(HEADERS)/lexerexception.h \
$(HEADERS)/lexerstate.h $(HEADERS)/log.h $(HEADERS)/scriptsource.h \
$(HEADERS)/token.h $(HEADERS)/tokenfactory.h $(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/lexer.cpp

log.o: $(SOURCE)/log.cpp $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/log.cpp

nullostream.o: $(SOURCE)/nullostream.cpp $(HEADERS)/nullostream.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/nullostream.cpp

object.o: $(SOURCE)/object.cpp $(HEADERS)/class.h $(HEADERS)/classfactory.h \
$(HEADERS)/log.h $(HEADERS)/object.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/object.cpp

parser.o: $(SOURCE)/parser.cpp $(HEADERS)/additionexpression.h \
$(HEADERS)/assignmentexpression.h $(HEADERS)/expressionfactory.h \
$(HEADERS)/expressionsource.h $(HEADERS)/intliteralexpression.h \
$(HEADERS)/lexerexception.h $(HEADERS)/log.h $(HEADERS)/parserexception.h \
$(HEADERS)/parserstate.h $(HEADERS)/parser.h $(HEADERS)/quitexpression.h \
$(HEADERS)/stringliteralexpression.h $(HEADERS)/token.h \
$(HEADERS)/tokensource.h $(HEADERS)/tokentype.h $(HEADERS)/variableexpression.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/parser.cpp

peachy.o: $(SOURCE)/peachy.cpp $(HEADERS)/peachy.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/peachy.cpp

quitexpression.o: $(SOURCE)/quitexpression.cpp $(HEADERS)/expression.h \
$(HEADERS)/expressiontype.h $(HEADERS)/log.h $(HEADERS)/quitexpression.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/quitexpression.cpp

replscriptsource.o: $(SOURCE)/replscriptsource.cpp $(HEADERS)/log.h \
$(HEADERS)/replscriptsource.h $(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/replscriptsource.cpp

runtime.o: $(SOURCE)/runtime.cpp $(HEADERS)/log.h $(HEADERS)/runtime.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/runtime.cpp

scope.o: $(SOURCE)/scope.cpp $(HEADERS)/class.h $(HEADERS)/function.h \
$(HEADERS)/log.h $(HEADERS)/object.h $(HEADERS)/scope.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/scope.cpp

script.o: $(SOURCE)/script.cpp $(HEADERS)/environment.h \
$(HEADERS)/interpreter.h $(HEADERS)/interpreterexception.h $(HEADERS)/log.h \
$(HEADERS)/parserexception.h $(HEADERS)/runtime.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/script.cpp

scriptsource.o: $(SOURCE)/scriptsource.cpp $(HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/scriptsource.cpp

string.o: $(SOURCE)/types/string.cpp $(HEADERS)/class.h \
$(HEADERS)/classfactory.h $(HEADERS)/object.h $(HEADERS)/types/string.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/types/string.cpp

stringliteralexpression.o: $(SOURCE)/stringliteralexpression.cpp \
$(HEADERS)/expression.h $(HEADERS)/expressiontype.h $(HEADERS)/log.h \
$(HEADERS)/stringliteralexpression.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/stringliteralexpression.cpp

stringscriptsource.o: $(SOURCE)/stringscriptsource.cpp \
$(HEADERS)/istreamscriptsource.h $(HEADERS)/log.h \
$(HEADERS)/stringscriptsource.h 
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/stringscriptsource.cpp

token.o: $(SOURCE)/token.cpp $(HEADERS)/log.h $(HEADERS)/token.h \
$(HEADERS)/tokentype.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/token.cpp

tokenfactory.o: $(SOURCE)/tokenfactory.cpp $(HEADERS)/token.h \
$(HEADERS)/tokenfactory.h $(HEADERS)/tokentype.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/tokenfactory.cpp

tokensource.o: $(SOURCE)/tokensource.cpp $(HEADERS)/log.h \
$(HEADERS)/scriptsource.h $(HEADERS)/token.h $(HEADERS)/tokenfactory.h \
$(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/tokensource.cpp

variableexpression.o: $(SOURCE)/variableexpression.cpp \
$(HEADERS)/expression.h $(HEADERS)/expressiontype.h $(HEADERS)/log.h \
$(HEADERS)/variableexpression.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/variableexpression.cpp
