package linkedlist;

public class Node {
    public int value;
    public Node prev;
    public Node next;

    public Node(int value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}