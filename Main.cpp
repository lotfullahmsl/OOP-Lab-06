#include <limits>

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if input fails
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip to next iteration of the loop
        }

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, newBook.title);
                cout << "Enter Author: ";
                getline(cin, newBook.author);
                cout << "Enter Book ID: ";
                cin >> newBook.id;
                library.addBook(newBook);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of the book to remove: ";
                cin >> id;
                library.removeBook(id);
                break;
            }
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }

    return 0;
}

