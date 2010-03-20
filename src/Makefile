# definitions

COMPILER = g++

COMPILER_FLAGS = -c -Wall

DEFINES = -DLOG_DEBUG_ENABLED -DLOG_INFO_ENABLED

DELETE = rm

FINAL_EXE = peachy.exe

HEADERS = headers

OBJECTS = environment.o filescriptsource.o lexer.o log.o peachy.o \
replscriptsource.o runtime.o script.o scriptsource.o stringscriptsource.o

SOURCES = environment.cpp filescriptsource.cpp lexer.cpp log.cpp peachy.cpp \
replscriptsource.cpp runtime.cpp script.cpp scriptsource.cpp \
stringscriptsource.cpp

TEST_EXE = testpeachy.exe

# main targets

all: $(FINAL_EXE) $(TEST_EXE)

$(FINAL_EXE): $(OBJECTS) main.o
	$(COMPILER) -o $(FINAL_EXE) $(OBJECTS) main.o

$(TEST_EXE): $(OBJECTS) test.o
	$(COMPILER) -o $(TEST_EXE) $(OBJECTS) test.o

clean:
	$(DELETE) *.exe *.o

# objects with entry points

main.o: main.cpp $(HEADERS)/environment.h $(HEADERS)/filescriptsource.h \
$(HEADERS)/scriptsource.h $(HEADERS)/log.h $(HEADERS)/peachy.h \
$(HEADERS)/replscriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) main.cpp

test.o: test.cpp $(HEADERS)/environment.h $(HEADERS)/lexer.h $(HEADERS)/log.h \
$(HEADERS)/runtime.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) test.cpp

# objects

environment.o: environment.cpp $(HEADERS)/environment.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) environment.cpp

filescriptsource.o: filescriptsource.cpp $(HEADERS)/filescriptsource.h \
$(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) filescriptsource.cpp

lexer.o: lexer.cpp $(HEADERS)/lexer.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) lexer.cpp

log.o: log.cpp $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) $(DEFINES) -I$(HEADERS) log.cpp

peachy.o: peachy.cpp $(HEADERS)/peachy.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) peachy.cpp

replscriptsource.o: replscriptsource.cpp $(HEADERS)/replscriptsource.h \
$(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) replscriptsource.cpp

runtime.o: runtime.cpp $(HEADERS)/runtime.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) runtime.cpp

script.o: script.cpp $(HEADERS)/script.h $(HEADERS)/environment.h \
$(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) script.cpp

scriptsource.o: scriptsource.cpp $(HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) scriptsource.cpp

stringscriptsource.o: stringscriptsource.cpp $(HEADERS)/stringscriptsource.h \
$(HEADERS)/scriptsource.h $(HEADERS)/log.h
	$(COMPILER) $(COMPILER_FLAGS) -I$(HEADERS) stringscriptsource.cpp

