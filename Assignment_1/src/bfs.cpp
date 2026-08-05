#include "../include/bfs.h"
#include <chrono>

#include <iostream>
#include <queue>

using namespace std;

void BFS(const CSRGraph& graph, int source)
{
    auto start = chrono::high_resolution_clock::now();
    vector<bool> visited(graph.vertices, false);
    vector<int> distance(graph.vertices, -1);
    vector<int> traversal;
    queue<int> q;

    visited[source] = true;
    distance[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        traversal.push_back(u);

        // Visit all neighbors of u
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++)
        {
            int v = graph.col_idx[i];

            if (!visited[v])
            {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nAlgorithm: BFS\n";
    cout << "Source: " << source << "\n";

    cout << "Traversal: ";
    for (int v : traversal)
        cout << v << " ";
    cout << "\n\n";

    cout << "Distances:\n";
    for (int i = 0; i < graph.vertices; i++)
    {
        cout << i << " ";
        if (distance[i] == -1)
            cout << "INF";
        else
            cout << distance[i];
        cout << '\n';
    }
    cout<<"Execution time: "<<duration<<endl; 
}