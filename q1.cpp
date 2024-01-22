#include <iostream>
#include <list>

using namespace std;
#define unit unsigned int

struct ItemVertex {
  unit camada;
};

template <typename T> class Graph {
private:
  unit num_vertices;
  unit num_arestas;
  list<T> *adj;

public:
  Graph(unit);
  ~Graph();
  void addAresta(T v, T w);
  void removeAresta(T v, T w);
  void printGraph();
};

template <typename T>
Graph<T>::Graph(unit num_vertices)
    : num_vertices(num_vertices), num_arestas(0) {
  adj = new list<T>[num_vertices];
}

template <typename T> Graph<T>::~Graph() { delete[] adj; }

template <typename T> void Graph<T>::addAresta(T v, T w) {
  adj[v.camada].push_back(w);
  adj[w.camada].push_back(v);
  num_arestas++;
}

template <typename T> void Graph<T>::removeAresta(T v, T w) {
  // Implementation for removing an edge if needed
}

template <typename T> void Graph<T>::printGraph() {
  cout << "num_vertices: " << num_vertices << endl;
  cout << "num_arestas: " << num_arestas << endl;

  for (unit i = 0; i < num_vertices; ++i) {
    cout << i << ": ";
    for (const auto &vertex : adj[i]) {
      cout << vertex.camada << ", ";
    }
    cout << endl;
  }
}

int main() {
  unit num_vertices, num_arestas;
  cin >> num_vertices >> num_arestas;

  Graph<ItemVertex> g(num_vertices);

  for (unit i = 0; i < num_arestas; ++i) {
    unit v_camada, w_camada;
    cin >> v_camada >> w_camada;
    ItemVertex v{v_camada};
    ItemVertex w{w_camada};
    g.addAresta(v, w);
  }

  g.printGraph();

  return 0;
}
