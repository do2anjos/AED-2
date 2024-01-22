#include <iostream>
#include <limits>
#include <vector>

using Vertex = unsigned int;
using Weight = float;
const Weight INF = std::numeric_limits<Weight>::infinity();

class WeightedDigraphMA {
private:
    unsigned int numVertices;
    std::vector<std::vector<Weight>> matriz_adjacencia;

public:
    WeightedDigraphMA(unsigned int);
    ~WeightedDigraphMA();
    void addAresta(Vertex u, Vertex v, Weight weight);
    void removeAresta(Vertex u, Vertex v);
    unsigned int getNumVertices() const;
    unsigned int getNumArestas() const;
    Weight getWeightAresta(Vertex u, Vertex v) const;
    void printGraph() const;
};

WeightedDigraphMA::WeightedDigraphMA(unsigned int numVertices)
    : numVertices(numVertices) {
    matriz_adjacencia.resize(numVertices, std::vector<Weight>(numVertices, INF));
}

WeightedDigraphMA::~WeightedDigraphMA() {

}

void WeightedDigraphMA::addAresta(Vertex u, Vertex v, Weight weight) {
    matriz_adjacencia[u][v] = weight;
    matriz_adjacencia[v][u] = weight;  
}

void WeightedDigraphMA::removeAresta(Vertex u, Vertex v) {
    matriz_adjacencia[u][v] = INF;
    matriz_adjacencia[v][u] = INF;  
}

unsigned int WeightedDigraphMA::getNumVertices() const {
    return numVertices;
}

unsigned int WeightedDigraphMA::getNumArestas() const {
    unsigned int count = 0;
    for (Vertex u = 0; u < numVertices; ++u) {
        for (Vertex v = u + 1; v < numVertices; ++v) { 
            if (matriz_adjacencia[u][v] != INF) {
                ++count;
            }
        }
    }
    return count;
}

Weight WeightedDigraphMA::getWeightAresta(Vertex u, Vertex v) const {
    return matriz_adjacencia[u][v];
}

void WeightedDigraphMA::printGraph() const {
    for (Vertex v = 0; v < numVertices; ++v) {
        for (Vertex u = 0; u < numVertices; ++u) {
            Weight weight = matriz_adjacencia[v][u];
            if (weight == INF) {
                std::cout << "inf ";
            } else {
                std::cout << weight << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    unsigned int numVertices, numArestas;
    std::cin >> numVertices >> numArestas;

    WeightedDigraphMA graph(numVertices);

    for (unsigned int i = 0; i < numArestas; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.addAresta(u, v, w);
    }

    std::cout << "num_vertices: " << graph.getNumVertices() << std::endl;
    std::cout << "num_arestas: " << graph.getNumArestas() << std::endl;

    graph.printGraph();

    return 0;
}
