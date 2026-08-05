#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> row_ptr;
    vector<int> col_idx;
};

struct CSRGraph_withWeight
{
    int vertices;
    int edges;

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

CSRGraph readGraph(
    const string& filename,
    int& source
);

CSRGraph_withWeight readGraph_withWeight(
    const string& filename,
    int& source
);

void printCSR(
    const CSRGraph& graph
);

void printCSR_withWeight(
    const CSRGraph_withWeight& graph
);

#endif