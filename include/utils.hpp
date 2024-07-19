#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "Priority_queue.hpp"

// Método babilônico para encontrar raizes quadradas
double sqrt(double n) {
    double error = 0.0001;
    double s = n;
    while((s-n / s)> error) {
        s = (s+n / s )/2;
    };
    return s;
};


double calculate_distance(Vertex origin_vertex, Vertex destination_vertex) {

    int x_distance = destination_vertex.x_coordinate-origin_vertex.x_coordinate;
    int y_distance = destination_vertex.y_coordinate-origin_vertex.y_coordinate;
    
    double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
    return distance;

}

#endif