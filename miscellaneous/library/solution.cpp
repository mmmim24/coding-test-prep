#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i), isAvailable(true) {}

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn
             << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool status) { isAvailable = status; }
    string getIsbn() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

class Member
{
private:
    string memberId;
    string name;
    vector<Book *> borrowedBooks;

public:
    Member(string id, string n) : memberId(id), name(n) {}

    void display() const
    {
        cout << "Member ID: " << memberId << ", Name: " << name
             << ", Borrowed Books: " << borrowedBooks.size() << endl;
    }

    void borrowBook(Book *book)
    {
        if (book->getAvailability())
        {
            borrowedBooks.push_back(book);
            book->setAvailability(false);
            cout << name << " borrowed book with ISBN: " << book->getIsbn() << endl;
        }
        else
        {
            cout << "Book is not available!" << endl;
        }
    }

    void returnBook(Book *book)
    {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it)
        {
            if ((*it)->getIsbn() == book->getIsbn())
            {
                borrowedBooks.erase(it);
                book->setAvailability(true);
                cout << name << " returned book with ISBN: " << book->getIsbn() << endl;
                return;
            }
        }
        cout << "Book not found in member's borrowed list!" << endl;
    }
};

class Librarian
{
private:
    string librarianId;
    string name;

public:
    Librarian(string id, string n) : librarianId(id), name(n) {}

    void display() const
    {
        cout << "Librarian ID: " << librarianId << ", Name: " << name << endl;
    }

    void addBook(vector<Book *> &books, Book *book)
    {
        books.push_back(book);
        cout << "Book with ISBN " << book->getIsbn() << " added to library." << endl;
    }

    void removeBook(vector<Book *> &books, string isbn)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if ((*it)->getIsbn() == isbn)
            {
                books.erase(it);
                cout << "Book with ISBN " << isbn << " removed." << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }
};

class Library
{
private:
    string name;
    vector<Book *> books;
    vector<Member *> members;
    vector<Librarian *> librarians;

public:
    Library(string n) : name(n) {}

    vector<Book *> &getBooks() { return books; }

    void display() const
    {
        cout << "Library Name: " << name << ", Books: " << books.size()
             << ", Members: " << members.size() << ", Librarians: " << librarians.size() << endl;
    }

    void addBook(Book *book) { books.push_back(book); }
    void addMember(Member *member) { members.push_back(member); }
    void addLibrarian(Librarian *librarian) { librarians.push_back(librarian); }

    void showBooks() const
    {
        cout << "\nBooks in " << name << ":" << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << i + 1 << ". ";
            books[i]->display();
        }
        cout << endl;
    }

    void showMembers() const
    {
        cout << "\nMembers in " << name << ":" << endl;
        for (int i = 0; i < members.size(); i++)
        {
            cout << i + 1 << ". ";
            members[i]->display();
        }
        cout << endl;
    }

    void showLibrarians() const
    {
        cout << "\nLibrarians in " << name << ":" << endl;
        for (int i = 0; i < librarians.size(); i++)
        {
            cout << i + 1 << ". ";
            librarians[i]->display();
        }
        cout << endl;
    }
};

int main()
{
    Library lib("City Library");
    Book *book1 = new Book("C++ Programming", "Bjarne Stroustrup", "12345");
    Book *book2 = new Book("Java Programming", "James Gosling", "67890");
    Member *member1 = new Member("M001", "Alice");
    Librarian *librarian1 = new Librarian("L001", "Bob");

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addMember(member1);
    lib.addLibrarian(librarian1);

    lib.display();
    lib.showBooks();
    lib.showMembers();
    lib.showLibrarians();

    member1->borrowBook(book1);
    book1->display();
    lib.showBooks();
    member1->returnBook(book1);
    book1->display();
    lib.showBooks();

    librarian1->removeBook(lib.getBooks(), "12345");
    librarian1->addBook(lib.getBooks(), new Book("Python Programming", "Guido van Rossum", "11223"));
    lib.showBooks();

    return 0;
}