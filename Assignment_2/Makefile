CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = assignment2

INCLUDES = -Iinclude -I../Assignment_1/include

SOURCES = \
	driver/main.cpp \
	src/triangle_counting.cpp \
	src/betweenness_centrality.cpp \
	src/connected_components.cpp

OBJECTS = \
	driver/main.o \
	src/triangle_counting.o \
	src/betweenness_centrality.o \
	src/connected_components.o \
	build/csr.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

driver/main.o: driver/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

src/triangle_counting.o: src/triangle_counting.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

src/betweenness_centrality.o: src/betweenness_centrality.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

src/connected_components.o: src/connected_components.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

build/csr.o: ../Assignment_1/src/csr.cpp
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q driver\main.o src\triangle_counting.o src\betweenness_centrality.o src\connected_components.o build\csr.o assignment2.exe 2>nul || exit 0