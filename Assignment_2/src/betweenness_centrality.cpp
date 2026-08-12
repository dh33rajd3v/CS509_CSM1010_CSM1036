#include "../include/betweenness_centrality.h"


void betweennessCentrality()
{
    int source;

    const string directory = "Assignment_2/tests/betweenness_centrality";

    vector<string> files;

    for (const auto& entry : filesystem::directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().filename().string());
        }
    }

    if (files.empty())
    {
        cerr << "No files found in " << directory << endl;
        return;
    }

    sort(files.begin(), files.end());

    cout << "\nSelect a graph file:\n";

    for (size_t i = 0; i < files.size(); ++i)
    {
        cout << i + 1 << ". " << files[i] << '\n';
    }

    int choice;

    cout << "\n\nEnter choice: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(files.size()))
    {
        cerr << "Invalid choice.\n";
        return;
    }

    string selected_file =
        directory + "/" + files[choice - 1];

    CSRGraph graph =
        readGraph(
            selected_file,
            source
        );

    auto start = chrono::high_resolution_clock::now();

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

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << fixed << setprecision(2);

    cout << "Algorithm: Betweenness Centrality" << endl;
    cout << "Vertex Centrality" << endl;

    for (int v = 0; v < graph.vertices; v++)
    {
        cout << v << "      " << CB[v] << endl;
    }

    cout << "\nExecution time: "
     << duration.count()
     << " * 10^-3 ms"
     << endl;
}