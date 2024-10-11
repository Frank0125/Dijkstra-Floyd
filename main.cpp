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

int main()
{
    ifstream inputFile("input4.txt"); 
    if (!inputFile)
    {
        cerr << "Error: no se pudo abrir el archivo." << endl;
        return 1; 
    }

    int n;
    inputFile >> n; 

    // Leer la matriz de adyacencias
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inputFile >> dist[i][j];
        }
    }

    inputFile.close();

    floydWarshall(dist, n);

    // REsultado de matriz de distancias más cortas
    cout << "Floyd :" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == -1)
                cout << "-1 "; // Si no hay camino, pongo -1
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
