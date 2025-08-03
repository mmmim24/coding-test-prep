class Node:
    def __init__(self, value: int):
        self.value = value
        self.next = None
        self.prev = None
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        print("DoublyLinkedList created.")

    # the destructor to clean up the linked list
    # it is not necessary to call this explicitly in Python
    # as Python has garbage collection

    def __del__(self):
        current = self.head
        while current:
            next_node = current.next
            current.prev = None
            current.next = None
            current = next_node
        self.head = None
        self.tail = None
        print("DoublyLinkedList deleted.")

    def prepend(self, value: int):
        new_node = Node(value)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node
        if not self.tail:
            self.head = new_node
            self.tail = new_node
            
    def append(self, value: int):
        new_node = Node(value)
        new_node.prev = self.tail
        if self.tail:
            self.tail.next = new_node
        self.tail = new_node
        if not self.head:
            self.head = new_node
            self.tail = new_node

    def headNode(self)->Node:
        if self.head:
            return self.head
        return None

    def tailNode(self)->Node:
        if self.tail:
            return self.tail
        return None

    def deleteHead(self):
        if not self.head:
            return
        self.head = self.head.next
        self.head.prev = None
        if not self.head:
            self.tail = None
        
    def deleteTail(self):
        if not self.tail:
            return
        self.tail = self.tail.prev
        self.tail.next = None
        if not self.tail:
            self.head = None

    def traverseFromHead(self):
        current_node = self.head
        if not current_node:
            print('List is empty')
            return
        print('Traverse from head:',end=' ')
        while current_node:
            print(current_node.value, end=' ')
            current_node = current_node.next
        print()
    
    def traverseFromTail(self):
        current_node = self.tail
        if not current_node:
            print('List is empty')
            return
        print('Traverse from tail:',end=' ')
        while current_node:
            print(current_node.value, end = ' ')
            current_node = current_node.prev
        print()

L = DoublyLinkedList()

L.append(2)
L.append(1)
L.append(3)

print('Head node value after append.',L.headNode().value)
print('Tail node value after append.',L.tailNode().value)
L.traverseFromHead()
L.traverseFromTail()

L.prepend(0)
L.prepend(-1)

print('Head node value after prepend.',L.headNode().value)
print('Tail node value after prepend.',L.tailNode().value)
L.traverseFromHead()
L.traverseFromTail()

L.deleteTail()
print('Head node value after delete tail.',L.headNode().value)
print('Tail node value after delete tail.',L.tailNode().value)
L.traverseFromHead()
L.traverseFromTail()

L.deleteHead()
print('Head node value after delete head.',L.headNode().value)
print('Tail node value after delete head.',L.tailNode().value)
L.traverseFromHead()
L.traverseFromTail()

