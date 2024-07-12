#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Vertex {
    public:
        int id,x_coordinate,y_coordinate;

    Vertex(int id,int x_coordinate,int y_coordinate) {
        this->id=id;
        this->x_coordinate=x_coordinate;
        this->y_coordinate=y_coordinate;
    }
    Vertex() {}
    
};





#endif