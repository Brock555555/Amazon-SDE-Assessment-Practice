#include <iostream> //Preprocessor directives
#include <string>


int boo(){
    return 0000;
}


int main(){
    std::cout << "Hello Boo!"<< std::endl;


    int a = 3;
    int b = 4;
    if (a < 3 && b > 9){
        std::cout << "out of range" << std::endl;
    }
    else{
        std::cout << "in range!" << std::endl;
    }

    switch(a){
        case 0:
            std::cout << "zero" << std::endl;
            break;
        case 1:
            std::cout << "one" << std::endl;
            break;
        default:   
            std::cout << "other" << std::endl;
            break;   
    }

    //post increment a++ assigns value first then increments
    //pre increment ++a increments first then assigns
    a = 3;
    while(a < 10){
        std::cout << a << ", ";
        a++;
    }
    a=3;
    while(a < 10){
        std::cout << a << ", ";
        ++a;
    }
    std::cout << std::endl;

    a = 1;
    int c = ++a; // is c = (a + 1)
    std::cout << c;
    a = 1;
    int d = a++; // is d = a, d + 1
    std::cout << d;


    for (int i = 0; i < 10; i++){
        std::cout << i << std::endl;
    }

    return 0;
}