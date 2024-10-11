/*
Algoritmo Floyd para encontrar la distancia más corta entre parejas de nodos en un grafo dirigido. 
 */

#include <iostream>
#include <vector>
#include <fstream> 
using namespace std;

// Algoritmo de Floyd-Warshall
void floydWarshall(vector<vector<int>> &dist, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != -1 && dist[k][j] != -1)
                {
                    int newDist = dist[i][k] + dist[k][j];
                    if (dist[i][j] == -1 || newDist < dist[i][j])
                    {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
    }
}

void printFloyd(vector<vector<int>> &dist, int n)
{
    cout << "Floyd :" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}