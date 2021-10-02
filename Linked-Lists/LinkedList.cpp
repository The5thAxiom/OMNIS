#include <iostream>

struct SingleNode {
    int value = 0;
    struct SingleNode * next = NULL;
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
    struct SingleNode * Head;
public:
// Constructor(s)
    SinglyLinkedList() {
        this->Head = (struct SingleNode *)calloc(1, sizeof(struct SingleNode));
        this->Head->next = NULL;
        this->Head->value = 0;
    }
// Methods
    /*
        Returns the size of the Linked List
    */
    int Size() {
        int count = 0;
        struct SingleNode * cursor = this->Head;
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
        struct SingleNode * temp = (struct SingleNode *)calloc(1, sizeof(struct SingleNode));
        temp->value = num;
        temp->next = NULL;
        struct SingleNode * cursor = this->Head;
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
        struct SingleNode * rightCursor = this->Head->next;
        struct SingleNode * leftCursor = this->Head;
        struct SingleNode * temp = (struct SingleNode *)calloc(1, sizeof(struct SingleNode));
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
        struct SingleNode * rightCursor = this->Head->next;
        struct SingleNode * leftCursor = this->Head;
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
        struct SingleNode * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
};

struct DoubleNode {
    int value = 0;
    struct DoubleNode * next = NULL;
    struct DoubleNode * prev = NULL;
};

/*
    Functions:
        - int SinglyLinkedList::Size(): returns the size of the list
        - void SinglyLinkedList::Add(int num): inserts an elment at the end of the list
        - void SinglyLinkedList::Insert(int num, int index): inserts an element at the specified index
        - void SinglyLinkedList::Delete(int index): deletes an element at the specified index
        - void SinglyLinkedList::Print(): prints out the elements of the list to the console
*/
class DoublyLinkedList {
private:
    /**
     * Only points to the first element of the list
     * (not a part of the list)
    */
    struct DoubleNode * Head;
public:
// Constructor(s)
    DoublyLinkedList() {
        this->Head = (struct DoubleNode *)calloc(1, sizeof(struct DoubleNode));
        this->Head->next = NULL;
        this->Head->prev = NULL;
        this->Head->value = 0;
    }
// Methods
    /*
        Returns the size of the Linked List
    */
    int Size() {
        int count = 0;
        struct DoubleNode * cursor = this->Head;
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
        struct DoubleNode * temp = (struct DoubleNode *)calloc(1, sizeof(struct DoubleNode));
        temp->value = num;
        temp->next = NULL;
        struct DoubleNode * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = temp;
        temp->prev = cursor;
    }
    /*
        For inserting a node at the given position (starting from 0).
        The second argument is the position which the element to be inserted
        after the function is inserted.
    */
    void Insert(int num, int index) {
        int count = 0;
        struct DoubleNode * rightCursor = this->Head->next;
        struct DoubleNode * leftCursor = this->Head;
        struct DoubleNode * temp = (struct DoubleNode *)calloc(1, sizeof(struct DoubleNode));
        temp->value = num;
        while (count != index) {
            rightCursor = rightCursor->next;
            leftCursor = leftCursor->next;
            count++;
        }
        leftCursor->next = temp;
        temp->next = rightCursor;
        temp->prev = leftCursor;
    }
    /*
        For deleting the specified index (starting from 0)
    */
   void Delete(int index) {
        int count = 0;
        struct DoubleNode * rightCursor = this->Head->next;
        struct DoubleNode * leftCursor = this->Head;
        while (count != index) {
            rightCursor = rightCursor->next;
            leftCursor = leftCursor->next;
            count++;
        }
        leftCursor->next = rightCursor->next;
        leftCursor->next->prev = leftCursor;
        free(rightCursor);
   }
    /*
        For printing out the whole list
    */
    void Print() {
        std::cout << this->Size() << " elements: ";
        struct DoubleNode * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
    void ReversePrint() {
    std::cout << this->Size() << " elements: ";
    struct DoubleNode * cursor = this->Head;
    while (cursor->next != NULL) { // go to the end of the list
        cursor = cursor->next;
    }
    std::cout << cursor->value << " ";
    while (cursor->prev != this->Head) {//
        cursor = cursor->prev;
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

    DoublyLinkedList list1;
    list1.Add(25);
    list1.Add(2);
    list1.Add(3);
    list1.Add(5);
    list1.Add(10);
    list1.Print();
    list1.ReversePrint();
    list1.Insert(1, 3);
    list1.Print();
    list1.Insert(50, 5);
    list1.Print();
    list1.Insert(60, 7);
    list1.Print();
    list1.Delete(2);
    list1.Print();
    list1.Delete(4);
    list1.Print();
    return 0;
};