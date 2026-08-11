#include "../include/betweenness_centrality.h"


void betweennessCentrality()
{
    int source;
    CSRGraph graph =
        readGraph(
            "tests/betweenness_centrality/bc_5.txt",
            source
        );

    int V = graph.vertices;

    vector<double> CB(V, 0.0);

    for (int s = 0; s < V; s++)
    {
        stack<int> S;

        vector<vector<int>> pred(V);

        vector<int> dist(V, -1);

        vector<double> sigma(V, 0.0);

        vector<double> delta(V, 0.0);

        queue<int> Q;

        dist[s] = 0;
        sigma[s] = 1.0;

        Q.push(s);


        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            S.push(v);

            for (int i = graph.row_ptr[v];
                 i < graph.row_ptr[v + 1];
                 i++)
            {
                int w = graph.col_idx[i];

                if (dist[w] == -1)
                {
                    dist[w] = dist[v] + 1;
                    Q.push(w);
                }

                if (dist[w] == dist[v] + 1)
                {
                    sigma[w] += sigma[v];
                    pred[w].push_back(v);
                }
            }
        }


        while (!S.empty())
        {
            int w = S.top();
            S.pop();

            for (int v : pred[w])
            {
                delta[v] +=
                    (sigma[v] / sigma[w]) *
                    (1.0 + delta[w]);
            }

            if (w != s)
            {
                CB[w] += delta[w];
            }
        }
    }


    for (int v = 0; v < V; v++)
    {
        CB[v] /= 2.0;
    }

    cout << fixed << setprecision(2);

    cout << "Algorithm: Betweenness Centrality" << endl;
    cout << "Vertex Centrality" << endl;

    for (int v = 0; v < graph.vertices; v++)
    {
        cout << v << "      " << CB[v] << endl;
    }
}