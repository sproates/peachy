# definitions

COMPILER = g++

COMPILER_FLAGS = -c -Wall -Wextra -pedantic -I$(HEADERS) $(DEFINES)

DEFINES =

DELETE = rm -f -v

FINAL_EXE = peachy.exe

HEADERS = headers

OBJECTS = environment.o filescriptsource.o lexer.o log.o parser.o peachy.o \
peachyparser.o replscriptsource.o runtime.o script.o scriptsource.o \
stringscriptsource.o token.o tokensource.o

TEST_EXE = testpeachy.exe

# main targets

all: $(FINAL_EXE) $(TEST_EXE)

$(FINAL_EXE): $(OBJECTS) main.o
	$(COMPILER) -o $(FINAL_EXE) main.o $(OBJECTS)

$(TEST_EXE): $(OBJECTS) test.o
	$(COMPILER) -o $(TEST_EXE) test.o $(OBJECTS)

clean:
	$(DELETE) *.exe *.o

# general object target

.cpp.o:
	$(COMPILER) $(COMPILER_FLAGS) $<

# objects with entry points

main.o: main.cpp $(HEADERS)/environment.h $(HEADERS)/filescriptsource.h \
$(HEADERS)/lexer.h $(HEADERS)/log.h $(HEADERS)/parser.h $(HEADERS)/peachy.h \
$(HEADERS)/peachyparser.h $(HEADERS)/replscriptsource.h $(HEADERS)/runtime.h \
$(HEADERS)/script.h $(HEADERS)/scriptsource.h $(HEADERS)/tokensource.h

test.o: test.cpp $(HEADERS)/environment.h $(HEADERS)/lexer.h $(HEADERS)/log.h \
$(HEADERS)/parser.h $(HEADERS)/peachyparser.h $(HEADERS)/runtime.h \
$(HEADERS)/script.h $(HEADERS)/scriptsource.h $(HEADERS)/stringscriptsource.h \
$(HEADERS)/token.h $(HEADERS)/tokensource.h $(HEADERS)/tokentype.h

# intermediary objects

environment.o: environment.cpp $(HEADERS)/environment.h $(HEADERS)/log.h

filescriptsource.o: filescriptsource.cpp $(HEADERS)/filescriptsource.h \
$(HEADERS)/log.h $(HEADERS)/scriptsource.h

lexer.o: lexer.cpp $(HEADERS)/lexer.h $(HEADERS)/lexerstate.h $(HEADERS)/log.h \
$(HEADERS)/scriptsource.h $(HEADERS)/token.h $(HEADERS)/tokensource.h

log.o: log.cpp $(HEADERS)/log.h

parser.o: parser.cpp $(HEADERS)/log.h $(HEADERS)/parser.h \
$(HEADERS)/tokensource.h

peachy.o: peachy.cpp $(HEADERS)/peachy.h

peachyparser.o: peachyparser.cpp $(HEADERS)/log.h $(HEADERS)/parser.h \
$(HEADERS)/peachyparser.h $(HEADERS)/token.h $(HEADERS)/tokensource.h

replscriptsource.o: replscriptsource.cpp $(HEADERS)/log.h \
$(HEADERS)/replscriptsource.h $(HEADERS)/scriptsource.h $(HEADERS)/log.h

runtime.o: runtime.cpp $(HEADERS)/log.h $(HEADERS)/runtime.h

script.o: script.cpp $(HEADERS)/environment.h $(HEADERS)/log.h \
$(HEADERS)/parser.h $(HEADERS)/runtime.h

scriptsource.o: scriptsource.cpp $(HEADERS)/scriptsource.h

stringscriptsource.o: stringscriptsource.cpp $(HEADERS)/log.h \
$(HEADERS)/stringscriptsource.h $(HEADERS)/scriptsource.h $(HEADERS)/log.h

token.o: token.cpp $(HEADERS)/log.h $(HEADERS)/token.h $(HEADERS)/tokentype.h

tokensource.o: tokensource.cpp $(HEADERS)/log.h $(HEADERS)/scriptsource.h \
$(HEADERS)/token.h $(HEADERS)/tokensource.h
