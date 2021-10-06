#include <iostream>

/*
    Circular queue
*/
template <typename type>
class Queue {
private:
    type * array;
    int size, head, tail;
    bool empty, full;
public:
    Queue(int size) {
        this->size = size;
        this->array = (type *)calloc(size, sizeof(type));
        this->head = 0; // the first element
        this->tail = 0; // the last available space for an element
        this->empty = true;
        this->full = false;
    }
    bool IsEmpty() {
        return this->empty;
    }
    bool IsFull() {
        return this->full;
    }
    void Enqueue(type num) {
        if (this->IsFull()) {
            std::cout << "Queue full, cannot enqueue" << std::endl;
            return;
        }
        array[this->tail] = num;
        this->empty = false;
        this->tail++;
        if (this->tail == this->size) this->tail = 0;
        if (this->tail == this->head) this->full = true;
    }
    type Dequeue() {
        if (this->IsEmpty()) {
            std::cout << "Queue empty, cannot dequeue" << std::endl;
            return 0;
        }
        type dequeued = array[this->head];
        this->head++;
        this->full = false;
        if (this->head == this->size) this->head = 0;
        if (this->head == this->tail) this->empty = true;
        return dequeued;
    }
    void Print() {
        if (this->IsEmpty()) {
            std::cout << "Queue Empty" << std::endl;
            return;
        }
        std::cout
            << "tail: " << this->tail
            << "; head: " << this->head
            << "; size: " << this->size
            << "; queue: "
        ;
        for (int i = 0; i < this->size; i++) {
            std::cout << this->array[i] << " ";
        }
        std::cout << std::endl;
/*         for (int cursor = this->head; cursor != this->tail;) {
            std::cout << this->array[cursor] << " ";
            if (cursor == this->size - 1) cursor = 0;
            else cursor++;
        }
        std::cout << std::endl; */
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
    void operator>>(int num) {
        for (int i = 0; i < num; i++) {
            this->Dequeue();
        }
    }
};

int main() {
    Queue<int> q(5);
    q.Print();
    q << 1;
    q.Print();
    q << 2;
    q.Print();
    q << 3;
    q.Print();
    q << 4;
    q.Print();
    q << 5;
    q.Print();
    q >> 1;
    q.Print();
    q << 6;
    q.Print();

    return 0;
}
