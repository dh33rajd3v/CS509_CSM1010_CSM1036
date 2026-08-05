#include "../include/parser.h"
#include "../include/bfs.h"
#include "../include/dfs.h"

#include <iostream>

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\nAssignment 1\n";
        cout << "1. Run BFS\n";
        cout << "2. Run DFS\n";
        cout << "3. Run SSSP\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                run_BFS();
                break;

            case 2:
                run_DFS();
                break;

            case 3:
                run_SSSP();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}