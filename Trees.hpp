#ifndef Tree_HPP
#define Tree_HPP

template <typename T>
class Binary_Tree{
    private:
        struct Node{
            T value;
            Node* left;
            Node* right;
        };

        Node* root;
    public:
        Tree(){
            root = nullptr;//default constructor
        }
        Tree(T root_value){
            root = new Node{root_value, nullptr, nullptr};
        }



};

#endif