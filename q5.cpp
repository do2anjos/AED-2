#include <iostream>
#include <list>
#include <vector>

using Vertex = unsigned int;

class DigraphLA {
private:
  unsigned int numVertices;
  std::vector<std::list<Vertex>> lista_de_adjacencia;

public:
  DigraphLA(unsigned int);
  ~DigraphLA();
  void addAresta(Vertex u, Vertex v);
  void removeAresta(Vertex u, Vertex v);
  unsigned int getNumVertices() const;
  unsigned int getNumArestas() const;
  const std::list<Vertex> &getAdj(Vertex v) const;
};

DigraphLA::DigraphLA(unsigned int numVertices) : numVertices(numVertices) {
  lista_de_adjacencia.resize(numVertices);
}

DigraphLA::~DigraphLA() {
}

void DigraphLA::addAresta(Vertex u, Vertex v) {
  lista_de_adjacencia[u].push_back(v);
}

void DigraphLA::removeAresta(Vertex u, Vertex v) {
  lista_de_adjacencia[u].remove(v);
}

unsigned int DigraphLA::getNumVertices() const {
  return numVertices;
}

unsigned int DigraphLA::getNumArestas() const {
  unsigned int numArestas = 0;
  for (const auto &adjList : lista_de_adjacencia) {
    numArestas += adjList.size();
  }
  return numArestas;
}

const std::list<Vertex> &DigraphLA::getAdj(Vertex v) const {
  return lista_de_adjacencia[v];
}

int main() {
  unsigned int numVertices, numArestas;
  std::cin >> numVertices >> numArestas;

  DigraphLA graph(numVertices);

  for (unsigned int i = 0; i < numArestas; ++i) {
    Vertex u, v;
    std::cin >> u >> v;
    graph.addAresta(u, v);
  }

  std::cout << "num_vertices: " << graph.getNumVertices() << std::endl;
  std::cout << "num_arestas: " << graph.getNumArestas() << std::endl;

  for (Vertex v = 0; v < numVertices; ++v) {
    const std::list<Vertex> &adjList = graph.getAdj(v);
    std::cout << v << ": ";
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
      std::cout << *it;
      if (std::next(it) != adjList.end()) {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
