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

CSRGraph readGraph(
    const string& filename,
    int& source
);

void printCSR(
    const CSRGraph& graph
);

#endif