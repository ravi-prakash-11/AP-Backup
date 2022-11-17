#include<bits/stdc++.h>
using namespace std;


int minDistance(int dist[], bool ShortestPathSet[])
{
 
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < 9; v++)
        if (ShortestPathSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void printSolution(int dist[], int src)
{
    
    cout <<"\nMinimum cost to all Vertices"<<endl;
    cout<<"Source Vertex: "<<src<<"\n\n";
    for (int i = 0; i < 9; i++)
    {
        if(i==src)continue;
        cout <<src<<" to "<<i<<" -> "<< dist[i] << endl;
    }
    cout<<"\n\n";
}


void dijkstra(int graph[9][9], int src)
{
    int shortestdist[9];
    bool visited[9];

    for(int i=0; i<9; i++)
    {
        shortestdist[i]=INT_MAX;
        visited[i]=false;
    }

    shortestdist[src] = 0;

    for(int it=0; it<8; it++)
    {   
        int u = minDistance(shortestdist,visited);
        visited[u] = true;

        for (int v = 0; v < 9; v++)

            if (!visited[v] 
                && graph[u][v] 
                && shortestdist[u] != INT_MAX 
                && shortestdist[u] + graph[u][v] < shortestdist[v])
                shortestdist[v] = shortestdist[u] + graph[u][v];
    }



    printSolution(shortestdist,src);
}
 
main()
{
    system("cls");
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    cout<<"\n\t\t\t\t\t   Adjacency Matrix:\n\n\t\033[1;34mSource\t\t\033[1;35m   ->\t\t\t\033[1;31mDestination\n\n\n\t\t";
    for(int i=0; i<9; i++)
        cout<<" \033[1;31m\t"<<i;
    cout<<"\n";
    for (int i = 0; i < 9; i++)
    {
        cout<<"\n\n\t\033[34m"<<i<<"\033[1;35m   ->\t";
        for (int j = 0; j < 9; j++)
        {
            cout<<"\t\033[0;37m"<<graph[i][j];
        }
    }
    cout<<"\n\n\n\033[0m";

    for(int src=0; src<9; src++)
    dijkstra(graph, src);
}