#include "./../include/Heap.hpp"


Heap::Heap(int maxsize) {
    this->size = 0;
    this->data = new PAIR[maxsize];
}

Heap::~Heap() {
    delete []data;
}

PAIR Heap::get_parent(int posicao) {
    if ((posicao-1)/2 <= 0) return {-1,-1};
    return data[(posicao-1)/2];
}

PAIR Heap::get_left_child(int posicao) {
    if (posicao*2+1 >= this->size) return {-1,-1};
    return this->data[posicao*2+1];
}

PAIR Heap::get_right_child(int posicao) {
    if (posicao*2+2 >= this->size) return {-1,-1};
    return this->data[posicao*2+2];
}

void Heap::swap(int posicao1, int posicao2) {
    PAIR temp = this->data[posicao2];
    this->data[posicao2] = data[posicao1];
    this->data[posicao1] = temp;
}

void Heap::add(PAIR x) {
    data[this->size] = x;
    size++;
    this->heapify_up(this->size-1);
}

void Heap::add(int vertex,float distance, int portals_used) {
    data[this->size] = {vertex,distance, portals_used};
    size++;
    this->heapify_up(this->size-1);
}

PAIR Heap::pop() {
    if(is_empty()) return {-1,-1};
    PAIR item = this->data[0];
    this->data[0] = this->data[this->size-1];
    this->size--;
    this->heapify_down(0);
    return item;
};

bool Heap::is_empty() {
    return (this->size == 0);
}

void Heap::heapify_up(int posicao) {
    while(posicao > 0 && data[posicao].distance < data[(posicao-1)/2].distance) {
        swap(posicao, (posicao-1)/2);
        posicao = posicao/2;
    }

}

void Heap::heapify_down(int posicao) {
        int IndexDoMenorFilho;
    while(2*posicao+1 < size) {
        //Encontrando o menor filho para garantir a comparação do item com os dois filhos.
        int IndexDoMenorFilho = posicao*2+1;

        if(IndexDoMenorFilho + 1 < size && get_right_child(posicao).distance < get_left_child(posicao).distance) {
            IndexDoMenorFilho = posicao*2+2;
        }
        // Item é menor do que seus filhos (Está no local correto):
        if(data[posicao].distance < data[IndexDoMenorFilho].distance ) {
            break;
        }
        // Item não está no local correto:
        else {
            swap(posicao,IndexDoMenorFilho);
        }
        posicao = IndexDoMenorFilho;
    }
};

void Heap::print() {
    for(int i=0;i<this->size;i++) {
        std::cout<<this->data[i].vertex<<" : "<< data[i].distance << std::endl;
    }
}
