#include <stdio.h>

class Stack {
private:
    int * array;
    int size;
    int topPointer;
public:
    Stack(size) {
        this->size = size;
        this->array = (int *)calloc(this->size, sizeof(int));
        this->topPointer = -1;
    }
};

int main() {
    Stack stk;
    return 0;
}