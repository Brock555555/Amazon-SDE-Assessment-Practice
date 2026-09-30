#include <iostream>
#include <string>

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
    return 0;

}