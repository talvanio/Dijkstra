#include "./include/Heap.hpp"

int main() {
    Heap heap = Heap(6  );
    heap.add({0,0});
    heap.add({1,9000});
    heap.add({2,8000});
    heap.add({3,7000});
    heap.add({4,6000});
    heap.add({5,3});
    heap.print();
    heap.pop();
    std::cout<<"-- Pop -- "<<std::endl;
    heap.print();
    return 0;
}