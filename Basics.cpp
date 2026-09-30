#include <iostream> //Preprocessor directives
#include <string>


int Number(){
    return 0000;
}

double conversion(int num){
    double temp = num;
    return temp; //turns the int into a double
}

int conversion(double num){
    int temp = num;
    return temp;//will chop off the decimal
}

//pass by value
//For a pass-by-value parameter, as long as the corresponding argument is a compatible type
// (i.e., they're the same, or there's an implicit conversion between them), it will be legal to pass it.
int return_number(int num){
    return num + 1;
}

//pass by reference
//For a pass-by-reference parameter, the types actually have to match. 
//Because the reference is referring to the actual location in memory.
void change_val(int &num){
    num++;
    std::cout << "num changed to: " << num << " In function" << std::endl;
}


int main(){
    std::cout << "Hello!"<< std::endl;
    std::string s = "Hello";
    std::cout << s << std::endl;
    s = s + " There!";
    std::cout << s << std::endl;
    int var;
    std::cout << typeid(var).name() << std::endl;
    while (true){
        std::cout << "Enter something: ";
        if (std::cin >> var){
           break;
        }
        std::cout << "Not an Integer" << std::endl;
        std::cin.clear();    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

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
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i){
        std::cout << i << ", ";
    }
    std::cout << return_number(3) << std::endl;
    int h = 7;
    change_val(h);
    std::cout << h << std::endl;


    return 0;
}