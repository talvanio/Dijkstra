#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <stdio.h>
#include <stdlib.h>
#include "adj_list.hpp"

class graph {
	public:
		
		int number_of_vertices=0;
		adj_list** adjacency_list_vector;

		graph (int number_of_vertices) {
			this->number_of_vertices = number_of_vertices;
			for(int i =0;i<number_of_vertices;i++) {
				adjacency_list_vector[i] = new adj_list();
			}
		}
		void insert_edge (int origin_vertex, int destination_vertex, float weight) {
			adjacency_list_vector[origin_vertex]->insert(destination_vertex,weight);			
		}
		
		~graph() {
			for(int i=0;i<this->number_of_vertices;i++) {
				delete[] adjacency_list_vector[i];
			}
			delete[] adjacency_list_vector;
		}
};










#endif
