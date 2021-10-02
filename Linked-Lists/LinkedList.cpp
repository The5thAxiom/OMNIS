#include <iostream>

struct Node {
    int value = 0;
    struct Node * next = NULL;
    struct Node * prev = NULL; // this one is not used at all for a singly linked list
};

class SinglyLinkedList {
private:
    /**
     * Only points to the first element of the list
     * (not a part of the list)
    */
    struct Node * Head;
public:
// Constructor(s)
    SinglyLinkedList() {
        this->Head = (struct Node *)calloc(1, sizeof(struct Node));
        this->Head->next = NULL;
        this->Head->value = 0;
    }
// Methods
    /*
        For inserting a node at the end of the list
    */
    void Add(int num) {
        struct Node * temp = (struct Node *)calloc(1, sizeof(struct Node));
        temp->value = num;
        temp->next = NULL;
        struct Node * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = temp;
    }
    /*
        For inserting a node at the given position (starting from 0).
        The second argument is the position which the element to be inserted
        after the function is inserted.
    */
    void Insert(int num, int index) {
        int count = 0;
        struct Node * rightCursor = this->Head->next;
        struct Node * leftCursor = this->Head;
        struct Node * temp = (struct Node *)calloc(1, sizeof(struct Node));
        temp->value = num;
        while (count != index) {
            rightCursor = rightCursor->next;
            leftCursor = leftCursor->next;
            count++;
        }
        leftCursor->next = temp;
        temp->next = rightCursor;
    }
    /*
        For printing out the whole list
    */
    void Print() {
        struct Node * cursor = this->Head;
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
    list.Add(10);
    list.Insert(1, 3);
    list.Insert(345, 0);
    list.Print();
    return 0;
};