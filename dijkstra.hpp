#include "iostream"
#include "vector"

using namespace std;

//Función que calcula el minimo entre dos numeros paramatener estetica en el codigo
int calculateMin(int a, int b) {
    return a < b ? a : b;
}

vector<int> dijkstra(vector<vector<int>> graph, int nodesNumber, int pivotNode) {
    if (pivotNode > nodesNumber || pivotNode < 1) {
        cout << "Error: El nodo de inicio no existe en el grafo" << endl;
        return vector<int>();
    }
    
    //Primero Inicialimos la matriz de distancias donde
    //empezamos con la distancia de un nodo a si mismo siendo 0 y
    // todo lo demas 1000 (representaría infinito)
    vector<int> distances = vector<int>(nodesNumber, 1000);
    distances[pivotNode - 1] = 0;

    //Calculamos la distancia minima
    int min = 1000; //Representa infinito
    
    //Despues creamos la lista de visitados que es del tamaño de los nodos
    //y la inicializamos en 0
    //La posicion 0 corresponde al nodo 1, la posicion 1 al nodo 2, etc
    vector<bool> visited (nodesNumber, false);
    int currentNode = -1;

    for (int i = 0; i < nodesNumber; i++) {
        //Inicializamos el minimo en infinito
        min = 1000;
        for (int j = 0; j < nodesNumber; j++) {
            //Logica implementada de Dijkstra
            // dist[v] = min(dist[v], dist[u] + weight(u, v))
            if (!visited[j] && distances[j] < min) {
                min = distances[j];
                currentNode = j;
            }
        }

        //Marcamos el nodo como visitado
        visited[currentNode] = true;

        //Actualizamos las distancias
        for (int j = 0; j < nodesNumber; j++) {
            //Solamente si hay un arco entre el nodo actual y el nodo 
            if (!visited[j] && graph[currentNode][j] != -1) {
                distances[j] = calculateMin(distances[j], distances[currentNode]+ graph[currentNode][j]);
            }
        }
    }

    return distances;
}

void printDistances(vector<vector<int>>graph, int nodesNumber) {
    for (int i = 0; i < nodesNumber; i++) {
        vector<int> distances = dijkstra(graph, nodesNumber, i+1);
        for (int j = 0; j < nodesNumber; j++) {
            if (i!=j) {
                cout << "Node " << i + 1 << " to node " << j + 1 << " : " << distances[j] << " " << endl;
            }   
        }
        cout << endl;
    }
}