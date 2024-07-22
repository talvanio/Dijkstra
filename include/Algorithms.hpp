#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../include/Graph.hpp"
#include "../include/Heap.hpp"
#include "../include/utils.hpp"

void can_escape_dijkstra(Graph* graph, int max_portals, int energy);
void can_escape_a_star(Graph* graph, int max_portals, int energy, Vertex* vertex_array);

#endif
