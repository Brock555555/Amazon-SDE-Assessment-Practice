#ifndef LinkedList_HPP
#define LinkedList_HPP

template <typename T>
class LinkedList{
    private:
        struct Node{
            T value;
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

        void add_Node(T value){
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

        T return_head(){
            return head->value;
        }

        T return_tail(){
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

        T pop(){//pop the head and return its value
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

        T pop_tail(){//pop tail and return its value
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

#endif