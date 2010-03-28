COMPILER = g++
COMPILER_FLAGS = -c -Wall -Wextra -pedantic -I$(HEADERS) -I$(PEACHY_HEADERS)
DELETE = rm -f -v
EXE = testpeachy.exe
HEADERS = ./includes
OBJECTS = main.o mockscriptsource.o
PEACHY = ../src
PEACHY_HEADERS = ../includes
PEACHY_OBJECTS = $(PEACHY)/log.o $(PEACHY)/scriptsource.o
SOURCE = ./src

all: $(EXE)

$(EXE): $(OBJECTS)
	$(COMPILER) -o $@ $(OBJECTS) $(PEACHY_OBJECTS)

main.o: main.cpp $(HEADERS)/mockscriptsource.h $(PEACHY_HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) main.cpp

mockscriptsource.o: $(SOURCE)/mockscriptsource.cpp \
                    $(HEADERS)/mockscriptsource.h \
                    $(PEACHY_HEADERS)/scriptsource.h
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/mockscriptsource.cpp

clean:
	$(DELETE) *.exe *.o
