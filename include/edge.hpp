#ifndef VERTICE_HPP
#define VERTICE_HPP


class edge {
    public:
    int vertex;
    float weight;
    edge* next;
    edge(int vertex, float weight) {
        this->next = nullptr;
        this->vertex = vertex;
        this->weight = weight;
    }
};

#endif