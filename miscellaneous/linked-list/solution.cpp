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
        std::cout << "DoublyLinkedList created from constructor." << std::endl;
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
        std::cout << "DoublyLinkedList deleted from destructor." << std::endl;
    }
    Node *headNode();
    Node *tailNode();
    void deleteHead();
    void deleteTail();

public:
    void prepend(int value)
    {
        Node *newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

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
        if (current == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }
        std::cout << "Traversing from head: ";
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void traverseFromTail()
    {
        Node *current = tail;
        if (current == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }
        std::cout << "Traversing from tail: ";
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->prev;
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
    std::cout << "Head node value after append: " << list->headNode()->value << std::endl;
    std::cout << "Tail node value after append: " << list->tailNode()->value << std::endl;
    list->traverseFromHead();
    list->traverseFromTail();
    list->prepend(0);
    list->prepend(-1);
    std::cout << "Head node value after prepend: " << list->headNode()->value << std::endl;
    std::cout << "Tail node value after prepend: " << list->tailNode()->value << std::endl;
    list->traverseFromHead();
    list->traverseFromTail();
    list->deleteHead();
    std::cout << "Head node value after delete head: " << list->headNode()->value << std::endl;
    list->traverseFromHead();
    list->traverseFromTail();
    list->deleteTail();
    std::cout << "tail: " << list->tailNode()->value << std::endl;
    list->traverseFromHead();
    list->traverseFromTail();
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
    list2.traverseFromTail();
    std::cout << "head: " << list2.headNode()->value << std::endl;
    std::cout << "tail: " << list2.tailNode()->value << std::endl;
    list2.prepend(0);
    list2.prepend(-1);
    list2.traverseFromHead();
    list2.traverseFromTail();
    std::cout << "head: " << list2.headNode()->value << std::endl;
    std::cout << "tail: " << list2.tailNode()->value << std::endl;
    list2.deleteHead();
    list2.deleteTail();
    list2.traverseFromHead();
    list2.traverseFromTail();
    std::cout << "head: " << list2.headNode()->value << std::endl;
    std::cout << "tail: " << list2.tailNode()->value << std::endl;
    std::cout << "Deleting list..." << std::endl;
    std::cout << "Successfully deleted" << std::endl;
    return 0;
}

Node *DoublyLinkedList::headNode()
{
    if (head == nullptr)
    {
        std::cout << "List is empty, no head node." << std::endl;
        throw std::runtime_error("List is empty");
    }
    return head;
}

Node *DoublyLinkedList::tailNode()
{
    if (tail == nullptr)
    {
        std::cout << "List is empty, no tail node." << std::endl;
        throw std::runtime_error("List is empty");
    }
    return tail;
}

void DoublyLinkedList::deleteHead()
{
    if (head == nullptr)
    {
        std::cout << "List is empty, cannot delete head." << std::endl;
        return;
    }
    Node *current = head->next;
    head->next = nullptr;
    if (current != nullptr)
    {
        current->prev = nullptr;
    }
    delete head;
    head = current;
    if (head == nullptr)
    {
        tail = nullptr;
    }
}

void DoublyLinkedList::deleteTail()
{
    if (tail == nullptr)
    {
        std::cout << "List is empty, cannot delete tail." << std::endl;
        return;
    }
    Node *current = tail->prev;
    tail->prev = nullptr;
    if (current != nullptr)
    {
        current->next = nullptr;
    }
    delete tail;
    tail = current;
    if (tail == nullptr)
    {
        head = nullptr;
    }
}