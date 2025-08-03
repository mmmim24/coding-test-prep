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
        list.traverseFromHead();
        scanner.close();
    }
}