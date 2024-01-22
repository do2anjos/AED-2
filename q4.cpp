#include <iostream>
#include <limits>
#include <vector>

using Vertex = unsigned int;
using Weight = float;

class WeightedGraphMA {
private:
    unsigned int numVertices;
    std::vector<std::vector<Weight>> matriz_adjacencia;

public:

    WeightedGraphMA(unsigned int);

    ~WeightedGraphMA();

    void addAresta(Vertex u, Vertex v, Weight w);
    void removeAresta(Vertex u, Vertex v);
    unsigned int getNumVertices() const;
    unsigned int getNumArestas() const;
    std::vector<Vertex> getAdj(Vertex v) const;
    Weight getWeightAresta(Vertex u, Vertex v) const;
    void printGraph() const;
};

WeightedGraphMA::WeightedGraphMA(unsigned int numVertices) : numVertices(numVertices) {
    matriz_adjacencia = std::vector<std::vector<Weight>>(
        numVertices, std::vector<Weight>(numVertices, std::numeric_limits<Weight>::infinity()));
}

WeightedGraphMA::~WeightedGraphMA() {

}

void WeightedGraphMA::addAresta(Vertex u, Vertex v, Weight w) {
    matriz_adjacencia[u][v] = w;
    matriz_adjacencia[v][u] = w;
}

void WeightedGraphMA::removeAresta(Vertex u, Vertex v) {
    matriz_adjacencia[u][v] = std::numeric_limits<Weight>::infinity();
    matriz_adjacencia[v][u] = std::numeric_limits<Weight>::infinity();
}

unsigned int WeightedGraphMA::getNumVertices() const {
    return numVertices;
}

unsigned int WeightedGraphMA::getNumArestas() const {
    unsigned int numArestas = 0;
    for (unsigned int i = 0; i < numVertices; ++i) {
        for (unsigned int j = i + 1; j < numVertices; ++j) {
            if (matriz_adjacencia[i][j] != std::numeric_limits<Weight>::infinity()) {
                ++numArestas;
            }
        }
    }
    return numArestas;
}

std::vector<Vertex> WeightedGraphMA::getAdj(Vertex v) const {
    std::vector<Vertex> lista_adjacencia;
    for (unsigned int i = 0; i < numVertices; ++i) {
        if (matriz_adjacencia[v][i] != std::numeric_limits<Weight>::infinity()) {
            lista_adjacencia.push_back(i);
        }
    }
    return lista_adjacencia;
}

Weight WeightedGraphMA::getWeightAresta(Vertex u, Vertex v) const {
    return matriz_adjacencia[u][v];
}

void WeightedGraphMA::printGraph() const {
    for (unsigned int i = 0; i < numVertices; ++i) {
        for (unsigned int j = 0; j < numVertices; ++j) {
            if (matriz_adjacencia[i][j] == std::numeric_limits<Weight>::infinity()) {
                std::cout << "inf ";
            } else {
                std::cout << matriz_adjacencia[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned int numVertices, numArestas;
    std::cin >> numVertices >> numArestas;

    WeightedGraphMA graph(numVertices);

    for (unsigned int i = 0; i < numArestas; ++i) {
        Vertex u, v;
        Weight weight;
        std::cin >> u >> v >> weight;
        graph.addAresta(u, v, weight);
    }

    std::cout << "num_vertices: " << graph.getNumVertices() << std::endl;
    std::cout << "num_arestas: " << graph.getNumArestas() << std::endl;

    graph.printGraph();

    return 0;
}
