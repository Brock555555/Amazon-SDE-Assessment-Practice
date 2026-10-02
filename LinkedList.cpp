#include <iostream>
#include <stdexcept>

class LinkedList{
    private:
        struct Node{
            int value;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;

    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        ~LinkedList(){//doesnt have any allocated values so just delete the nodes
            Node* current = head;
            while(current){
                Node* next_node = current->next;
                delete current;
                current = next_node;
            }
        }

        void add_Node(int value){
            if (head == nullptr){
                head = new Node{value, nullptr, nullptr};
                tail = head;
            }
            else{
                Node* temp_node = new Node{value, nullptr, tail};
                tail->next = temp_node;
                tail = temp_node;
            }
        }

        void print_nodes(){
            Node* current = head;
            while(current){
                std::cout << current->value << std::endl;
                current = current->next;
            }
        }

        void print_nodes_reverse(){
            Node* current = tail;
            while (current){
                std::cout << current->value << std::endl;
                current = current->prev;
            }
        }

        int return_head(){
            return head->value;
        }

        int return_tail(){
            return tail->value;
        }

        int length(){
            int count = 0;
            Node* current = head;
            while(current){
                count++;
                current = current->next;
            }
            return count;
        }

        int pop(){//pop the head and return its value
            if(head){
                Node* old_head = head;
                int value = old_head->value;
                head = head->next;//should be another node or nullptr if only one
                if(head == nullptr){//make sure the tail doesnt point to junk
                    tail = nullptr;
                }
                delete old_head;
                return value;
            }
            else{
                throw std::out_of_range("Tried to delete the head node of an empty list");
            }
        }

        int pop_tail(){//pop tail and return its value
            if(tail){
                Node* old_tail = tail;
                int value = tail->value;
                tail = tail->prev;
                if (tail == nullptr){
                    head = nullptr;
                }
                else{
                    tail->next = nullptr;
                }
                delete old_tail;
                return value;
            }
            else{
                throw std::out_of_range("Tried to delete the tail node of an empty list");
            }
        }

};

int main(){
    LinkedList Numbers;
    Numbers.add_Node(1);
    Numbers.add_Node(2);
    Numbers.print_nodes();
    Numbers.print_nodes_reverse();
    Numbers.pop();
    Numbers.print_nodes();
    std::cout << "----------------" << std::endl;
    Numbers.~LinkedList();
    LinkedList* Numbers2 = new LinkedList;
    Numbers2->add_Node(3);
    Numbers2->add_Node(4);
    Numbers2->print_nodes();
    delete Numbers2;//should delete the linked list itself and calls the deconstructor
    LinkedList Numbers3;
    try{
        Numbers3.pop();
    }
    catch(const std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        Numbers3.pop_tail();
    }
    catch(const std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }



    return 0;
}