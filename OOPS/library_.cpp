#include<iostream>
using namespace std;
class Book
{
    private :
    string title;
    string author;
    string isbn;

    public:
    Book(string title, string author, string isbn) 
    {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Library: public Book 
{
private:
    string name;
    string address;
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library(string name, string address)
    {
        this->name = name;
        this->address = address;
    }


    void addBook(const Book& book) 
    {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = book;
        } else {
            cout << "Library is full, cannot add more books." << endl;
        }
    }

    void displayBooks() const {
        cout << "Library: " << name << ", Address: " << address << endl;
        cout << "Books in the library:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            books[i].display();
        }
    }
};

int main() {
    Library library("City Library", "123 Main St");

    Book book1("world of facts 1", "a j", "12345");
    Book book2("world war", "peter", "54312");
    Book book3("call of duty", "Lee", "98745");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    return 0;
}
