#include <iostream>
#include <new>
#include "../include/Algorithms.hpp"
#include "../include/Graph.hpp"
#include "../include/Heap.hpp"
#include "../include/utils.hpp"

void can_escape_dijkstra(Graph* graph,int max_portals, int energy) {

    Heap min_heap = Heap(graph->number_of_vertices*graph->number_of_vertices);
    float* distances = new float[graph->number_of_vertices];
    int* portals_used = new int[graph->number_of_vertices];
    bool* visited = new bool[graph->number_of_vertices];

    // Vértice inicial:
    min_heap.add(0,0,0);
    distances[0] = 0.0;
    visited[0] = false;
    portals_used[0] = 0;

    // Outros vértices são inicializados com distâncias "infinitas"
    for(int i=1;i<graph->number_of_vertices;i++) {
        distances[i] = 3.402823466e38/4.0;
        visited[i] = false;
        portals_used[i] = 0;
    }

    /*
    std::cout<<"Distancias iniciais: ";
    for(int i   =0;i<graph.number_of_vertices;i++) {
        std::cout<<distances[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Distancias inicializadas"<<std::endl;
    */

    while(!min_heap.is_empty()) {
        // std::cout<< "Tamanho do heap: "<< min_heap.size<<std::endl;
        int current_vertex = min_heap.pop().vertex;
        if(visited[current_vertex] == true) continue;

        Adj_list current_vertex_adj_list = graph->get_adj(current_vertex);

        //Iterar sobre a adj list:
        Edge* temp_edge = current_vertex_adj_list.root_edge;
        Edge* next_edge = current_vertex_adj_list.root_edge;

        while(next_edge != nullptr) {

            temp_edge = next_edge;
            int adjacent_vertex = temp_edge->vertex;
            if(visited[adjacent_vertex]) continue;

            float adjacent_vertex_weight = temp_edge->weight;
            float new_distance = adjacent_vertex_weight + distances[current_vertex];
            int portal_count = portals_used[current_vertex];

            if(new_distance < distances[adjacent_vertex] && new_distance >= 0) {

                distances[adjacent_vertex] = new_distance;

                if(adjacent_vertex_weight==0.0 && portals_used[adjacent_vertex]+1 <= max_portals) {
                    portals_used[adjacent_vertex]++;
                }
                /*
                std::cout<<"Distancias: ";
                for(int j=0;j<graph.number_of_vertices;j++) {
                    std::cout<<distances[j]<<" ";
                }
                std::cout<<std::endl;
                */
            }
            min_heap.add(adjacent_vertex,new_distance,portals_used[adjacent_vertex]);

            new_distance = 0;
            next_edge = temp_edge->next;
        }
        

    }
    if(distances[graph->number_of_vertices-1] <= energy && portals_used[graph->number_of_vertices-1] <= max_portals) std::cout<<1;
    else std::cout<<0;
    /*
    std::cout<<"DDistancias finais: ";
    for(int j=0;j<graph->number_of_vertices;j++) {
        std::cout<<distances[j]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"DUso de Portais:";
    for(int j=0;j<graph->number_of_vertices;j++) {
        std::cout<<portals_used[j]<<" ";
    }
    std::cout<<std::endl;
    */
    delete[] distances;
    delete[] portals_used;
    delete[] visited;


}

// Vertex array é para as localizações euclideanas
void can_escape_a_star(Graph* graph, int max_portals, int energy, Vertex* vertex_array) {

    Heap min_heap = Heap(graph->number_of_vertices*graph->number_of_vertices);
    float* distances = new float[graph->number_of_vertices];
    int* portals_used = new int[graph->number_of_vertices];
    float* priority = new float[graph->number_of_vertices];
    bool* visited = new bool[graph->number_of_vertices];


    // Vértice inicial:
    min_heap.add(0,0,0);
    distances[0] = 0.0;
    visited[0] = false;
    portals_used[0] = 0;
    priority[0] = calculate_distance(vertex_array[0],vertex_array[graph->number_of_vertices-1]);

    // Outros vértices são inicializados com distâncias "infinitas"
    for(int i=1;i<graph->number_of_vertices;i++) {
        distances[i] = 3.402823466e38/4.0;
        visited[i] = false;
        portals_used[i] = 0;
        priority[i] = calculate_distance(vertex_array[i],vertex_array[graph->number_of_vertices-1]);
    }

    /*
    std::cout<<"Distancias iniciais: ";
    for(int i   =0;i<graph.number_of_vertices;i++) {
        std::cout<<distances[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Distancias inicializadas"<<std::endl;
    */

    while(!min_heap.is_empty()) {
        // std::cout<< "Tamanho do heap: "<< min_heap.size<<std::endl;
        /*
        std::cout<<"===="<<std::endl;
        min_heap.print();
        std::cout<<"===="<<std::endl;
        */

        int current_vertex = min_heap.pop().vertex;

        if(visited[current_vertex] == true) continue;
        if (current_vertex == graph->number_of_vertices - 1) break;

        Adj_list current_vertex_adj_list = graph->get_adj(current_vertex);

        //Iterar sobre a adj list:
        Edge* temp_edge = current_vertex_adj_list.root_edge;
        Edge* next_edge = current_vertex_adj_list.root_edge;

        while(next_edge != nullptr) {

            temp_edge = next_edge;
            int adjacent_vertex = temp_edge->vertex;

            if(visited[adjacent_vertex]) continue;
            float adjacent_vertex_weight = temp_edge->weight;

            float new_distance = adjacent_vertex_weight + distances[current_vertex];
            int portal_count = portals_used[current_vertex];

            priority[adjacent_vertex] = priority[adjacent_vertex] + new_distance;

            if(new_distance < distances[adjacent_vertex] && new_distance >= 0) {

                distances[adjacent_vertex] = new_distance;

                if(adjacent_vertex_weight==0.0 && portals_used[adjacent_vertex]+1 <= max_portals) {
                    portals_used[adjacent_vertex]++;
                }
                /*
                std::cout<<"Distancias: ";
                for(int j=0;j<graph.number_of_vertices;j++) {
                    std::cout<<distances[j]<<" ";
                }
                std::cout<<std::endl;
                */
            }
            min_heap.add(adjacent_vertex,priority[adjacent_vertex],portals_used[adjacent_vertex]);

            new_distance = 0;
            next_edge = temp_edge->next;
        }
        

    }
    if(distances[graph->number_of_vertices-1] <= energy && portals_used[graph->number_of_vertices-1] <= max_portals) {
        std::cout<<1;
    } else std::cout<<0;
    /*
    std::cout<<"Distancias finais: ";
    for(int j=0;j<graph->number_of_vertices;j++) {
        std::cout<<distances[j]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Uso de Portais:";
    for(int j=0;j<graph->number_of_vertices;j++) {
        std::cout<<portals_used[j]<<" ";
    }
    std::cout<<std::endl;
    */
    delete[] distances;
    delete[] portals_used;
    delete[] priority;
    delete[] visited;

}
