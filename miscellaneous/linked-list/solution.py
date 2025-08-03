class Node:
    def __init__(self, value: int):
        self.value = value
        self.next = None
        self.prev = None
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

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
        
    def deleteTail(self):
        if not self.tail:
            return
        self.tail = self.tail.prev
        self.tail.next = None

    def traverseFromHead(self):
        current_node = self.head
        while current_node:
            print(current_node.value, end=' ')
            current_node = current_node.next
        print()
    
    def traverseFromTail(self):
        current_node = self.tail
        while current_node:
            print(current_node.value, end = ' ')
            current_node = current_node.prev
        print()

L = DoublyLinkedList()

L.append(2)
L.append(1)
L.append(3)

print('Traverse from head:',end='')
L.traverseFromHead()
print('Traverse from tail:',end='')
L.traverseFromTail()
print('Value of the head node',L.headNode().value)
print('Value of the tail node',L.tailNode().value)

L.append(4)

print('Traverse from head:',end='')
L.traverseFromHead()
print('Traverse from tail:',end='')
L.traverseFromTail()
print('Value of the head node',L.headNode().value)
print('Value of the tail node',L.tailNode().value)

L.prepend(0)
L.prepend(-1)

print('Traverse from head:',end='')
L.traverseFromHead()
print('Traverse from tail:',end='')
L.traverseFromTail()
print('Value of the head node',L.headNode().value)
print('Value of the tail node',L.tailNode().value)

L.deleteHead()
L.deleteTail()

print('Traverse from head:',end='')
L.traverseFromHead()
print('Traverse from tail:',end='')
L.traverseFromTail()
print('Value of the head node',L.headNode().value)
print('Value of the tail node',L.tailNode().value)
