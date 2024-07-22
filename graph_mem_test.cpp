#include "./include/Graph.hpp"

int main() {
    Graph graph = Graph(8);
    Vertex vertex = Vertex(1,20,40);
    Vertex vertex2 = Vertex(5,10,15);
    graph.insert_edge(vertex,vertex2);
    return 0;
}