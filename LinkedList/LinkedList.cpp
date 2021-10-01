#include <iostream>

struct Node {
    int value = 0;
    struct Node * next = NULL;
    struct Node * prev = NULL;
};

class SinglyLinkedList {
private:
    /**
     * Only points to the first element of the list
     * (not a part of the list)
    */
    struct Node * Head;
public:
    SinglyLinkedList() {
        this->Head->next = NULL;
        this->Head->value = 0;
    }
    void Add(int num) {
        struct Node * temp = (struct Node *)calloc(1, sizeof(struct Node));
        temp->value = num;
        struct Node * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = temp;
        
    }
    void Print() {
        struct Node * cursor = (struct Node *)calloc(1, sizeof(struct Node));
        cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << std::endl;
        }
    }
};


int main() {
    SinglyLinkedList list = SinglyLinkedList();
    list.Add(25);
    list.Add(2);
    list.Add(3);
    list.Add(5);
    list.Print();
    return 0;
};