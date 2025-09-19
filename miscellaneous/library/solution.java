import java.util.ArrayList;
import java.util.List;

class Book {
    private String title;
    private String author;
    private String isbn;
    private boolean isAvailable;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isAvailable = true;
    }

    public void display() {
        System.out.println("Title: " + title + ", Author: " + author + ", ISBN: " + isbn 
                          + ", Available: " + (isAvailable ? "Yes" : "No"));
    }

    public boolean isAvailable() { return isAvailable; }
    public void setAvailable(boolean available) { isAvailable = available; }
    public String getIsbn() { return isbn; }
    public String getTitle() { return title; }
    public String getAuthor() { return author; }
}

class Member {
    private String memberId;
    private String name;
    private List<Book> borrowedBooks;

    public Member(String memberId, String name) {
        this.memberId = memberId;
        this.name = name;
        this.borrowedBooks = new ArrayList<>();
    }

    public void display() {
        System.out.println("Member ID: " + memberId + ", Name: " + name 
                          + ", Borrowed Books: " + borrowedBooks.size());
    }

    public void borrowBook(Book book) {
        if (book.isAvailable()) {
            borrowedBooks.add(book);
            book.setAvailable(false);
            System.out.println(name + " borrowed book with ISBN: " + book.getIsbn());
        } else {
            System.out.println("Book is not available!");
        }
    }

    public void returnBook(Book book) {
        if (borrowedBooks.remove(book)) {
            book.setAvailable(true);
            System.out.println(name + " returned book with ISBN: " + book.getIsbn());
        } else {
            System.out.println("Book not found in member's borrowed list!");
        }
    }
}

class Librarian {
    private String librarianId;
    private String name;

    public Librarian(String librarianId, String name) {
        this.librarianId = librarianId;
        this.name = name;
    }

    public void display() {
        System.out.println("Librarian ID: " + librarianId + ", Name: " + name);
    }

    public void addBook(List<Book> books, Book book) {
        books.add(book);
        System.out.println("Book with ISBN " + book.getIsbn() + " added to library.");
    }

    public void removeBook(List<Book> books, String isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books.get(i).getIsbn().equals(isbn)) {
                books.remove(i);
                System.out.println("Book with ISBN " + isbn + " removed.");
                return;
            }
        }
        System.out.println("Book with ISBN " + isbn + " not found!");
    }
}

class Library {
    private String name;
    private List<Book> books;
    private List<Member> members;
    private List<Librarian> librarians;

    public Library(String name) {
        this.name = name;
        this.books = new ArrayList<>();
        this.members = new ArrayList<>();
        this.librarians = new ArrayList<>();
    }

    public void display() {
        System.out.println("Library Name: " + name + ", Books: " + books.size() 
                          + ", Members: " + members.size() + ", Librarians: " + librarians.size());
    }

    public void addBook(Book book) { books.add(book); }
    public void addMember(Member member) { members.add(member); }
    public void addLibrarian(Librarian librarian) { librarians.add(librarian); }

    public List<Book> getBooks() { return books; }

    public void showBooks() {
        System.out.println("\nBooks in " + this.name + ":");
        for (int i = 0; i < books.size(); i++) {
            System.out.print((i + 1) + ".");
            books.get(i).display();
        }
        System.out.println();
    }

    public void showMembers() {
        System.out.println("\nMembers in " + this.name + ":");
        for (int i = 0; i < members.size(); i++) {
            System.out.print((i + 1) + ".");
            members.get(i).display();
        }
        System.out.println();
    }

    public void showLibrarians() {
        System.out.println("\nLibrarians in " + this.name + ":");
        for (int i = 0; i < librarians.size(); i++) {
            System.out.print((i + 1) + ".");
            librarians.get(i).display();
        }
        System.out.println();
    }
}

public class solution {
    public static void main(String[] args) {
        Library lib = new Library("City Library");
        Book book1 = new Book("C++ Programming", "Bjarne Stroustrup", "12345");
        Book book2 = new Book("Java Programming", "James Gosling", "67890");
        Member member1 = new Member("M001", "Alice");
        Librarian librarian1 = new Librarian("L001", "Bob");

        lib.addBook(book1);
        lib.addBook(book2);
        lib.addMember(member1);
        lib.addLibrarian(librarian1);

        lib.display();
        lib.showBooks();
        lib.showMembers();
        lib.showLibrarians();

        member1.borrowBook(book1);
        book1.display();
        lib.showBooks();
        member1.returnBook(book1);
        book1.display();
        lib.showBooks();

        librarian1.removeBook(lib.getBooks(), "12345");
        librarian1.addBook(lib.getBooks(), new Book("Python Programming", "Guido van Rossum", "11223"));
        lib.showBooks();
    }
}