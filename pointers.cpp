#include <iostream>
#include <string>
#include <memory>

int main(){
    int* x; // x is a pointer to an integer, its value is an address of where it points to
    int y = 1;
    x = &y;//the value of the x pointer will be the address of y, & takes the address of the variable
    std::cout << x << std::endl; //prints something such as 0000001CAC2FF7F0
    std::cout << *x << std::endl; //prints 1, *x is the dereference operator, 
    //it dereferences the pointer to give what the value is that it points to.
    int i = 3;
    int* p = &i;
    std::cout << i << std::endl;
    *p = 4;//dereferences the pointer p, which points to i, to change the value of i to 4
    std::cout << i << std::endl;
    //you can also have pointers to pointers
    int **w;//this is a pointer to a pointer
    w = &p;//which is the address of a pointer
    std::cout << w << " " << *w  << " " << **w << std::endl;

    int* f = new int;//goes on the heap (dynamic storage allocation)
    *f = 3;
    std::cout << f << std::endl;
    std::cout << *f << std::endl;
    (*f)++;
    std::cout << *f << std::endl;
    delete f;

    int value = 10;
    void* void_pointer;//cant be dereferenced unless by type casting since they can hold any value
    void_pointer = &value;
    std::cout << *(static_cast<int*>(void_pointer)) << std::endl;

    //types of smart pointers
    std::unique_ptr<int> unique{new int};//this is a unique pointer, it holds unique ownership of the object it points too
    //It will also guarantees that its death will trigger the automatic deletion of the object it points to
    *unique = 1;//this int value will be deleted if the pointer were to fall out of scope
    //Since a unique pointer has automatic deletion it isnt allowed to be copied, since you could try to copy something deleted
    std::shared_ptr<int> shared{new int};//This is a shared pointer, ownership is shared 
    //as long as any one of those pointers still points to the object, the object will continue to exist, 
    //but as soon as the last one is destroyed, the object will be destroyed automatically
    std::shared_ptr<int> shared2 = shared;//as you can see shared pointers can be copied, since its destroyed when the last one dies
    *shared = 4;
    //there also one called weak ptr but its mainly used to observe a shared pointer and detecting cyclic references

    return 0;

}