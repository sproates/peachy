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

OBJECTS = environment.o filescriptsource.o lexer.o log.o nullostream.o \
parser.o peachy.o peachyparser.o replscriptsource.o runtime.o script.o \
scriptsource.o stringscriptsource.o token.o tokenfactory.o tokensource.o

SOURCE = ./src

TEST_EXE = testpeachy.exe

# main targets

all: $(FINAL_EXE) $(TEST_EXE) test

$(FINAL_EXE): main.o $(OBJECTS)
	$(COMPILER) -o $(FINAL_EXE) main.o $(OBJECTS)

$(TEST_EXE): test.o $(OBJECTS)
	$(COMPILER) -o $(TEST_EXE) test.o $(OBJECTS)

clean:
	$(DELETE) *.exe *.o

rebuild: clean all

test: $(TEST_EXE)
	$(TEST_EXE)

# objects with entry points

main.o: $(SOURCE)/main.cpp $(HEADERS)/environment.h \
$(HEADERS)/filescriptsource.h $(HEADERS)/lexer.h $(HEADERS)/log.h \
$(HEADERS)/parser.h $(HEADERS)/peachy.h $(HEADERS)/peachyparser.h \
$(HEADERS)/replscriptsource.h $(HEADERS)/runtime.h $(HEADERS)/script.h \
$(HEADERS)/scriptsource.h $(HEADERS)/tokenfactory.h $(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/main.cpp

test.o: $(SOURCE)/test.cpp $(HEADERS)/environment.h $(HEADERS)/lexer.h \
$(HEADERS)/log.h $(HEADERS)/nullostream.h $(HEADERS)/parser.h \
$(HEADERS)/peachyparser.h $(HEADERS)/runtime.h $(HEADERS)/script.h \
$(HEADERS)/scriptsource.h $(HEADERS)/stringscriptsource.h $(HEADERS)/token.h \
$(HEADERS)/tokenfactory.h $(HEADERS)/tokensource.h $(HEADERS)/tokentype.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/test.cpp

# intermediary objects

environment.o: $(SOURCE)/environment.cpp $(HEADERS)/environment.h \
$(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/environment.cpp

filescriptsource.o: $(SOURCE)/filescriptsource.cpp \
$(HEADERS)/filescriptsource.h $(HEADERS)/log.h $(HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/filescriptsource.cpp

lexer.o: $(SOURCE)/lexer.cpp $(HEADERS)/lexer.h $(HEADERS)/lexerexception.h \
$(HEADERS)/lexerstate.h $(HEADERS)/log.h $(HEADERS)/scriptsource.h \
$(HEADERS)/token.h $(HEADERS)/tokenfactory.h $(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/lexer.cpp

log.o: $(SOURCE)/log.cpp $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/log.cpp

nullostream.o: $(SOURCE)/nullostream.cpp $(HEADERS)/nullostream.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/nullostream.cpp

parser.o: $(SOURCE)/parser.cpp $(HEADERS)/log.h $(HEADERS)/parser.h \
$(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/parser.cpp

peachy.o: $(SOURCE)/peachy.cpp $(HEADERS)/peachy.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/peachy.cpp

peachyparser.o: $(SOURCE)/peachyparser.cpp $(HEADERS)/lexerexception.h \
$(HEADERS)/log.h $(HEADERS)/parser.h $(HEADERS)/parserexception.h \
$(HEADERS)/parserstate.h $(HEADERS)/peachyparser.h $(HEADERS)/token.h \
$(HEADERS)/tokensource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/peachyparser.cpp

replscriptsource.o: $(SOURCE)/replscriptsource.cpp $(HEADERS)/log.h \
$(HEADERS)/replscriptsource.h $(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/replscriptsource.cpp

runtime.o: $(SOURCE)/runtime.cpp $(HEADERS)/log.h $(HEADERS)/runtime.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/runtime.cpp

script.o: $(SOURCE)/script.cpp $(HEADERS)/environment.h $(HEADERS)/log.h \
$(HEADERS)/parser.h $(HEADERS)/parserexception.h $(HEADERS)/runtime.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/script.cpp

scriptsource.o: $(SOURCE)/scriptsource.cpp $(HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/scriptsource.cpp

stringscriptsource.o: $(SOURCE)/stringscriptsource.cpp $(HEADERS)/log.h \
$(HEADERS)/stringscriptsource.h $(HEADERS)/scriptsource.h $(HEADERS)/log.h
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
