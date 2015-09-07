CC = clang++
CFLAGS = -Wall -c -g --std=c++11
LDFLAGS = -lm
MAIN_DIR = src
AVL_DIR = src/AVL_tree
SOURCES = $(AVL_DIR)/avl.cpp $(AVL_DIR)/avl_node.cpp $(MAIN_DIR)/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = exec

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(AVL_DIR)/*.o
	rm $(MAIN_DIR)/*.o
	rm exec
