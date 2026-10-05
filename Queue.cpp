#include "LinkedList.hpp"
#include <iostream>
#include <string>

//implementation of a double ended queue

template <typename T>
void enqueueFront(LinkedList<T> &queue, const T &value){
    queue.push(value);
}

template <typename T>
void enqueueBack(LinkedList<T> &queue, const T &value){
    queue.add_Node(value);
}

template <typename T>
T dequeueFront(LinkedList<T> &queue){
    return queue.pop();
}

template <typename T>
T dequeueBack(LinkedList<T> &queue){
    return queue.pop_tail();
}

template <typename T>
T front(LinkedList<T> &queue){
    return queue.return_head();
}

template <typename T>
T back(LinkedList<T> &queue){
    return queue.return_tail();
}

int main(){
    LinkedList<std::string> queue;
    enqueueFront(queue, std::string("Debra"));
    enqueueBack(queue, std::string("Bret"));
    std::cout << front(queue) << ' '<< back(queue) << std::endl;
    queue.print_nodes();
    std::cout << "Removed: " << dequeueBack(queue) << std::endl;
    enqueueFront(queue, std::string("Roo"));
    std::cout << "Removed: " << dequeueFront(queue) << std::endl;
    queue.print_nodes();
    
    return 0;
}