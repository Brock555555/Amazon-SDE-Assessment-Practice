#include <iostream>
#include "LinkedList.hpp"
#include <vector>

class Stack{
    private:
        int size;//what the size currently is
        int* array;
        int capacity;//how much storage we have
    public:

        Stack(int capacity){
            this->size = 0;
            array = new int[capacity];//construct an array of some size
            this->capacity = capacity;
        }

        ~Stack(){
            delete[] array;
        }

        //functions for the array implementation
        void push(int value){
            if (size == capacity){//were full
                std::cout << "Stack is at capacity, consider reallocating or extending" << std::endl;
            }
            else{
                array[size] = value;
                size++;
            }
        }

        int pop(){//removes and returns the top value
            if (size <= 0){
                std::cout << "Stack is empty, cant delete nothing, returning -1" << std::endl;
                return -1;
            }
            else{
                int top = array[size -1];
                size--;//dont really need to delete here, just override the ints
                return top;
            }
        }

        int top(){//always found in spot size - 1
            if (size == 0){
                std::cout << "Stack is empty, returning -1" << std::endl;
                return -1;
            }
            else{
                return array[size-1];
            }
        }

        void print_stack(){
            for(int i = size-1; i >= 0; i--){
                std::cout << array[i] << std::endl;
            }
        }

};

class Vector_Stack{
    private:
        std::vector<int> vec = {};//if you want static
        //std::vector<int>* vec;// if dynamic
    public:
        Vector_Stack(){
            //vec = new std::vector<int>();//if dynamic
        }
        ~Vector_Stack(){
        }

        int top(){
            if (vec.empty()){
                std::cout << "Stack is already empty" << std::endl;
                return -1;
            }
            else{
                return vec.back();
            }
        }

        void push(int value){
            vec.push_back(value);
        }

        int pop(){
            if(vec.empty()){
                std::cout << "Stack is empty already" << std::endl;
                return -1;
            }
            else{
                int top = vec.back();
                vec.pop_back();
                return top;
            }
        }

        void print_stack(){
            for(int i = vec.size()-1; i >= 0; i--){
                std::cout << vec[i] << std::endl;
            }
        }

};

int main(){
    //using our linkedlist
    LinkedList<int> Stack1;
    Stack1.push(2);
    Stack1.push(3);
    Stack1.print_nodes();

    std::cout << "Popped: " << Stack1.pop() << std::endl;
    std::cout << "Current Head is: " << Stack1.return_head() << std::endl;

    //using an array
    //we will construct the stack such that the top is at the end of the array
    //essentially the stack will grow to the right -> toward the end of the array when it hits its capacity
    Stack Array_Stack(10);
    Array_Stack.push(4);
    std::cout << Array_Stack.top() << std::endl << std::endl;
    Array_Stack.push(10);
    Array_Stack.push(25);
    Array_Stack.push(15);
    std::cout << "Popped: " << Array_Stack.pop() << std::endl;
    Array_Stack.print_stack();
    std::cout << std::endl;
    //Array_Stack.~Stack();

    //using a vector
    Vector_Stack vector;
    vector.push(2);
    vector.push(15);
    std::cout << "Popped: "<< vector.pop() << std::endl;
    std::cout << vector.top() << std::endl << std::endl;
    vector.push(14);
    vector.print_stack();

}