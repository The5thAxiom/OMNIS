#include <iostream>

/*
    Circular queue
*/
template <typename type>
class Queue {
private:
    type * array;
    int size, head, tail;
public:
    Queue(int size) {
        this->size = size;
        this->array = (type *)calloc(size, sizeof(type));
        this->head = 0; // the first element
        this->tail = 0; // the last available space for an element
    }
    bool IsEmpty() {
        return (this->head == this->tail);
    }
    bool IsFull() {
        return (this->tail == this->head - 1 || (this->tail == size - 1 && this->head == 0));
    }
    void Enqueue(type num) {
        if (this->IsFull()) {
            std::cout << "Queue full, cannot enqueue" << std::endl;
            return;
        }
        array[this->tail] = num;
        if (this->tail == this->size - 1 || this->head != 0) tail = 0;
        else this->tail++;
    }
    type Dequeue() {
        if (this->IsEmpty()) {
            std::cout << "Queue empty, cannot dequeue" << std::endl;
            return 0;
        }
        type dequeued = array[this->head];
        if (head == size - 1) head = 0;
        else head++;
        return dequeued;
    }
    void Print() {
        if (this->IsEmpty()) {
            std::cout << "Queue Empty" << std::endl;
            return;
        }
        for (int cursor = this->head; cursor != this->tail;) {
            std::cout << this->array[cursor] << " ";
            if (cursor == this->size - 1) cursor = 0;
            else cursor++;
        }
        std::cout << std::endl;
    }
// Operators
    void operator<<(type num) {
        this->Enqueue(num);
    }
    void operator+(type num) {
        this->Enqueue(num);
    }
    void operator+=(type num) {
        this->Enqueue(num);
    }
    void operator--(int) {
        this->Dequeue();
    }
};

int main() {
    Queue<int> q(6);
    q.Print();
    q.Enqueue(1);
    q.Print();
    q << 2;
    q.Print();
    q + 3;
    q.Print();
    q += 5;
    q.Print();
    q += 5;
    q.Print();
    q--;
    q += 77;
    q.Print();
    q += 5;
    q.Print();
    q += 5;
    q.Print();
    q--;
    q.Print();
    q.Dequeue();
    q.Print();

    Queue<char> a(10);
    a.Print();
    a << 'a';
    a.Print();
    a << 'b';
    a.Print();
    a << 'c';
    a.Print();
    a--;
    a.Print();
    a--;
    a.Print();
    a--;
    a.Print();
    a--;
    a.Print();
    return 0;
}
