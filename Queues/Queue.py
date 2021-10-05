# THIS DOES NOT WORK, I DO NOT KNOW WHY, I DON'T LIKE PYTHON'S LISTS NOW
# THIS AND QUEUE.CPP, both have problems
# THEY BOTH WILL BE QUARANTINED TO ANOTHER BRANCH
# Circular queue
import array as ar
class Queue:
    def __init__(self, size):
        self.size = size
        #self.array = ar.array('i', [0] * self.size)
        self.array = [0] * size
        self.head = 0 # the first element
        self.tail = 0 # the last available space for an element
    def IsEmpty(self):
        return self.head == self.tail
    def IsFull(self):
        return (self.tail == self.head - 1 or (self.tail == self.size - 1 and self.head == 0))
    def Enqueue(self, num):
        if self.IsFull():
            print("Queue full, cannot enqueue")
            return
        #print(self.array, self.head, self.tail, self.size, self.IsFull())
        self.array[self.tail] = num
        if self.tail == self.size - 1 or self.head != 0:
            tail = 0
        else:
            self.tail += 1
    def Dequeue(self):
        if self.IsEmpty():
            print("Queue empty, cannot dequeue")
        dequeued = self.array[self.head]
        if self.head == self.size - 1:
            self.head = 0
        else:
            self.head += 1
        return dequeued
    def Print(self):
        if self.IsEmpty():
            print("Queue empty")
            return
        cursor = self.head
        while (True):
            print(self.array[cursor], end = " ")
            if cursor == self.size - 1:
                cursor = 0
            else:
                cursor += 1
            if cursor != self.tail:
                break
        print()
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
    q = Queue(6)
    q.Print()
    q.Enqueue(1)
    q.Print()
    q << 2
    q.Print()
    q + 3
    q.Print()
    q << 5
    q.Print()
    q << 5
    q.Print()
    q >> 1
    q << 77
    q.Print()
    q << 5
    q.Print()
    q << 5
    q.Print()
    q >> 1
    q.Print()
    q.Dequeue()
    q.Print()

    # a = Queue(10)
    # a.Print()
    # a << 'a'
    # a.Print()
    # a << 'b'
    # a.Print()
    # a << 'c'
    # a.Print()
    # a >> 1
    # a.Print()
    # a >> 1
    # a.Print()
    # a >> 1
    # a.Print()
    # a >> 1
    # a.Print()
