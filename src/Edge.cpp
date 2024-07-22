#include "./../include/Edge.hpp"

Edge::Edge(int vertex, float weight) {
    this->next = nullptr;
    this->vertex = vertex;
    this->weight = weight;
}

Edge::Edge() {
    this->next = nullptr;
}