#include "Header.h"

using namespace std;

int main() {

    Book library[10];

    for (int i = 0; i < 10; ++i) {
        library[i].title = "Book " + to_string(i + 1);
        library[i].author = "Author " + to_string(i + 1);
        library[i].publisher = "Publisher " + to_string(i + 1);
        library[i].genre = "Genre " + to_string(i + 1);
    }

    int choice;

    do {

        cout << "Choose an option:\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search by author\n";
        cout << "4. Search by title\n";
        cout << "5. Sort by title\n";
        cout << "6. Sort by author\n";
        cout << "7. Sort by publisher\n";
        cout << "0. Exit\n";

        cout << "Your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            int bookIndex;
            cout << "Enter the index of the book to edit: ";
            cin >> bookIndex;

            if (bookIndex >= 0 && bookIndex < 10) {
                editBook(library[bookIndex]);
                cout << "Book edited successfully!\n";
            }
            else {
                cout << "Invalid book index!\n";
            }
        }
        else if (choice == 2) {
            for (const auto& book : library) {
                printBook(book);
            }
        }
        else if (choice == 3) {
            string authorSearch;
            cout << "Enter the author to search: ";
            getline(cin >> ws, authorSearch);

            for (const auto& book : library) {
                if (book.author == authorSearch) {
                    printBook(book);
                }
            }
        }
        else if (choice == 4) {
            string titleSearch;
            cout << "Enter the title to search: ";
            getline(cin >> ws, titleSearch);

            for (const auto& book : library) {
                if (book.title == titleSearch) {
                    printBook(book);
                }
            }
        }
        else if (choice == 5) {
            sort(begin(library), end(library),
                [](const Book& a, const Book& b) {
                    return a.title < b.title;
                });
            cout << "Books sorted by title.\n";
        }
        else if (choice == 6) {
            sort(begin(library), end(library),
                [](const Book& a, const Book& b) {
                    return a.author < b.author;
                });
            cout << "Books sorted by author.\n";
        }
        else if (choice == 7) {
            sort(begin(library), end(library),
                [](const Book& a, const Book& b) {
                    return a.publisher < b.publisher;
                });
            cout << "Books sorted by publisher.\n";
        }
        else if (choice == 0) {
            cout << "Program terminated.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
