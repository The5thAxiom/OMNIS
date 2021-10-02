# made a while ago
# might need to change it

class Stack:
    def __init__(self):
        self.stack = []
        self.currentElement = 0
        self.max = 0
        self.debug()
    def SetMax(self, maxsize):
        self.max = maxsize
    def Push(self, num):
        if self.currentElement == self.max:
            print("Stack can't have more than %d elements.", self.max)
            return
        self.stack.insert(self.currentElement, num)
        self.currentElement += 1
        print("Pushed", num, "to stack.")
        self.debug()
    def Pop(self):
        if self.currentElement == 0:
            print("No elements to Pop.")
            return
        print("Popped", self.stack[self.currentElement - 1])
        ans = self.stack[self.currentElement - 1]
        self.stack.pop(self.currentElement - 1)
        self.currentElement -= 1
        self.debug()
        return ans
    def debug(self):
        print("debug: ", self.currentElement, self.stack, self.max)

a = Stack()
a.SetMax(20)
a.Push(30)
a.Push(40)
a.Pop()
a.Pop()
a.Pop()
