#ifndef HEAP_HPP
#define HEAP_HPP
#include "Edge.hpp"



class Heap {
    public:
        int heap_size = 0;
        int heap_capacity = 10;
        Edge* items;


        Heap() {};
        
        void verify_and_increase() {
            if(heap_size == heap_capacity) {
                Edge* temp_items = new Edge[heap_capacity*2];

                for(int i=0; i<heap_capacity;i++) {
                    temp_items[i] = items[i];
                }
                delete[] this->items;
                this->items = temp_items;
                this->heap_capacity *= 2;
            }
        }

        float left_child(int index) {return items[get_left_child_index(index)].weight;};
        float right_child(int index) {return items[get_right_child_index(index)].weight;};
        float parent(int index) {return items[get_parent_index(index)].weight;};

        Edge peek() {
            if (this->heap_size == 0 ) return;
            return this->items[0];
        }

        Edge poll() {
            if (this->heap_size == 0) return;
            Edge item = this->items[0];
            this->items[0] = this->items[heap_size -1];
            this->heap_size--;
            this->heapify_down();
            return item;
        }

        void add(Edge item) {
            verify_and_increase();
            items[heap_size] = item;
            heap_size++;
            heapify_up();
        }

        // heapify_up: itera sobre o Heap, de baixo para cima. Enquanto existir um pai para aquele nó, 
        // e enquanto o pai for maior do que o último elemento, sobe o elemento pelo heap.

        void heapify_up() {
            int index = this->heap_size-1;
            while(has_parent(index) && parent(index) > items[index].weight) {
                swap(get_parent_index(index), index);
                index = get_parent_index(index);
            }

        }

        void heapify_down() {
            int index = 0;
            while(has_left_child) {

                //Encontrando o menor filho para garantir a comparação do item com os dois filhos.
                int smaller_child_index = get_left_child_index(index);
                if(has_right_child && right_child(index) < left_child(index)) {
                    smaller_child_index = get_right_child_index(index);
                }

                // Item é menor do que seus filhos (Está no local correto):
                if(items[index].weight < items[smaller_child_index].weight) {
                    break;
                }
                // Item não está no local correto:
                else {
                    swap(index,smaller_child_index);
                }
                index = smaller_child_index;
            }

        }

        bool search(int vertex_id) {
            for(int i=0;i<this->heap_size;i++) {
                if(this->items[i].vertex == vertex_id) return 1;
            }
            return 0;
        }



        int get_left_child_index(int parent_index) {
            return 2* parent_index + 1;
        }
        int get_right_child_index(int parent_index) {
            return 2* parent_index + 1;
        }
        int get_parent_index(int child_index) {
            return (child_index)/2;
        }

        bool has_left_child(int index) {
            return (get_left_child_index(index) < heap_size);
        }

        bool has_right_child(int index) {
            return (get_right_child_index(index) < heap_size);
        }
        bool has_parent(int index) {
            return (get_parent_index(index) >= 0);
        }


        void swap(int item1_index, int item2_index) {
            Edge temp = this->items[item2_index];
            this->items[item2_index] = items[item1_index];
            this->items[item1_index] = temp;
        }







};






#endif