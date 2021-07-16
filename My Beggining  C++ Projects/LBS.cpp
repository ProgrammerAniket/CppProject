#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Library
{
    string isbn, title, author, edition, publication;

public:
    //Functions that set the value of the private data variables.
    void setIsbn(string a) { isbn = a; }
    void setTitle(string b) { title = b; }
    void setAuthor(string c) { author = c; }
    void setEdition(string d) { edition = d; }
    void setPublication(string e) { publication = e; }

    //Functions that get the value or return the value.
    string getIsbn() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getEdition() { return edition; }
    string getPublication() { return publication; }
};

int counter = 0;

void addBooks(int counter);
void deleteBooks(int counter);
void editBooks(int counter);
void searchBooks(int counter);
void viewAllBooks(int counter);
void quit(void);

int increment(int c)
{
    c++;
    counter = c;
    return counter;
}

int decrement(int c)
{
    c--;
    counter = c;
    return counter;
}

Library books[10];

int main()
{
    string choice;
    system("CLS");
    cout << "\t\t\t WELCOME TO LIBRARY MANAGMENT SOFTWARE " << endl;
    cout << "\t\t\tTHIS SOFTWARE IS MADE BY ANIKET SHARMA " << endl;
    cout << "\t\t\t\t\t LBS " << endl;
    cout << "\n[1] ADD A BOOK " << endl;
    cout << "[2] DELETE A BOOK " << endl;
    cout << "[3] EDIT A BOOK " << endl;
    cout << "[4] SEARCH A BOOK " << endl;
    cout << "[5] VIEW ALL THE BOOKS " << endl;
    cout << "[6] QUIT " << endl;
    cout << "\nEnter your choice here : ";
    getline(cin, choice);

    if (choice == "1")
    {
        addBooks(counter);
    }
    else if (choice == "2")
    {
        deleteBooks(counter);
    }

    else if (choice == "3")
    {
        editBooks(counter);
    }

    else if (choice == "4")
    {
        searchBooks(counter);
    }

    else if (choice == "5")
    {
        viewAllBooks(counter);
    }

    else if (choice == "6")
    {
        quit();
    }

    else
    {
        main();
    }

    _getch();

    return 0;
}

void addBooks(int counter)
{
    string isbn, title, author, edition, publication;

    cout << "\t\t\t ADD BOOKS " << endl;
    if (counter == 10)
    {
        cout << "YOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE BOOKS " << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        main();
    }

    else
    {
        cout << "ENTER ISBN : " << endl;
        getline(cin, isbn);
        cout << "ENTER TITLE : " << endl;
        getline(cin, title);
        cout << "ENTER AUTHOR : " << endl;
        getline(cin, author);
        cout << "ENTER EDITION : " << endl;
        getline(cin, edition);
        cout << "ENTER PUBLICATION : " << endl;
        getline(cin, publication);
        books[counter].setIsbn(isbn);
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setEdition(edition);
        books[counter].setPublication(publication);
        increment(counter);
        cout << "BOOK ADDED SUCCESFULLY! Press any key to continue..." << endl;
        _getch();
        main();
    }
}

void deleteBooks(int counter)
{
    string isbn;
    int choice;
    cout << "DELETE BOOK\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NOT BOOKS TO BE DELETED " << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        main();
    }
    cout << "ENTER ISBN : " << endl;
    getline(cin, isbn);
    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == isbn)
        {
            cout << "BOOK FOUND!" << endl;
            cout << "Do You Want to delete this books yes[1], no[2]" << endl;
            cin >> choice;
            if (choice == 1)
            {
                books[i].setIsbn("");
                books[i].setTitle("");
                books[i].setAuthor("");
                books[i].setEdition("");
                books[i].setPublication("");
                decrement(counter);
                cout << "BOOK DELETED SUCCESFULLY!\n Press any key to continue.." << endl;
                _getch();
                main();

                for (int a = i; a < counter; a++)
                {
                    books[a] = books[a + 1];
                }

                books[9].setIsbn("");
                books[9].setTitle("");
                books[9].setAuthor("");
                books[9].setEdition("");
                books[9].setPublication("");
            }

            else
            {
                main();
            }
        }
    }
    cout << "BOOK NOT FOUND " << endl;
    cout << "Press any key to continue.." << endl;
    _getch();
    main();
}

