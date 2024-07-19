#include <iostream>
#include <new>
#include "../include/Graph.hpp"
#include "../include/Heap.hpp"

void Dijkstra(Graph graph) {

    Heap min_heap = Heap();
    float* distances = new float[graph.number_of_vertices];

    // Vértice inicial:
    min_heap.add(0,0);
    distances[0] = 0;

    // Outros vértices são inicializados com distâncias "infinitas"
    for(int i=1;i<graph.number_of_vertices;i++) {
        min_heap.add(i,999999999999999.0);
        distances[i] = 999999999999999.0;
    }
    std::cout<<"Distancias iniciais: ";
    for(int i=0;i<graph.number_of_vertices;i++) {
        std::cout<<distances[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Distancias inicializadas"<<std::endl;


    for(int i=0;i<min_heap.heap_size;i++){
        int current_vertex = min_heap.items[i].vertex;
        Adj_list current_vertex_adj_list = graph.get_adj(i);
        //Iterar sobre a adj list:
        Edge* temp_edge = current_vertex_adj_list.root_edge;
        Edge* next_edge = current_vertex_adj_list.root_edge;
        current_vertex_adj_list.print();
        while(next_edge != nullptr) {
            temp_edge = next_edge;
            int adjacent_vertex = temp_edge->vertex;
            float adjacent_vertex_weight = temp_edge->weight;
            if(adjacent_vertex_weight+distances[current_vertex] < distances[adjacent_vertex]) {

                distances[adjacent_vertex] = adjacent_vertex_weight + distances[current_vertex];



                std::cout<<"Distancias: ";



                for(int j=0;j<graph.number_of_vertices;j++) {
                    std::cout<<distances[j]<<" ";
                }
                std::cout<<std::endl;
            };
            next_edge = temp_edge->next;
        }

    }

    std::cout<<"Distancias finais: ";
    for(int j=0;j<graph.number_of_vertices;j++) {
        std::cout<<distances[j]<<" ";
    }
    std::cout<<std::endl;
}
