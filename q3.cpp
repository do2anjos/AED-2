#include <iostream>
#include <list>
#include <utility>

using namespace std;

using Vertex = unsigned int;
using Weight = float;

struct VertexWeightPair {
    Vertex vertex;  
    Weight weight; 

    VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {}
};

class WeightedGraphLA {
private:
    unsigned int numVertices;
    list<VertexWeightPair>* lista_de_adjacencia;

public:
    WeightedGraphLA(unsigned int);
    ~WeightedGraphLA();
    void addAresta(Vertex, Vertex, Weight);
    void removeAresta(Vertex, Vertex);
    void printGraph();

};

WeightedGraphLA::WeightedGraphLA(unsigned int numVertices) : numVertices(numVertices) {
    lista_de_adjacencia = new list<VertexWeightPair>[numVertices];
}

WeightedGraphLA::~WeightedGraphLA() {
    delete[] lista_de_adjacencia;
}

void WeightedGraphLA::addAresta(Vertex u, Vertex v, Weight weight) {
    lista_de_adjacencia[u].emplace_back(v, weight);
    lista_de_adjacencia[v].emplace_back(u, weight);
}

void WeightedGraphLA::removeAresta(Vertex u, Vertex v) {

}

void WeightedGraphLA::printGraph() {
    for (unsigned int i = 0; i < numVertices; ++i) {
        cout << i << ": ";
        for (const auto& vertexWeightPair : lista_de_adjacencia[i]) {
            cout << "{" << vertexWeightPair.vertex << ", " << vertexWeightPair.weight << "} ";
        }
        cout << endl;
    }
}

int main() {
    unsigned int numVertices, numArestas;
    cin >> numVertices >> numArestas;

    WeightedGraphLA graph(numVertices);

    for (unsigned int i = 0; i < numArestas; ++i) {
        Vertex u, v;
        Weight weight;
        cin >> u >> v >> weight;
        graph.addAresta(u, v, weight);
    }

    cout << "numVertices: " << numVertices << endl;
    cout << "numArestas: " << numArestas << endl;

    graph.printGraph();

    return 0;
}
