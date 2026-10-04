#include <iostream>
#include <array>
#include <vector>

void fill_array(int* passed_array, int array_size, int filler){//fills an array with what you want
    for (int i = 0; i < array_size; i++){
        passed_array[i] = filler;
    }
}


int main(){
    //int a[10]; //a statically allocated array of 10 ints
    //but what are they currently? its not populated!
    int a[10] = {};
    int a_size = sizeof(a) / sizeof(a[0]);//for raw arrays, if imported array or vector can use .size()
    for (int i = 0; i < a_size; i++){
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;

    std::array<int, 10> numbers = {};//declaration using array library
    for (int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;

    int* new_array = new int[10];//a dynamically allocated array
    fill_array(new_array, 10, 0);
    //int new_array_size = sizeof(new_array) / sizeof(new_array[0]);//doesnt work for built in dynamic arrays, use vectors instead
    int new_array_size = 10;
    for (int i = 0; i < new_array_size; i++){
        std::cout << new_array[i] << ", ";
    }
    std::cout << std::endl;
    delete[] new_array;

    std::vector<int> vector1 = {};//an empty vector
    //Vectors can dynamically grow or shrink during program execution.
    //They provide constant-time random access and support efficient insertion and deletion at the end.
    vector1.begin(); //returns the start of the vector
    vector1.push_back(1); //places a value at the end
    vector1.insert(vector1.begin(), 2); //places a value in a specific spot, here its 0
    vector1.insert(vector1.begin() + 2, 4); //in index 2
    for (int i = 0; i < vector1.size(); i++){
        std::cout << vector1[i] << ", ";
    }
    std::cout << std::endl;
    vector1.erase(vector1.begin(), vector1.end());//erase all elements
    std::vector<int>* vec = new std::vector<int>();//a dynamically allocated vector, vectors are already on heap so you would rarely do this
    delete vec;

    //multidimensional arrays
    int rows = 5;
    int columns = 5;
    int multi[5][5];
    for (int i = 0; i < rows; i++){
        for(int j =0; j < columns; j++){
            multi[i][j] = i * j;
            std::cout << multi[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //dynamically
    int ** dynamic_multi = new int*[rows];//is an int pointer to pointers that are arrays
    for(int i = 0; i < rows; i++){
        dynamic_multi[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++){
        for(int j =0; j < columns; j++){
            dynamic_multi[i][j] = i + j;
            std::cout << dynamic_multi[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    //multidimensional vectors
    std::vector<std::vector <int>> vector2(rows, std::vector<int>(columns));//is a vector of vectors (ints) where the rows are a vector
    //and the columns are also a vector
    for (int i = 0; i < vector2.size(); i++){//vector2.size() gives the # of rows
        for (int j = 0; j < vector2[0].size(); j++){//vector2[0].size() gives the # of columns
            vector2[i][j] = i + j;
            std::cout << vector2[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    return 0;
}