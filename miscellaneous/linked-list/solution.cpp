#include <iostream>
struct Node
{
    int value;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head = nullptr, *tail = nullptr;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        std::cout << "DoublyLinkedList created." << std::endl;
    }
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        std::cout << "DoublyLinkedList deleted." << std::endl;
    }

public:
    void append(int value)
    {
        Node *newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void traverseFromHead()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    int n;
    std::cin >> n;
    DoublyLinkedList *list = new DoublyLinkedList();
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        list->append(value);
    }
    list->traverseFromHead();
    std::cout << "Deleting list..." << std::endl;
    delete list;
    std::cout << "Successfully deleted" << std::endl;

    std::cout << "\nCreating another list...\n\n";

    DoublyLinkedList list2;
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        list2.append(value);
    }
    list2.traverseFromHead();
    std::cout << "Deleting list..." << std::endl;
    std::cout << "Successfully deleted" << std::endl;
    return 0;
}