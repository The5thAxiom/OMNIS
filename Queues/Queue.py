# Circular queue
import array as ar
class Queue:
    def __init__(self, size):
        self.size = size
        self.array = [0] * size
        self.head = 0 # the first element
        self.tail = 0 # the last available space for an element
        self.empty = True
        self.full = False
    def IsEmpty(self):
        return self.empty
    def IsFull(self):
        return self.full
    def Enqueue(self, num):
        if self.IsFull():
            print("Queue full, cannot enqueue")
            return
        self.array[self.tail] = num
        self.empty = False
        self.tail += 1
        if self.tail == self.size:
            self.tail = 0
        if self.tail == self.head:
            self.full = True
    def Dequeue(self):
        if self.IsEmpty():
            print("Queue empty, cannot dequeue")
        dequeued = self.array[self.head]
        self.head += 1
        self.full = False
        if self.head == self.size:
            self.head = 0
        if self.head == self.tail:
            self.empty = True
        return dequeued
    def Print(self):
        if self.IsEmpty():
            print("Queue empty")
        print("tail: {}; head: {}; size: {}; queue: {}".format(self.tail, self.head, self.size, self.array))
        #     return
        # cursor = self.head
        # while (True):
        #     print(self.array[cursor], end = " ")
        #     if cursor == self.size - 1:
        #         cursor = 0
        #     else:
        #         cursor += 1
        #     if cursor != self.tail:
        #         break
        # print()
# Operators
    def __add__(self, num):
        self.Enqueue(num)
    def __iadd__(self, num):
        self.Enqueue(num)
    def __lshift__(self, num):
        self.Enqueue(num)
    def __rshift__(self, num = 1):
        for i in range(num):
            self.Dequeue()

if __name__ == "__main__":
    q = Queue(5)
    q.Print()
    q << 1
    q.Print()
    q << 2
    q.Print()
    q << 3
    q.Print()
    q << 4
    q.Print()
    q << 5
    q.Print()
    q >> 1
    q.Print()
    q << 6
    q.Print()