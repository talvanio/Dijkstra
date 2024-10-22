#include "./../include/Graph.hpp"

Graph::Graph (int number_of_vertices) {

    
    this->number_of_vertices = number_of_vertices;
    adjacency_list_vector = new Adj_list*[number_of_vertices];


    
    for(int i =0;i<number_of_vertices;i++) {
        adjacency_list_vector[i] = new Adj_list();
    }
}

Graph::~Graph() {
    for(int i=0;i<number_of_vertices-1;i++) {
        delete adjacency_list_vector[i];
    }
    delete[] adjacency_list_vector;
}

void Graph::insert_edge (int origin_vertex, int destination_vertex, float weight) {
    if(origin_vertex < number_of_vertices
    && destination_vertex < number_of_vertices) {
        adjacency_list_vector[origin_vertex]->insert(destination_vertex,weight);			
    }
    else {
        std::cout<<"Vértice inválido"<<std::endl;
        std::cout<<"Number of vertices:"<<number_of_vertices<<std::endl;
        std::cout<<"Vertice de origem:"<<origin_vertex<<std::endl;
        std::cout<<"Vertice destino:"<<destination_vertex<<std::endl;

    }
}

void Graph::insert_portal(Vertex origin_vertex,Vertex destination_vertex) {
    insert_edge(origin_vertex.id,destination_vertex.id,0);
}

void Graph::insert_edge (Vertex origin_vertex, Vertex destination_vertex) {
    adjacency_list_vector[origin_vertex.id]->insert(destination_vertex.id,calculate_distance(origin_vertex,destination_vertex));
}

void Graph::print_graph() {
    for (int i = 0; i<this->number_of_vertices;i++) {
        std::cout<<"vertex no "<<i<<" :  ";
        this->adjacency_list_vector[i]->print();
    };
}

Adj_list Graph::get_adj(int vertex_index) {
    if (vertex_index < 0 || vertex_index >= this->number_of_vertices) return Adj_list();


    return *adjacency_list_vector[vertex_index];
}

