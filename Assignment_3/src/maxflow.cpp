#include "../include/maxflow.h"

struct FlowEdge
{
    int to;
    long long capacity;
    int rev;
};


class Dinic
{
private:

    int V;

    vector<vector<FlowEdge>> graph;

    vector<int> level;
    vector<int> ptr;


    bool bfs(int source, int sink)
    {
        fill(level.begin(), level.end(), -1);

        queue<int> q;

        level[source] = 0;
        q.push(source);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (const FlowEdge& edge : graph[u])
            {
                if (edge.capacity > 0 &&
                    level[edge.to] == -1)
                {
                    level[edge.to] = level[u] + 1;
                    q.push(edge.to);
                }
            }
        }

        return level[sink] != -1;
    }


    long long dfs(
        int u,
        int sink,
        long long flow)
    {
        if (u == sink)
            return flow;

        for (int& i = ptr[u];
             i < (int)graph[u].size();
             i++)
        {
            FlowEdge& edge = graph[u][i];

            if (edge.capacity <= 0)
                continue;

            if (level[edge.to] != level[u] + 1)
                continue;

            long long pushed = dfs(
                edge.to,
                sink,
                min(flow, edge.capacity)
            );

            if (pushed > 0)
            {
                edge.capacity -= pushed;

                graph[edge.to][edge.rev].capacity += pushed;

                return pushed;
            }
        }

        return 0;
    }


public:

    Dinic(int vertices)
    {
        V = vertices;

        graph.resize(V);
        level.resize(V);
        ptr.resize(V);
    }

    void addEdge(
        int u,
        int v,
        long long capacity)
    {
        FlowEdge forward = {
            v,
            capacity,
            (int)graph[v].size()
        };

        FlowEdge backward = {
            u,
            0,
            (int)graph[u].size()
        };

        graph[u].push_back(forward);
        graph[v].push_back(backward);
    }


    long long maxFlow(
        int source,
        int sink)
    {
        long long flow = 0;

        while (bfs(source, sink))
        {
            fill(ptr.begin(), ptr.end(), 0);

            while (true)
            {
                long long pushed = dfs(
                    source,
                    sink,
                    LLONG_MAX
                );

                if (pushed == 0)
                    break;

                flow += pushed;
            }
        }

        return flow;
    }


    vector<bool> reachableFromSource(int source)
    {
        vector<bool> visited(V, false);

        queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (const FlowEdge& edge : graph[u])
            {
                if (edge.capacity > 0 &&
                    !visited[edge.to])
                {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }

        return visited;
    }
};


void maxflowMincut(
    const CSRGraph_withWeight& graph,
    int source,
    int sink)
{
    int V = graph.vertices;


    Dinic dinic(V);

    for (int u = 0; u < V; u++)
    {
        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            int v = graph.col_idx[i];

            long long capacity =
                graph.values[i];

            dinic.addEdge(
                u,
                v,
                capacity
            );
        }
    }


    long long maximumFlow =
        dinic.maxFlow(source, sink);


    vector<bool> sourceSide =
        dinic.reachableFromSource(source);


    struct CutEdge
    {
        int u;
        int v;
        long long capacity;
    };

    vector<CutEdge> cutEdges;

    long long minimumCutCapacity = 0;


    for (int u = 0; u < V; u++)
    {
        if (!sourceSide[u])
            continue;

        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            int v = graph.col_idx[i];

            long long capacity =
                graph.values[i];


            if (!sourceSide[v])
            {
                cutEdges.push_back({
                    u,
                    v,
                    capacity
                });

                minimumCutCapacity += capacity;
            }
        }
    }


    cout << "Algorithm: Maxflow-Mincut\n";

    cout << "Source: " << source << '\n';

    cout << "Sink: " << sink << '\n';

    cout << "Maximum flow: " << maximumFlow << '\n';

    cout << "Minimum cut capacity: " << minimumCutCapacity << '\n';

    cout << "Source side: ";

    for (int i = 0; i < V; i++)
    {
        if (sourceSide[i])
            cout << i << " ";
    }

    cout << '\n';


    cout << "Sink side: ";

    for (int i = 0; i < V; i++)
    {
        if (!sourceSide[i])
            cout << i << " ";
    }

    cout << '\n';


    cout << "Cut edges:\n";

    for (const CutEdge& edge : cutEdges)
    {
        cout << edge.u << " "
             << edge.v << " "
             << edge.capacity
             << '\n';
    }
}

int readSink(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cerr << "Unable to open file.\n";
        exit(1);
    }

    string line;
    string lastLine;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            lastLine = line;
        }
    }

    file.close();

    string label;
    int sink;

    stringstream ss(lastLine);

    if (!(ss >> label >> sink))
    {
        cerr << "Invalid last line in file.\n";
        exit(1);
    }

    if (label != "SINK")
    {
        cerr << "SINK line not found at end of file.\n";
        exit(1);
    }

    return sink;
}


void mm_fn(){

    int source;

    const string directory = "Assignment_3/tests/minmax";

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


    CSRGraph_withWeight graph =
        readGraph_withWeight(
            selected_file,
            source
        );

    int sink = readSink(selected_file);

    auto start = chrono::high_resolution_clock::now();
    
    maxflowMincut(
        graph,
        source,
        sink
    );

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> execution_time =
        end - start;

    cout << "Execution Time: "
         << execution_time.count() << " ms\n";
    
}