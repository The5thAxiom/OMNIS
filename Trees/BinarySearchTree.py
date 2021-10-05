class BSTNode:
    def __init__(self):
        self.value = None
        self.parent = None
        self.left = None
        self.right = None
    def Value(self):
        return self.value
    def Parent(self):
        return self.parent
    def Left(self):
        return self.left
    def Right(self):
        return self.right
    def SetValue(self, num):
        self.value = num
    def SetParent(self, p):
        self.parent = p
    def SetLeft(self, l):
        self.left = l
    def SetRight(self, r):
        self.right = r

class BinarySearchTree:
    def __init__(self, num):
        self.Root = BSTNode()
        self.Root.SetValue(num)
    def Insert(self, num):
        cursor = self.Root
        temp = BSTNode()
        temp.SetValue(num)
        while True:
            if cursor.Value() > temp.Value():
                if cursor.Left() == None:
                    cursor.SetLeft(temp)
                    temp.SetParent(cursor)
                    break
                cursor = cursor.Left()
            else:
                if cursor.Right() == None:
                    cursor.SetRight(temp)
                    temp.SetParent(cursor)
                    break
                cursor = cursor.Right()
    def inorder(self, x):
        if x.Left() != None:
            self.inorder(x.Left())
        print(x.Value(), end = " ")
        if x.Right() != None:
            self.inorder(x.Right())
    def PrintInOrder(self):
        self.inorder(self.Root)
        print()

if __name__ == "__main__":
    bst = BinarySearchTree(5)
    bst.Insert(2)
    bst.PrintInOrder()
    bst.Insert(7)
    bst.PrintInOrder()
    bst.Insert(1)
    bst.PrintInOrder()
    bst.Insert(3)
    bst.PrintInOrder()
    bst.Insert(6)
    bst.PrintInOrder()
    bst.Insert(8)
    bst.PrintInOrder()