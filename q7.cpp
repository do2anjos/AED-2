#include <iostream>
#include <list>
#include <vector>

using Vertex = unsigned int;
using Weight = float;

class VertexWeightPair {
public:
    Vertex vertex;
    Weight weight;

    VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {}
};

class WeightedDigraphLA {
private:
    unsigned int numVertices;
    std::vector<std::list<VertexWeightPair>> lista_de_adjacencia;

public:

    WeightedDigraphLA(unsigned int);
    ~WeightedDigraphLA();

    void addAresta(Vertex u, Vertex v, Weight weight);
    void removeAresta(Vertex u, Vertex v);
    unsigned int getNumVertices() const;
    unsigned int getNumArestas() const;

    const std::list<VertexWeightPair>& getAdj(Vertex v) const;
};

WeightedDigraphLA::WeightedDigraphLA(unsigned int numVertices) : numVertices(numVertices) {
    lista_de_adjacencia.resize(numVertices);
}

WeightedDigraphLA::~WeightedDigraphLA() {

}

void WeightedDigraphLA::addAresta(Vertex u, Vertex v, Weight weight) {
    lista_de_adjacencia[u].emplace_back(v, weight);
}

void WeightedDigraphLA::removeAresta(Vertex u, Vertex v) {
    lista_de_adjacencia[u].remove_if([v](const VertexWeightPair& pair) { return pair.vertex == v; });
}

unsigned int WeightedDigraphLA::getNumVertices() const {
    return numVertices;
}

unsigned int WeightedDigraphLA::getNumArestas() const {
    unsigned int numArestas = 0;
    for (const auto& adjList : lista_de_adjacencia) {
        numArestas += adjList.size();
    }
    return numArestas;
}

const std::list<VertexWeightPair>& WeightedDigraphLA::getAdj(Vertex v) const {
    return lista_de_adjacencia[v];
}

int main() {
    unsigned int numVertices, numArestas;
    std::cin >> numVertices >> numArestas;

    WeightedDigraphLA graph(numVertices);

    for (unsigned int i = 0; i < numArestas; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.addAresta(u, v, w);
    }

    std::cout << "num_vertices: " << graph.getNumVertices() << std::endl;
    std::cout << "num_arestas: " << graph.getNumArestas() << std::endl;

    for (Vertex v = 0; v < numVertices; ++v) {
        const std::list<VertexWeightPair>& adjList = graph.getAdj(v);
        std::cout << v << " : ";
        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            std::cout << "(" << it->vertex << ", " << it->weight << ")";
            if (std::next(it) != adjList.end()) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
