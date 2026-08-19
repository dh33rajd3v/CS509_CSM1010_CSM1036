#include "../include/gradient_descent.h"


double evaluateFunction(const vector<double>& c, int degree, double x)
{
    double result = 0.0;

    for (int i = 0; i <= degree; i++)
    {
        result += c[i] * pow(x, i);
    }

    return result;
}


double evaluateDerivative(const vector<double>& c, int degree, double x)
{
    double result = 0.0;

    for (int i = 1; i <= degree; i++)
    {
        result += i * c[i] * pow(x, i - 1);
    }

    return result;
}

void gd_func()
{

    const string directory = "Assignment_3/tests/gd";

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


    ifstream input(selected_file);

    if (!input)
    {
        cerr << "Error: Could not open file\n";
    }

    string keyword;
    int degree;

    input >> keyword >> degree;

    input >> keyword;

    vector<double> coefficients(degree + 1);

    for (int i = 0; i <= degree; i++)
    {
        input >> coefficients[i];
    }

    double x;
    double learning_rate;
    double tolerance;
    int max_iterations;

    input >> keyword >> x;
    input >> keyword >> learning_rate;
    input >> keyword >> tolerance;
    input >> keyword >> max_iterations;

    input.close();

    auto start = chrono::high_resolution_clock::now();

    int iterations = 0;
    bool converged = false;

    while (iterations < max_iterations)
    {
        double gradient =
            evaluateDerivative(coefficients, degree, x);

        if (abs(gradient) <= tolerance)
        {
            converged = true;
            break;
        }

        x = x - learning_rate * gradient;

        iterations++;
    }

    double gradient =
        evaluateDerivative(coefficients, degree, x);

    if (abs(gradient) <= tolerance)
    {
        converged = true;
    }

    double final_value =
        evaluateFunction(coefficients, degree, x);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> execution_time =
        end - start;

    cout << fixed << setprecision(6);

    cout << "Algorithm: Gradient Descent\n";
    cout << "Degree: " << degree << "\n";
    cout << "Final x: " << x << "\n";
    cout << "Final f(x): " << final_value << "\n";
    cout << "Iterations: " << iterations << "\n";
    cout << "Convergence: "
         << (converged ? "true" : "false") << "\n";
    cout << "Execution Time: "
         << execution_time.count() << " ms\n";
}