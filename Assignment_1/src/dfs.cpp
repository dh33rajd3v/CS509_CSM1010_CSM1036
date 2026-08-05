#include "../include/dfs.h"
#include <chrono>

#include <iostream>

using namespace std;

void DFSUtil(
    const CSRGraph& graph,
    int u,
    vector<bool>& visited,
    vector<int>& traversal)
{
    visited[u] = true;

    traversal.push_back(u);

    for (int i = graph.row_ptr[u];
         i < graph.row_ptr[u + 1];
         i++)
    {
        int v = graph.col_idx[i];

        if (!visited[v])
        {
            DFSUtil(
                graph,
                v,
                visited,
                traversal
            );
        }
    }
}

void DFS(
    const CSRGraph& graph,
    int source)
{
    auto start = chrono::high_resolution_clock::now();
    vector<bool> visited(
        graph.vertices,
        false
    );

    vector<int> traversal;

    DFSUtil(
        graph,
        source,
        visited,
        traversal
    );

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Algorithm: DFS\n";

    cout << "Source: "
         << source
         << "\n";

    cout << "Traversal: ";

    for (int vertex : traversal)
    {
        cout << vertex << " ";
    }

    cout<<"\nExecution time: "<<duration<<endl; 

    cout << endl;
}