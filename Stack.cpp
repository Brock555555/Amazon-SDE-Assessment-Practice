#include <iostream>
#include "LinkedList.hpp"

int main(){
    //using our linkedlist
    LinkedList<int> Stack1;
    Stack1.push(2);
    Stack1.push(3);
    Stack1.print_nodes();

    std::cout << "Popped: " << Stack1.pop() << std::endl;
    std::cout << "Current Head is: " << Stack1.return_head() << std::endl;
}