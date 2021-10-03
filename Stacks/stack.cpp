#include<iostream>

class ArrayStack {
private:
    int * array;
    int size;
    int topPointer;
public:
    ArrayStack(int size) {
        this->size = size;
        this->array = (int *)calloc(this->size, sizeof(int));
        this->topPointer = -1;
    }
    void Push(int num) {
        if (this->topPointer == this->size - 1) {
            std::cout << "Stack full, cannot push " << num << std::endl;
            return;
        }
        this->topPointer++;
        this->array[this->topPointer] = num;
    }
    int Pop() {
        if (this->topPointer == -1) {
            std::cout << "Stack empty, cannot pop" << std::endl;
            return 0;
        }
        int popped = this->array[this->topPointer];
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
    ArrayStack stk(3);
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
    return 0;
}