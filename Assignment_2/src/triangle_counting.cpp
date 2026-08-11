#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "csr.h"

using namespace std;


void run_triangle()
{
    int source;

    CSRGraph graph =
        readGraph(
            "tests/triangle_counting/triangle.txt",
            source
        );

    auto start = chrono::high_resolution_clock::now();

    vector<tuple<int, int, int>> triangles_found;

    for (int u = 0; u < graph.vertices; u++)
    {
        for (int i = graph.row_ptr[u];
             i < graph.row_ptr[u + 1];
             i++)
        {
            int v = graph.col_idx[i];

            for (int j = i + 1;
                 j < graph.row_ptr[u + 1];
                 j++)
            {
                int w = graph.col_idx[j];

                for (int k = graph.row_ptr[v];
                     k < graph.row_ptr[v + 1];
                     k++)
                {
                    if (graph.col_idx[k] == w)
                    {
                        vector<int> points = {u, v, w};

                        sort(points.begin(), points.end());

                        triangles_found.push_back(
                            make_tuple(
                                points[0],
                                points[1],
                                points[2]
                            )
                        );
                        break;
                    }
                }
            }
        }
    }

    sort(triangles_found.begin(), triangles_found.end());

    triangles_found.erase(
        unique(triangles_found.begin(), triangles_found.end()),
        triangles_found.end()
    );

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Algorithm: Triangle Counting" << endl;
    cout << "Total triangles: "
         << triangles_found.size()
         << endl;

    cout << "Triangles found:" << endl;

    for (const auto& points : triangles_found)
    {
        int a, b, c;

        tie(a, b, c) = points;

        cout << "("
             << a << ", "
             << b << ", "
             << c << ")"
             << endl;
    }
    cout<<"\nExecution time: "<<duration.count()<<endl; 
}
