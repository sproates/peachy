COMPILER = g++
COMPILER_FLAGS = -c -Wall -DLOG_DEBUG_ENABLED
FINAL_EXE = peachy.exe
TEST_EXE = testpeachy.exe
DELETE = rm
OBJECTS = environment.o filescriptsource.o lexer.o log.o peachy.o \
          replscriptsource.o runtime.o script.o scriptsource.o \
          stringscriptsource.o
SOURCES = environment.cpp filescriptsource.cpp lexer.cpp log.cpp peachy.cpp \
          replscriptsource.cpp runtime.cpp script.cpp scriptsource.cpp \
          stringscriptsource.cpp

all: $(FINAL_EXE)

tester: $(TEST_EXE)

$(FINAL_EXE): $(OBJECTS) main.o
	$(COMPILER) -o $(FINAL_EXE) $(OBJECTS) main.o

$(TEST_EXE): $(OBJECTS) test.o
	$(COMPILER) -o $(TEST_EXE) $(OBJECTS) test.o

$(OBJECTS): $(SOURCES)
	$(COMPILER) $(COMPILER_FLAGS) -Iheaders $(SOURCES)

main.o: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) -Iheaders main.cpp

test.o: test.cpp
	$(COMPILER) $(COMPILER_FLAGS) -Iheaders test.cpp

clean:
	$(DELETE) *.exe *.o
