#ifndef VERTICE_HPP
#define VERTICE_HPP


class Edge {
    public:
    int vertex;
    float weight;
    Edge* next;
    Edge(int vertex, float weight) {
        this->next = nullptr;
        this->vertex = vertex;
        this->weight = weight;
    }
    Edge() {
        this->next = nullptr;
    }

};

#endif