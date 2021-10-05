#include <iostream>

template <typename type>
struct SingleNode {
    type value;
    struct SingleNode<type> * next = NULL;
};

template <typename type>
class SinglyLinkedList {
private:
    struct SingleNode<type> * Head;
public:
    SinglyLinkedList() {
        this->Head = new struct SingleNode<type>();
        this->Head->next = NULL;
        this->Head->value = 0;
    }
    int Size() {
        int count = 0;
        struct SingleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            count++;
        }
        return count;
    }
    void Add(type num) {
        struct SingleNode<type> * temp = new struct SingleNode<type>();
        temp->value = num;
        temp->next = NULL;
        struct SingleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = temp;
    }
    void Insert(type num, int index) {
        int count = 0;
        struct SingleNode<type> * rightCursor = this->Head->next;
        struct SingleNode<type> * leftCursor = this->Head;
        struct SingleNode<type> * temp = new struct SingleNode<type>();
        temp->value = num;
        while (count != index) {
            rightCursor = rightCursor->next;
            leftCursor = leftCursor->next;
            count++;
        }
        leftCursor->next = temp;
        temp->next = rightCursor;
    }
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
        delete rightCursor;
    }
    type Access(int index) {
        int count = -1;
        struct SingleNode<type> * cursor = this->Head;
        while (count != index) {
            cursor = cursor->next;
            count++;
        }
        return cursor->value;
    }
    void Print() {
        std::cout << this->Size() << " elements: ";
        struct SingleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
    void Print(int index) {
        std::cout << this->Access(index) << std::endl;
    }
    void operator<<(type num) {
        this->Add(num);
    }
    void operator+(type num) {
        this->Add(num);
    }
    void operator+=(type num) {
        this->Add(num);
    }
};

template <typename type>
struct DoubleNode {
    type value;
    struct DoubleNode<type> * next = NULL;
    struct DoubleNode<type> * prev = NULL;
};

template <typename type>
class DoublyLinkedList {
private:
    struct DoubleNode<type> * Head;
public:
    DoublyLinkedList() {
        this->Head = new struct DoubleNode<type>();
        this->Head->next = NULL;
        this->Head->prev = NULL;
        this->Head->value = 0;
    }
    int Size() {
        int count = 0;
        struct DoubleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            count++;
        }
        return count;
    }
    void Add(type num) {
        struct DoubleNode<type> * temp = new struct DoubleNode<type>();
        temp->value = num;
        temp->next = NULL;
        struct DoubleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = temp;
        temp->prev = cursor;
    }
    void Insert(type num, int index) {
        int count = 0;
        struct DoubleNode<type> * rightCursor = this->Head->next;
        struct DoubleNode<type> * leftCursor = this->Head;
        struct DoubleNode<type> * temp = new struct DoubleNode<type>();
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
        delete rightCursor;
    }
    type Access(int index) {
        int count = -1;
        struct DoubleNode<type> * cursor = this->Head;
        while (count != index) {
            cursor = cursor->next;
            count++;
        }
        return cursor->value;
    }
    void Print() {
        std::cout << this->Size() << " elements: ";
        struct DoubleNode<type> * cursor = this->Head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            std::cout << cursor->value << " ";
        }
        std::cout << std::endl;
    }
    void Print(int index) {
        std::cout << this->Access(index) << std::endl;
    }
    void ReversePrint() {
    std::cout << this->Size() << " elements: ";
    struct DoubleNode<type> * cursor = this->Head;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    std::cout << cursor->value << " ";
    while (cursor->prev != this->Head) {
        cursor = cursor->prev;
        std::cout << cursor->value << " ";
    }
    std::cout << std::endl;
    }
    void operator<<(type num) {
        this->Add(num);
    }
    void operator+(type num) {
        this->Add(num);
    }
    void operator+=(type num) {
        this->Add(num);
    }
};

int main() {
    SinglyLinkedList<int> list;
    list << 25;
    list + 2;
    list += 3;
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
    list1 << 'a';
    list1 += 'b';
    list1 + 'c';
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

    list.Print(0);
    list.Print(1);
    list.Print(2);
    list.Print(3);

    list1.Print(1);
    list1.Print(2);
    return 0;
};
