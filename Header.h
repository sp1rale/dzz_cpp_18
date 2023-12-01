#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Publisher: " << book.publisher << endl;
    cout << "Genre: " << book.genre << endl;
    cout << "------------------------\n";
}

void editBook(Book& book) {
    cout << "Enter new title: ";
    getline(cin >> ws, book.title);

    cout << "Enter new author: ";
    getline(cin >> ws, book.author);

    cout << "Enter new publisher: ";
    getline(cin >> ws, book.publisher);

    cout << "Enter new genre: ";
    getline(cin >> ws, book.genre);
}


#endif 