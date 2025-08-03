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
        while (current != null) {
            System.out.print(current.value + " ");
            current = current.next;
        }
        System.out.println();
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
        list.traverseFromHead();
        scanner.close();
    }
}