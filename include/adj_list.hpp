#include <stdlib.h>
#include "edge.hpp"

#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP

class adj_list {
    edge* root_edge;
    public:
        adj_list() {
            edge* root_edge = nullptr;
        }
        void insert(int vertex, float weight) {
            if (this->root_edge == nullptr) {
                edge edge_to_insert(vertex,weight);
                root_edge = &edge_to_insert;
            }
            else {
                edge edge_to_insert(vertex,weight);
                edge_to_insert.next = this->root_edge;
                this->root_edge = &edge_to_insert;
            }

        };
        ~adj_list() {
            edge* actual_edge = root_edge;
            while(actual_edge != nullptr) {
                edge* next_edge = actual_edge->next;
                delete(actual_edge);
                actual_edge = next_edge;
            }
            root_edge = nullptr;
        };

};






#endif