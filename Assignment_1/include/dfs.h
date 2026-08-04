#ifndef DFS_H
#define DFS_H

#include <vector>

#include "csr.h"

void DFS(const CSRGraph& graph, int source);

void DFSUtil(
    const CSRGraph& graph,
    int u,
    vector<bool>& visited,
    vector<int>& traversal
);

#endif