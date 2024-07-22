#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Adj_list.hpp"
#include "Vertex.hpp"
#include "utils.hpp"

class Graph {
	public:
		
		int number_of_vertices;
		Adj_list** adjacency_list_vector;

		Graph (int number_of_vertices);

		~Graph();

		void insert_edge (int origin_vertex, int destination_vertex, float weight);

		void insert_portal(Vertex origin_vertex,Vertex destination_vertex);

		void insert_edge (Vertex origin_vertex, Vertex destination_vertex);

		void print_graph();

		Adj_list get_adj(int vertex_index);


		
};










#endif
