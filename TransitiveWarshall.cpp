#include <bits/stdc++.h>
using namespace std;

#define V 6

void printSolution(int reach[V][V]);
void transitiveClosure(int graph[V][V])
{
    int reach[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }
    printSolution(reach);
}

void printSolution(int reach[V][V])
{
    cout << "\n\n\t\t\tTransitive Closure Matrix\n\n\t\t";
    for (int i = 0; i < V; i++)
        cout << " \033[1;31m\t" << i;
    cout << "\n";

    for (int i = 0; i < V; i++)
    {
        cout << "\n\n\t\033[34m" << i << "\033[1;35m   ->\t\033[0;37m";
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                cout << "\t1";
            else
                cout << "\t" << reach[i][j];
        }
    }
    cout << "\n\n\n\033[0m";
}

int main()
{

    int graph[V][V] = {{1, 0, 0, 0, 1, 1},
                       {0, 1, 0, 1, 1, 0},
                       {0, 0, 1, 1, 0, 1},
                       {0, 1, 1, 1, 0, 0},
                       {1, 0, 0, 0, 1, 0},
                       {1, 0, 0, 0, 0, 1}};

    transitiveClosure(graph);
    return 0;
}