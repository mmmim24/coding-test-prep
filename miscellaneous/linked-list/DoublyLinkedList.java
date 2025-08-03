import java.util.Scanner;

public class DoublyLinkedList {
    
    static class Node {
        int value;
        Node prev;
        Node next;

        Node(int value) {
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }

    private Node head;
    private Node tail;

    public DoublyLinkedList() {
        head = null;
        tail = null;
        System.out.println("DoublyLinkedList created.");
    }

    // this below destructor is commented out because it will not work
    // Java has garbage collection and does not require explicit memory management like C++.

    // public ~DoublyLinkedList() {
    //     Node current = head;
    //     while (current != null) {
    //         Node nextNode = current.next;
    //         current.prev = null;
    //         current.next = null;
    //         current = nextNode;
    //     }
    //     head = null;
    //     tail = null;
    //     System.out.println("DoublyLinkedList deleted.");
    // }

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

    public static void main(String[] args) {
        System.out.println("This is an implementation of a doubly linked list in a standalone file.");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DoublyLinkedList list = new DoublyLinkedList();
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            list.append(value);
        }
        System.out.println("Head node value after append: " + list.headNode().value);
        System.out.println("Tail node value after append: " + list.tailNode().value);
        list.traverseFromHead();
        list.traverseFromTail();
        list.prepend(0);
        list.prepend(-1);
        System.out.println("Head node value after prepend: " + list.headNode().value);
        System.out.println("Tail node value after prepend: " + list.tailNode().value);
        list.traverseFromHead();
        list.traverseFromTail();
        list.deleteTail();
        System.out.println("Head node value after delete tail: " + list.headNode().value);
        System.out.println("Tail node value after delete tail: " + list.tailNode().value);
        list.traverseFromHead();
        list.traverseFromTail();
        list.deleteHead();
        System.out.println("Head node value after delete head: " + list.headNode().value);
        System.out.println("Tail node value after delete head: " + list.tailNode().value);
        list.traverseFromHead();
        list.traverseFromTail();
        scanner.close();
    }
}