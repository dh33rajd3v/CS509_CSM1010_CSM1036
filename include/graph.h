#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Graph
{
    int vertices;
    int edges;

    vector<vector<int>> adjacencyList;
};

Graph readGraph(
    const string& filename,
    int& source
);

void printGraph(
    const Graph& graph
);

#endif