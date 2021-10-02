#include <iostream>

struct Node {
    int value = 0;
    struct Node * next = NULL;
    struct Node * prev = NULL; // this one is not used at all for a singly linked list
};


/*
    Functions:
        - int SinglyLinkedList::Size(): returns the size of the list
        - void SinglyLinkedList::Add(int num): inserts an elment at the end of the list
        - void SinglyLinkedList::Insert(int num, int index): inserts an element at the specified index
        - void SinglyLinkedList::Delete(int index): deletes an element at the specified index
        - void SinglyLinkedList::Print(): prints out the elements of the list to the console
*/
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
        Returns the size of the Linked List
    */
    int Size() {
        int count = 0;
        struct Node * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            count++;
        }
        return count;
    }
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
        For deleting the specified index (starting from 0)
    */
   void Delete(int index) {
        int count = 0;
        struct Node * rightCursor = this->Head->next;
        struct Node * leftCursor = this->Head;
        while (count != index) {
            rightCursor = rightCursor->next;
            leftCursor = leftCursor->next;
            count++;
        }
        leftCursor->next = rightCursor->next;
        free(rightCursor);
   }
    /*
        For printing out the whole list
    */
    void Print() {
        std::cout << this->Size() << " elements: ";
        struct Node * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList list = SinglyLinkedList();
    list.Add(25);
    list.Add(2);
    list.Add(3);
    list.Add(5);
    list.Add(10);
    list.Print();
    list.Insert(1, 3);
    list.Print();
    list.Insert(50, 5);
    list.Print();
    list.Insert(60, 7);
    list.Print();
    list.Delete(2);
    list.Print();
    list.Delete(4);
    list.Print();
    return 0;
};