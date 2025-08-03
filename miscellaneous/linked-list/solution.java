import java.util.Scanner;
import linkedlist.DLinkedList;

class Solution {
    public static void main(String[] args) {
        System.out.println("This is a implementation of a doubly linked list from a package.");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        DLinkedList list = new DLinkedList();
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