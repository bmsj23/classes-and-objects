#include <iostream>
#include <iomanip>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book() : title(""), author(""), year(0) {}

    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    int getYear()
    {
        return year;
    }

    void displayBook()
    {
        cout << left << setw(30) << title
             << left << setw(25) << author
             << left << setw(9) << "\t" << year << endl;
    }

    void setBookDetails(string t, string a, int y)
    {
        title = t;
        author = a;
        year = y;
    }
};

class Library
{
private:
    Book books[50];
    int bookCount;

public:
    Library() : bookCount(5)
    {
        books[0].setBookDetails("Pride and Prejudice", "Jane Austen", 1813);
        books[1].setBookDetails("Moby Dick", "Herman Melville", 1851);
        books[2].setBookDetails("Lolita", "Vladimir Nabokov", 1955);
        books[3].setBookDetails("Hamlet", "William Shakespeare", 1600);
        books[4].setBookDetails("The Lord of the Rings", "J. R. R. Tolkien", 1937);
    }

    void addBook(Book book)
    {
        if (bookCount < 50)
        {

            books[bookCount] = book;
            bookCount++;

            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Library is full. Unable to add more books." << endl;
        }
    }

    void displayBookHeader()
    {

        cout << "Title\t\t\t\t" << "Author\t\t\t\t" << "Year\t\t\t\t";
        cout << endl;
    }

    void displayBooks()
    {

        if (bookCount == 0)
        {
            cout << "No books in the library." << endl;
        }
        else
        {

            cout << "Books in the library: " << endl
                 << endl;

            displayBookHeader();

            for (int i = 0; i < bookCount; i++)
            {

                books[i].displayBook();
            }
        }
    }

    void searchBookByTitle(string title)
    {

        bool found = false;

        for (int i = 0; i < bookCount; i++)
        {

            if (books[i].getTitle() == title)
            {

                cout << endl;
                displayBookHeader();
                cout << endl;

                books[i].displayBook();
                found = true;

                break;
            }
        }
        if (!found)
        {
            cout << "Book not found." << endl;
        }
    }
};

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int year;

            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter year: ";
            cin >> year;

            Book newBook(title, author, year);
            library.addBook(newBook);
            break;
        }
        case 2:
        {
            library.displayBooks();
            break;
        }
        case 3:
        {
            string searchTitle;

            cout << "Enter the title of the book to search: ";
            cin.ignore();
            getline(cin, searchTitle);

            library.searchBookByTitle(searchTitle);

            break;
        }
        case 4:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}
