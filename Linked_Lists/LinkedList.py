# Not meant to be actual code
# i don't remember how to do python classes that well so, this code won't even run at all
class SingleNode:
    def __init__(self):
        self.value = 0
        self.next = None
    def SetValue(self, num):
        self.value = num
    def SetNext(self, node):
        self.next = node
    def Value(self):
        return self.value
    def Next(self):
        return self.next

class SinglyLinkedList:
    def __init__(self):
        self.Head = SingleNode()
        self.Head.SetNext(None)
        self.Head.SetValue(0)
    def Size(self):
        count = 0
        cursor = self.Head
        while cursor.Next() != None:
            cursor = cursor.Next()
            count += 1
        return count
    def Add(self, num):
        temp = SingleNode()
        temp.SetValue(num)
        temp.SetNext(None)
        cursor = self.Head
        while cursor.Next() != None:
            cursor = cursor.Next()
        cursor.SetNext(temp)
    def Insert(self, num, index):
        count = 0
        rightCursor = self.Head.Next()
        leftCursor = self.Head
        temp = SingleNode()
        temp.SetValue(num)
        while count != index:
            rightCursor = rightCursor.Next()
            leftCursor = leftCursor.Next()
            count += 1
        leftCursor.SetNext(temp)
        temp.SetNext(rightCursor)
    def Delete(self, index):
        count = 0
        rightCursor = self.Head.Next()
        leftCursor = self.Head
        while count != index:
            rightCursor = rightCursor.Next()
            leftCursor = leftCursor.Next()
            count += 1
        leftCursor.SetNext(rightCursor.Next())
    def Access(self, index):
        count = -1
        cursor = self.Head
        while count != index:
            cursor = cursor.Next()
            count += 1
        return cursor.Value()
    def Print(self, index = None):
        if index is None:
            str = ""
            str += "{} elements: ".format(self.Size())
            cursor = self.Head
            while cursor.Next() != None:
                cursor = cursor.Next()
                str += "{} ".format(cursor.Value())
            print(str)
        else:
            print(self.Access(index))

class DoubleNode:
    def __init__(self):
        self.value = 0
        self.next = None
        self.prev = None
    def SetValue(self, num):
        self.value = num
    def SetNext(self, node):
        self.next = node
    def SetPrev(self, node):
        self.prev = node
    def Value(self):
        return self.value
    def Next(self):
        return self.next
    def Prev(self):
        return self.prev

class DoublyLinkedList:
    def __init__(self):
        pass

if __name__ == "__main__":
    list = SinglyLinkedList()
    list.Add(25)
    list.Add(2)
    list.Add(3)
    list.Add(5)
    list.Add(10)
    list.Print()
    list.Insert(1, 3)
    list.Print()
    list.Insert(50, 5)
    list.Print()
    list.Insert(60, 7)
    list.Print()
    list.Delete(2)
    list.Print()
    list.Delete(4)
    list.Print()

    # list1 = DoublyLinkedList()
    # list1.Add('a')
    # list1.Add('b')
    # list1.Add('c')
    # list1.Add('d')
    # list1.Add('s')
    # list1.Print()
    # list1.ReversePrint()
    # list1.Insert('g', 3)
    # list1.Print()
    # list1.Insert('n', 5)
    # list1.Print()
    # list1.Insert('!', 7)
    # list1.Print()
    # list1.Delete(2)
    # list1.Print()
    # list1.Delete(4)
    # list1.Print()

    list.Print(0)
    list.Print(1)
    list.Print(2)
    list.Print(3)

    # list1.Print(1)
    # list1.Print(2)
