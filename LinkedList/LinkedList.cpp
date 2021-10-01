#include <iostream>

class Node {
private:
    int key;
    Node * next;
public:
    Node(int num) {
        this->key = num;
    }
    void Add(int num) {
        Node * temp = (Node *)calloc(1, sizeof(Node));

    }
};

int main() {
    Node list = Node(3);
    list.Add(2);
}