package linkedlist;

public class DLinkedList {
    public Node head;
    public Node tail;

    public DLinkedList() {
        head = null;
        tail = null;
    }

    public void prepend(int value) {
        Node newNode = new Node(value);
        if (tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            head.prev = newNode;
            newNode.next = head;
            head = newNode;
        }
    }

    public void append(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void traverseFromHead() {
        Node current = head;
        System.out.print("Traversal from head: ");
        while (current != null) {
            System.out.print(current.value + " ");
            current = current.next;
        }
        System.out.println();
    }

    public void traverseFromTail() {
        Node current = tail;
        System.out.print("Traversal from tail: ");
        while (current != null) {
            System.out.print(current.value + " ");
            current = current.prev;
        }
        System.out.println();
    }

    public Node headNode() {
        if (head == null) {
            System.out.println("List is empty, no head node.");
            throw new RuntimeException("List is empty");
        }
        return head;
    }

    public Node tailNode() {
        if (tail == null) {
            System.out.println("List is empty, no tail node.");
            throw new RuntimeException("List is empty");
        }
        return tail;
    }

    public void deleteHead() {
        if (head == null) {
            System.out.println("List is empty, no head to delete.");
            return;
        }
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
    }
    
    public void deleteTail() {
        if (tail == null) {
            System.out.println("List is empty, no tail to delete.");
            return;
        }
        if (head == tail) {
            head = null;
            tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
    }
}