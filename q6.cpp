#include <iostream>
#include <limits>
#include <vector>

using Vertex = unsigned int;
using Weight = float;

class DigraphMA {
private:
    unsigned int numVertices;
    std::vector<std::vector<Weight>> matriz_adjacencia;

public:
    DigraphMA(unsigned int);
    ~DigraphMA();
    void addAresta(Vertex u, Vertex v, Weight weight);
    void removeAresta(Vertex u, Vertex v);
    unsigned int getNumVertices() const;
    unsigned int getNumArestas() const;
    Weight getWeightAresta(Vertex u, Vertex v) const;
    void printGraph() const;
};

DigraphMA::DigraphMA(unsigned int numVertices) : numVertices(numVertices) {
    matriz_adjacencia = std::vector<std::vector<Weight>>(
        numVertices, std::vector<Weight>(numVertices, std::numeric_limits<Weight>::infinity()));
}

DigraphMA::~DigraphMA() {}

void DigraphMA::addAresta(Vertex u, Vertex v, Weight weight) {
    matriz_adjacencia[u][v] = weight;
}

void DigraphMA::removeAresta(Vertex u, Vertex v) {
    matriz_adjacencia[u][v] = std::numeric_limits<Weight>::infinity();
}

unsigned int DigraphMA::getNumVertices() const {
    return numVertices;
}

unsigned int DigraphMA::getNumArestas() const {
    unsigned int numArestas = 0;
    for (unsigned int i = 0; i < numVertices; ++i) {
        for (unsigned int j = 0; j < numVertices; ++j) {
            if (matriz_adjacencia[i][j] != std::numeric_limits<Weight>::infinity()) {
                ++numArestas;
            }
        }
    }
    return numArestas;
}

Weight DigraphMA::getWeightAresta(Vertex u, Vertex v) const {
    return matriz_adjacencia[u][v];
}

void DigraphMA::printGraph() const {
    for (unsigned int i = 0; i < numVertices; ++i) {
        for (unsigned int j = 0; j < numVertices; ++j) {
            if (matriz_adjacencia[i][j] == std::numeric_limits<Weight>::infinity()) {
                std::cout << "0 ";
            } else {
                std::cout << "1 ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned int numVertices, numArestas;
    std::cin >> numVertices >> numArestas;

    DigraphMA graph(numVertices);

    for (unsigned int i = 0; i < numArestas; ++i) {
        Vertex u, v;
        std::cin >> u >> v;
        graph.addAresta(u, v, 1.0);
    }

    std::cout << "num_vertices: " << graph.getNumVertices() << std::endl;
    std::cout << "num_arestas: " << graph.getNumArestas() << std::endl;

    graph.printGraph();

    return 0;
}
