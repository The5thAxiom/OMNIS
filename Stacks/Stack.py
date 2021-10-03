# made a while ago
# might need to change it

# This array does not care about the types of the element
class ArrayStack:
    def __init__(self, size):
        self.size = size
        self.array = []
        self.topPointer = -1
    def IsEmpty(self):
        return (True if self.topPointer == -1 else False)
    def IsFull(self):
        return (True if self.topPointer == self.size - 1 else False)
    def Push(self, element):
        if self.IsFull():
            print("Stack full, cannot push")
            return
        self.topPointer += 1
        self.array.append(element)
    def Pop(self):
        if self.IsEmpty():
            print("Stack empty, cannot pop")
            return 0
        popped = self.array[self.topPointer]
        self.array[self.topPointer] = 0
        self.topPointer -= 1
        return popped
    def Print(self):
        str = ""
        str += "{} elements: ".format(self.topPointer + 1)
        for i in self.array:
            str += "{} ".format(i)
        print(str)

if __name__ == "__main__":
    stk = ArrayStack(3)
    stk.Push(10)
    stk.Print()
    stk.Push(20)
    stk.Print()
    stk.Push(30)
    stk.Print()
    stk.Push(40)
    stk.Print()
    stk.Pop()
    stk.Print()
    stk.Push(50)
    stk.Print()
    stk.Pop()
    stk.Print()
    stk.Pop()
    stk.Print()
    stk.Pop()
    stk.Print()
    stk.Pop()
    stk.Print()

    abc = ArrayStack(10)
    abc.Push("Hello")
    abc.Push(",")
    abc.Push(" ")
    abc.Push("World")
    abc.Push("!")
    abc.Print()

