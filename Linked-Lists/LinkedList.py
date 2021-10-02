# Not meant to be actual code
# i don't remember how to do python classes that well so, this code won't even run at all
class Node:
    value = 0

class SinglyLinkedList:
    def __init__(self):
        self.Head = Node()
        self.Head.next = None
        self.Head.value = 0
    def Add(self, num):
        self.Head.next = Node()
        
