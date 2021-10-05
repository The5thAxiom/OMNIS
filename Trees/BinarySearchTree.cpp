#include <iostream>

struct BSTNode {
    int value;
    struct BSTNode * parent;
    struct BSTNode * right;
    struct BSTNode * left;
};

class BinarySearchTree {
private:
    struct BSTNode * Root;
public:
// Constructor(s) and Destructor(s)
    BinarySearchTree(int num) {
        Root = new struct BSTNode();
        Root->value = num;
        Root->parent = NULL;
        Root->left = NULL;
        Root->right = NULL;
    }
    ~BinarySearchTree() {
        delete Root;
    }
// Methods
    void Insert(int num) {
        struct BSTNode * cursor = this->Root;
        struct BSTNode * temp = new struct BSTNode();
        temp->value = num;
        while (true) {
            if (cursor->value > temp->value) {
                if (cursor->left == NULL) {
                    cursor->left = temp;
                    temp->parent = cursor;
                    break;
                }
                cursor = cursor->left;
            } else {
                if (cursor->right == NULL) {
                    cursor->right = temp;
                    temp->parent = cursor;
                    break;
                }
                cursor = cursor->right;
            }
        }
    }
    // Traversal Methods
    void inorder(BSTNode * x) {
        if (x->left != NULL) inorder(x->left);
        std::cout << x->value << " ";
        if (x->right != NULL) inorder(x->right);
    }
    // Print Methods
    void PrintInOrder() {
        inorder(this->Root);
        std::cout << std::endl;
    }
// Operators
};

int main() {
    BinarySearchTree bst(5);
    bst.Insert(2);
    bst.Insert(7);
    bst.Insert(1);
    bst.PrintInOrder();
    bst.Insert(3);
    bst.PrintInOrder();
    bst.Insert(6);
    bst.PrintInOrder();
    bst.Insert(8);
    bst.PrintInOrder();
    return 0;
}