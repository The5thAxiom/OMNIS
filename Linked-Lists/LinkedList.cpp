#include <iostream>

template <typename type>
struct SingleNode {
    type value = 0;
    struct SingleNode<type> * next = NULL;
};

/*
    Functions:
        - int SinglyLinkedList::Size(): returns the size of the list
        - void SinglyLinkedList::Add(int num): inserts an elment at the end of the list
        - void SinglyLinkedList::Insert(int num, int index): inserts an element at the specified index
        - void SinglyLinkedList::Delete(int index): deletes an element at the specified index
        - void SinglyLinkedList::Print(): prints out the elements of the list to the console
*/
template <typename type>
class SinglyLinkedList {
private:
    /**
     * Only points to the first element of the list
     * (not a part of the list)
    */
    struct SingleNode<type> * Head;
public:
// Constructor(s)
    SinglyLinkedList() {
        this->Head = (struct SingleNode<type> *)calloc(1, sizeof(struct SingleNode<type>));
        this->Head->next = NULL;
        this->Head->value = 0;
    }
// Methods
    /*
        Returns the size of the Linked List
    */
    int Size() {
        int count = 0;
        struct SingleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            count++;
        }
        return count;
    }
    /*
        For inserting a node at the end of the list
    */
    void Add(type num) {
        struct SingleNode<type> * temp = (struct SingleNode<type> *)calloc(1, sizeof(struct SingleNode<type>));
        temp->value = num;
        temp->next = NULL;
        struct SingleNode<type> * cursor = this->Head;
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
    void Insert(type num, int index) {
        int count = 0;
        struct SingleNode<type> * rightCursor = this->Head->next;
        struct SingleNode<type> * leftCursor = this->Head;
        struct SingleNode<type> * temp = (struct SingleNode<type> *)calloc(1, sizeof(struct SingleNode<type>));
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
        struct SingleNode<type> * rightCursor = this->Head->next;
        struct SingleNode<type> * leftCursor = this->Head;
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
        struct SingleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
};
template <typename type>
struct DoubleNode {
    type value = 0;
    struct DoubleNode<type> * next = NULL;
    struct DoubleNode<type> * prev = NULL;
};

/*
    Functions:
        - int DoublyLinkedList::Size(): returns the size of the list
        - void DoublyLinkedList::Add(int num): inserts an elment at the end of the list
        - void DoublyLinkedList::Insert(int num, int index): inserts an element at the specified index
        - void DoublyLinkedList::Delete(int index): deletes an element at the specified index
        - void DoublyLinkedList::Print(): prints out the elements of the list to the console
        - void DoublyLinkedList::ReversePrint(): prints out the elements of the list to the console in the reverse order
*/
template <typename type>
class DoublyLinkedList {
private:
    /**
     * Only points to the first element of the list
     * (not a part of the list)
    */
    struct DoubleNode<type> * Head;
public:
// Constructor(s)
    DoublyLinkedList() {
        this->Head = (struct DoubleNode<type> *)calloc(1, sizeof(struct DoubleNode<type>));
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
        struct DoubleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            count++;
        }
        return count;
    }
    /*
        For inserting a node at the end of the list
    */
    void Add(type num) {
        struct DoubleNode<type> * temp = (struct DoubleNode<type> *)calloc(1, sizeof(struct DoubleNode<type>));
        temp->value = num;
        temp->next = NULL;
        struct DoubleNode<type> * cursor = this->Head;
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
    void Insert(type num, int index) {
        int count = 0;
        struct DoubleNode<type> * rightCursor = this->Head->next;
        struct DoubleNode<type> * leftCursor = this->Head;
        struct DoubleNode<type> * temp = (struct DoubleNode<type> *)calloc(1, sizeof(struct DoubleNode<type>));
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
        struct DoubleNode<type> * rightCursor = this->Head->next;
        struct DoubleNode<type> * leftCursor = this->Head;
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
        struct DoubleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
    void ReversePrint() {
    std::cout << this->Size() << " elements: ";
    struct DoubleNode<type> * cursor = this->Head;
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
    SinglyLinkedList<int> list;
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

    DoublyLinkedList<char> list1;
    list1.Add('a');
    list1.Add('b');
    list1.Add('c');
    list1.Add('d');
    list1.Add('s');
    list1.Print();
    list1.ReversePrint();
    list1.Insert('g', 3);
    list1.Print();
    list1.Insert('n', 5);
    list1.Print();
    list1.Insert('!', 7);
    list1.Print();
    list1.Delete(2);
    list1.Print();
    list1.Delete(4);
    list1.Print();
    return 0;
};
