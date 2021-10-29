// How to compile in windows:
// csc BinarySearchTree.cs -nologo && ./BinarySearchTree.exe
using System;

namespace OMNIS {
    class BSTNode {
        public int value {get; set;}
        public BSTNode parent {get; set;}
        public BSTNode right {get; set;}
        public BSTNode left {get; set;}
    }
    class BinarySearchTree {
        private BSTNode Root = new BSTNode();
        public BinarySearchTree(int num) {
            this.Root.value = num;
            this.Root.left = null;
            this.Root.right = null;
        }
        public void Insert(int num) {
            BSTNode cursor = this.Root;
            BSTNode temp = new BSTNode();
            temp.value = num;
            while (true) {
                if (cursor.value > temp.value) {
                    if (cursor.left == null) {
                        cursor.left = temp;
                        temp.parent = cursor;
                        break;
                    }
                    cursor = cursor.left;
                } else {
                    if (cursor.right == null) {
                        cursor.right = temp;
                        temp.parent = cursor;
                        break;
                    }
                    cursor = cursor.right;
                }
            }
        }
        private void inorder(BSTNode x) {
            if (x.left != null) inorder(x.left);
            System.Console.Write(String.Format("{0} ", x.value));
            if (x.right != null) inorder(x.right);
        }
        private void preorder(BSTNode x) {
            System.Console.Write(String.Format("{0} ", x.value));
            if (x.left != null) preorder(x.left);
            if (x.right != null) preorder(x.right);
        }
        private void postorder(BSTNode x) {
            if (x.left != null) postorder(x.left);
            if (x.right != null) postorder(x.right);
            System.Console.Write(String.Format("{0} ", x.value));
        }
        public void PrintInOrder() {
            this.inorder(this.Root);
            System.Console.WriteLine();
        }
        public void PrintPreOrder() {
            this.preorder(this.Root);
            System.Console.WriteLine();
        }
        public void PrintPostOrder() {
            this.postorder(this.Root);
            System.Console.WriteLine();
        }
    }
    class Testing {
        static void Main() {
            BinarySearchTree bst = new BinarySearchTree(10);
            bst.Insert(14);
            bst.Insert(1);
            bst.Insert(3);
            bst.Insert(2);
            bst.Insert(6);
            bst.Insert(12);
            bst.Insert(11);
            bst.Insert(13);
            bst.Insert(14);
            bst.Insert(15);

            bst.PrintInOrder();
            bst.PrintPreOrder();
            bst.PrintPostOrder();
        }
    }
}