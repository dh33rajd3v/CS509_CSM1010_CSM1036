# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Source files
SRC = driver/graph_driver.cpp \
      src/csr.cpp \
      src/BFS.cpp \
      src/dfs.cpp \
      src/parser.cpp \
      src/sssp.cpp

# Output executable
TARGET = graph

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean generated files
clean:
	rm -f $(TARGET) *.o
