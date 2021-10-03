#include <iostream>
#include <string>

template <typename type>
class ArrayStack {
private:
    type * array;
    int size;
    int topPointer;
public:
    ArrayStack(int size) {
        this->size = size;
        this->array = (type *)calloc(this->size, sizeof(type));
        this->topPointer = -1;
    }
    bool IsEmpty() {
        return (this->topPointer == -1);
    }
    bool IsFull() {
        return (this->topPointer == this->size - 1);
    }
    void Push(type element) {
        if (this->IsFull()) {
            std::cout << "Stack full, cannot push " << element << std::endl;
            return;
        }
        this->topPointer++;
        this->array[this->topPointer] = element;
    }
    type Pop() {
        if (this->IsEmpty()) {
            std::cout << "Stack empty, cannot pop" << std::endl;
            return 0;
        }
        type popped = this->array[this->topPointer];
        this->array[this->topPointer] == 0;
        this->topPointer--;
        return popped;
    }
    void Print() {
        std::cout << this->topPointer + 1 << " elements: ";
        for (int i = 0; i <= this->topPointer; i++) {
            std::cout << this->array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Testing Stacks" << std::endl;
    ArrayStack<int> stk(3);
    stk.Push(10);
    stk.Print();
    stk.Push(20);
    stk.Print();
    stk.Push(30);
    stk.Print();
    stk.Push(40);
    stk.Print();
    stk.Pop();
    stk.Print();
    stk.Push(50);
    stk.Print();
    stk.Pop();
    stk.Print();
    stk.Pop();
    stk.Print();
    stk.Pop();
    stk.Print();
    stk.Pop();
    stk.Print();

    ArrayStack<std::string> abc(10);
    abc.Push("Hello");
    abc.Push(",");
    abc.Push(" ");
    abc.Push("World");
    abc.Push("!");
    abc.Print();
    return 0;
}