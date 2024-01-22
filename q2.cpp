#include <iostream>
#include <vector>

using namespace std;

#define Vertex unsigned int
#define Weight float

class GraphMA {
private:
    unsigned int num_vertices;
    vector<vector<bool>> matriz_adjacencia;

public:
    GraphMA(unsigned int);
    ~GraphMA();
    void addAresta(Vertex, Vertex);
    void removeAresta(Vertex, Vertex);
    void printGraph();

};

GraphMA::GraphMA(unsigned int num_vertices) : num_vertices(num_vertices) {
    matriz_adjacencia.resize(num_vertices, vector<bool>(num_vertices, false));
}

GraphMA::~GraphMA() {

}

void GraphMA::addAresta(Vertex v, Vertex w) {

    matriz_adjacencia[v][w] = true;
    matriz_adjacencia[w][v] = true;
}

void GraphMA::removeAresta(Vertex v, Vertex w) {

    matriz_adjacencia[v][w] = false;
    matriz_adjacencia[w][v] = false;
}

void GraphMA::printGraph() {

    for (unsigned int i = 0; i < num_vertices; ++i) {
        for (unsigned int j = 0; j < num_vertices; ++j) {
            cout << matriz_adjacencia[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned int num_vertices, num_arestas;
    cin >> num_vertices >> num_arestas;

    cout << "num_vertices: " << num_vertices << endl;
    cout << "num_arestas: " << num_arestas << endl;

    GraphMA g(num_vertices);

    for (unsigned int i = 0; i < num_arestas; ++i) {
        Vertex v, w;
        cin >> v >> w;
        g.addAresta(v, w);
    }

    g.printGraph();

    return 0;
}
