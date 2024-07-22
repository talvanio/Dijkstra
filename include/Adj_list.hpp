#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP
#include <iostream>
#include <stdlib.h>
#include "Edge.hpp"

class Adj_list {
    public:
        Edge* root_edge;

        Adj_list() {
            this->root_edge = nullptr;
        }

        void insert(int vertex, float weight) {
            Edge* new_edge = new Edge(vertex,weight);
            new_edge->next = root_edge;
            this->root_edge = new_edge;
        };

        int len() {
            int i=0;
            Edge* next_edge = this->root_edge;
            Edge* current_edge = this->root_edge;

            while(next_edge != nullptr) {
                current_edge = next_edge;
                i++;
                next_edge = current_edge->next;
            }
            return i;
        }





        void print() {
            // Inicializando o next_edge como root_edge para evitar problemas em listas de adjacência de tamanho 1.
            Edge* next_edge = this->root_edge;
            
            Edge* actual_edge = this->root_edge;

            if(this->root_edge == nullptr) {
                std::cout<<"Lista de adjacência vazia"<<std::endl;
                return;
            } else {
                while(next_edge != nullptr) {
                    actual_edge = next_edge;
                    std::cout<<" | " << actual_edge->weight<<" "<<actual_edge->vertex<<" | ";
                    next_edge = actual_edge->next;

                }
                std::cout<<std::endl;
            }
        }

};






#endif