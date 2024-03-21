#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int id;
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully." << endl;
    }

    void removeBook(int id) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) { return b.id == id; });
        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Book with ID " << id << " not found." << endl;
        }
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "The library is empty." << endl;
        } else {
            cout << "Library Catalog:" << endl;
            for (const auto& book : books) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ID: " << book.id << endl;
            }
        }
    }
};