void editBooks(int counter)
{
    string editisbn;
    string isbn, title, author, edition, publication;
    string choice;
    cout << "\t\t\tEDIT BOOKS " << endl;
    if (counter == 0)
    {
        cout << "THERE IS NO BOOKS TO BE EDITED FIRST ADD THE BOOKS!,Press any key to continue... " << endl;
        _getch();
        main();
    }

    cout << "ENTER ISBN : " << endl;
    getline(cin, editisbn);

    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == editisbn)
        {
            cout << "BOOK FOUND!" << endl;
            cout << "DO YOU WANT TO EDIT THE BOOK 1 OR 2? " << endl;
            getline(cin, choice);
            if (choice == "1")
            {
                cout << "ENTER ISBN : " << endl;
                getline(cin, isbn);
                cout << "ENTER TITLE : " << endl;
                getline(cin, title);
                cout << "ENTER AUTHOR : " << endl;
                getline(cin, author);
                cout << "ENTER EDITION : " << endl;
                getline(cin, edition);
                cout << "ENTER PUBLICATION : " << endl;
                getline(cin, publication);
                books[i].setIsbn(isbn);
                books[i].setTitle(title);
                books[i].setAuthor(author);
                books[i].setEdition(edition);
                books[i].setPublication(publication);
                cout << "Press any key to proceed.." << endl;
                _getch();
                main();
            }
            else if (choice != "1")
            {
                main();
            }
        }

        else
        {
            cout << "BOOK NOT FOUND! PRESS ANY KEY TO CONTINUE.." << endl;
            _getch();
            main();
        }
    }
}

void searchBooks(int counter)
{
    string isbn;
    int choice;
    bool print = false;
    cout << "SEARCH BOOKS " << endl;
    if (counter == 0)
    {
        cout << "THERE IS NO BOOK TO SEARCH " << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        main();
    }
    cout << "ENTER ISBN : " << endl;
    getline(cin, isbn);
    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == isbn)
        {
            cout << "BOOK FOUND " << endl;
            cout << "ISBN : " << books[i].getIsbn() << endl;
            cout << "TITLE : " << books[i].getTitle() << endl;
            cout << "AUTHOR : " << books[i].getAuthor() << endl;
            cout << "EDITION : " << books[i].getEdition() << endl;
            cout << "PUBLICATION : " << books[i].getPublication() << endl;
            print = true;
        }
        if (print)
        {
            cout << "PRESS ANY KEY TO CONTINUE..." << endl;
            _getch();
            main();
        }
        else
        {
            cout << "BOOK NOT FOUND " << endl;
            cout << "PRESS ANY KEY TO CONTINUE..." << endl;
            _getch();
            main();
        }
    }
}

void viewAllBooks(int counter)
{
    cout << "VIEW ALL THE BOOKS " << endl;
    if (counter == 0)
    {
        cout << "THERE IS NO BOOK TO VIEW FIRST ADD THE BOOK! presss any key to continue..." << endl;
        _getch();
        main();
    }
    else
    {
        for (int i = 0; i < counter; i++)
        {
            cout << "\t\t\t BOOK DETAILS " << endl;
            cout << "ISBN : " << books[i].getIsbn() << endl;
            cout << "TITLE : " << books[i].getTitle() << endl;
            cout << "AUTHOR : " << books[i].getAuthor() << endl;
            cout << "EDITION : " << books[i].getEdition() << endl;
            cout << "PUBLICATION : " << books[i].getPublication() << endl;
        }
        cout << "Press any key to continue . . .";
        _getch();
        main();
    }
}

void quit(void)
{
   exit(1);
}