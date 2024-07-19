#include <stdio.h>
#include "./include/Graph.hpp"
#include "./include/utils.hpp"


int main() {

    int number_of_vertices,number_of_edges,number_of_portals;


    std::cin>>number_of_vertices>>number_of_edges>>number_of_portals;

    Graph graph = Graph(number_of_vertices);



    Vertex* vertex_array = new Vertex[number_of_vertices];

    for(int i=0;i<number_of_vertices;i++) {
        int x_coordinate,y_coordinate;
        std::cin>>x_coordinate>>y_coordinate;
        vertex_array[i] = Vertex(i,x_coordinate,y_coordinate);
    }


    for(int i=0;i<number_of_edges;i++) {
        int origin_vertex_id,destination_vertex_id;
        std::cin>>origin_vertex_id>>destination_vertex_id;

        graph.insert_edge(vertex_array[origin_vertex_id],vertex_array[destination_vertex_id]);
    }

    for(int i=0;i<number_of_portals;i++) {
        int origin_vertex_id,destination_vertex_id;
        std::cin>>origin_vertex_id>>destination_vertex_id;


        graph.insert_portal(vertex_array[origin_vertex_id],vertex_array[destination_vertex_id]);

    }


    graph.print_graph();
    return 0;

}   