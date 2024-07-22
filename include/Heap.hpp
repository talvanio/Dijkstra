#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>
#include <iostream>

struct PAIR {
    int vertex;
    float distance;
    int portals_used;
};

class Heap{

    public:
        Heap(int maxsize);
        ~Heap();

        void add(PAIR x);
        void add(int vertex, float distance, int portals_used);
        PAIR pop();
        void print();
        int size;

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool is_empty();

    private:
        PAIR get_parent(int posicao);
        PAIR get_left_child(int posicao);
        PAIR get_right_child(int posicao);

        PAIR* data;
        

        // ADICIONANDO UMA FUNÇÃO NOVA: SWAP
        void swap(int posicao1,int posicao2);



        /* Funções necessárias para implementar o Heapify recursivo
         * Você pode apagar elas caso decida implementar o Heapify iterativo
         */
        void heapify_up(int posicao);
        void heapify_down(int posicao);

};







#endif