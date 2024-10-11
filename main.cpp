#include "iostream"
#include "dijkstra.hpp"
#include "string"
#include "fstream"
#include "sstream"


using namespace std;
// g++ -o main main.cpp para crear el exe

int main(){
    // Lógica para leer el archivo de entrada y convertirlo en una matriz
    string line;
    int nodesNumber = 0;
    vector<vector<int>> graph;
    ifstream inputFile ("input.txt");

    if (inputFile.is_open())
    {
        getline(inputFile, line);
        stringstream ss(line);
        if (!(ss >> nodesNumber)) {
            cout << "Error: No se pudo convertir el número de nodos. Línea leída: " << line << endl;
            return 1;
        }

        for (int i = 0; i < nodesNumber; i++) {
            vector<int> row;
            getline(inputFile, line);
            stringstream ss(line);
            int value;
            while (ss >> value) {
                row.push_back(value);
            }
            graph.push_back(row);
        }
        inputFile.close();
    }
    else cout << "Unable to open file";

    for (int i = 0; i < nodesNumber; i++) {
        for (int j = 0; j < nodesNumber; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Salida:" << endl;

    //Dijsktra
    printDistances(graph, nodesNumber);

    return 0;
}