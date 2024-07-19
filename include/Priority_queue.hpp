#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

class Priority_queue {
    public:
        int vertex_id;
        int distance;
        void push(int vertex_id,int distance) {
            this->vertex_id = vertex_id;
            this->distance = distance;
        }


};





#endif