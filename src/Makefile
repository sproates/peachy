COMPILER = g++
COMPILER_FLAGS = -c -Wall -DLOG_DEBUG_ENABLED
FINAL_EXE = peachy.exe
DELETE = rm
OBJECTS = environment.o filescriptsource.o log.o main.o peachy.o \
          replscriptsource.o runtime.o script.o scriptsource.o \
          stringscriptsource.o
SOURCES = environment.cpp filescriptsource.cpp log.cpp main.cpp peachy.cpp \
          replscriptsource.cpp runtime.cpp script.cpp scriptsource.cpp \
          stringscriptsource.cpp

all: $(FINAL_EXE)

$(FINAL_EXE): $(OBJECTS)
	$(COMPILER) -o $(FINAL_EXE) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(COMPILER) $(COMPILER_FLAGS) -Iheaders $(SOURCES)

clean:
	$(DELETE) *.exe *.o
