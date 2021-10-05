#include <iostream>

template <typename type>
struct BSTNode {
    type value;
    struct BSTNode * parent;
    struct BSTNode * right;
    struct BSTNode * left;
};

/*
    Only use datatypes which can be compared(int, float, char(i think)) for proper results
*/
template <typename type>
class BinarySearchTree {
private:
    struct BSTNode<type> * Root;
public:
// Constructor(s) and Destructor(s)
    BinarySearchTree(type num) {
        Root = new struct BSTNode<type>();
        Root->value = num;
        Root->parent = NULL;
        Root->left = NULL;
        Root->right = NULL;
    }
    ~BinarySearchTree() {
        delete Root;
    }
// Methods
    void Insert(type num) {
        struct BSTNode<type> * cursor = this->Root;
        struct BSTNode<type> * temp = new struct BSTNode<type>();
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
private:
    // Traversal Methods
    void inorder(BSTNode<type> * x) {
        if (x->left != NULL) inorder(x->left);
        std::cout << x->value << " ";
        if (x->right != NULL) inorder(x->right);
    }
    void preorder(BSTNode<type> * x) {
        std::cout << x->value << " ";
        if (x->left != NULL) inorder(x->left);
        if (x->right != NULL) inorder(x->right);
    }
    void postorder(BSTNode<type> * x) {
        if (x->left != NULL) inorder(x->left);
        if (x->right != NULL) inorder(x->right);
        std::cout << x->value << " ";
    }
public:
    // Print Methods
    void PrintInOrder() {
        this->inorder(this->Root);
        std::cout << std::endl;
    }
    void PrintPreOrder() {
        this->preorder(this->Root);
        std::cout << std::endl;
    }
    void PrintPostOrder() {
        this->postorder(this->Root);
        std::cout << std::endl;
    }
// Operators
    void operator<<(type num) {
        this->Insert(num);
    }
    void operator+(type num) {
        this->Insert(num);
    }
    void operator+=(type num) {
        this->Insert(num);
    }
};

int main() {
    BinarySearchTree<int> bst(5);
    bst.PrintInOrder();
    bst << 2;
    bst.PrintInOrder();
    bst << 7;
    bst.PrintInOrder();
    bst + 1;
    bst.PrintInOrder();
    bst += 3;
    bst.PrintInOrder();
    bst.Insert(6);
    bst.PrintInOrder();
    bst.Insert(8);
    bst.PrintInOrder();
    bst.PrintPreOrder();
    bst.PrintPostOrder();
    return 0;
}