#ifndef EDGE_HPP
#define EDGE_HPP


class Edge {
    public:
    int vertex;
    float weight;
    Edge* next;


    Edge(int vertex, float weight);
    Edge();

};

#endif