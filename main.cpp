
#include "./include/Graph.hpp"
#include "./include/utils.hpp"

int main() {
    Graph my_graph = Graph(5);
    my_graph.insert_edge(0,2,2);
    my_graph.insert_edge(0,4,4);
    my_graph.insert_edge(1,2,6);
    my_graph.insert_edge(4,2,7);
    my_graph.insert_edge(3,4,8);

    my_graph.print_graph();
    return 0;
}