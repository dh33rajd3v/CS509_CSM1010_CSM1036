#include <iostream>
#include <cstdlib>

using namespace std;

void run_assignment1()
{
#ifdef _WIN32
    system("cd ..\\Assignment_1 && graph.exe");
#else
    system("cd ../Assignment_1 && ./graph");
#endif
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== CS509 LAB WRAPPER =====\n";
        cout << "1. Assignment 1\n";
        cout << "0. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                run_assignment1();
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