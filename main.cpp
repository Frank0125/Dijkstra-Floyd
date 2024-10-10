#include "iostream"
#include "dijkstra.cpp"
#include "string"
#include "fstream"
#include "sstream"
#include "vector"

using namespace std;
// g++ -o main main.cpp to create the executable

int main(){
    dijkstra();
    //read a txt file
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
        cout << "Nodes Number: " << nodesNumber << endl;
        inputFile.close();
    }
    else cout << "Unable to open file";

    

    cout << "Lets Code" << endl;
    return 0;
}