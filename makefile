CC = clang++
CFLAGS = -Wall -c -g --std=c++11
LDFLAGS = -lm
DIR = src
SOURCES = $(DIR)/AVL_tree/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = exec

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm exec
