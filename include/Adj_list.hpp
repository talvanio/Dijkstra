#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP
#include <iostream>
#include <stdlib.h>
#include "Edge.hpp"

class Adj_list {
    public:
        Edge* root_edge;

        Adj_list();
        void insert(int vertex, float weight);
        int len();
        void print();

};






#endif