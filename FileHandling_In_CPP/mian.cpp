#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Define the Book class
class Book
{
public:
    string ISBN;
    string bookTitle;
    string author;
    int numberOfCopies;

    // Constructors
    Book() {}
    Book(string isbn, string title, string auth, int copies)
        : ISBN(isbn), bookTitle(title), author(auth), numberOfCopies(copies) {}

    // Convert a Book object to a comma-separated string for file storage
    string toString() const
    {
        return ISBN + "," + bookTitle + "," + author + "," + to_string(numberOfCopies);
    }

    // Convert a comma-separated string to a Book object
    static Book fromString(const string &line)
    {
        stringstream ss(line);
        string isbn, title, auth, copies;
        getline(ss, isbn, ',');
        getline(ss, title, ',');
        getline(ss, auth, ',');
        getline(ss, copies, ',');
        return Book(isbn, title, auth, stoi(copies));
    }
};

// Define the Library class
class Library
{
private:
    const string filename = "catalog.txt"; // File to maintain the catalog

    // Helper function to load books from file into a vector
    vector<Book> loadFromFile()
    {
        vector<Book> books;
        ifstream file(filename);
        string line;
        while (getline(file, line))
        {
            books.push_back(Book::fromString(line));
        }
        file.close();
        return books;
    }

    // Helper function to save the vector of books back to file
    void saveToFile(const vector<Book> &books)
    {
        ofstream file(filename, ios::trunc); // add the data at endof the file
        for (const auto &book : books)
        {
            file << book.toString() << endl;
        }
        file.close();
    }

    // Helper function to check for duplicate ISBN
    bool isDuplicateISBN(const string &isbn)
    {
        vector<Book> books = loadFromFile();
        for (const auto &book : books)
        {
            if (book.ISBN == isbn)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to add a new book to the catalog
    void addNewBook(const string &isbn, const string &title, const string &author, int copies)
    {
        if (isDuplicateISBN(isbn))
        {
            cout << "Error: Duplicate ISBN. Book not added." << endl;
            return;
        }
        Book newBook(isbn, title, author, copies);
        vector<Book> books = loadFromFile();
        books.push_back(newBook);
        saveToFile(books);
        cout << "Book added successfully." << endl;
    }

    // Function to issue a book from the catalog
    void issueBook(const string &isbn)
    {
        vector<Book> books = loadFromFile();
        for (auto &book : books)
        {
            if (book.ISBN == isbn)
            {
                if (book.numberOfCopies > 0)
                {
                    book.numberOfCopies--;
                    saveToFile(books);
                    cout << "Book issued successfully." << endl;
                }
                else
                {
                    cout << "Error: No copies available." << endl;
                }
                return;
            }
        }
        cout << "Error: Book not found." << endl;
    }

    // Function to return a book to the catalog
    void returnBook(const string &isbn)
    {
        vector<Book> books = loadFromFile();
        for (auto &book : books)
        {
            if (book.ISBN == isbn)
            {
                
                book.numberOfCopies++;
                saveToFile(books);
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Error: Book not found." << endl;
    }

    // Function to update the details of a book in the catalog
    void updateBookDetails(const string &isbn, const string &newTitle, const string &newAuthor, int newCopies)
    {
        vector<Book> books = loadFromFile();
        for (auto &book : books)
        {
            if (book.ISBN == isbn)
            {
                book.bookTitle = newTitle;
                book.author = newAuthor;
                book.numberOfCopies = newCopies;
                saveToFile(books);
                cout << "Book details updated successfully." << endl;
                return;
            }
        }
        cout << "Error: Book not found." << endl;
    }

    // Function to delete a book from the catalog
    void deleteBook(const string &isbn)
    {
        vector<Book> books = loadFromFile();
        auto it = books.begin();
        while (it != books.end())
        {
            if (it->ISBN == isbn)
            {
                if (it->numberOfCopies == 0)
                {
                    books.erase(it);
                    saveToFile(books);
                    cout << "Book deleted successfully." << endl;
                }
                else
                {
                    cout << "Error: Cannot delete book with copies available." << endl;
                }
                return;
            }
            ++it;
        }
        cout << "Error: Book not found." << endl;
    }

    // Function to display all books in the catalog
    void displayAllBooks()
    {
        vector<Book> books = loadFromFile();
        if (books.empty())
        {
            cout << "No books in the catalog." << endl;
            return;
        }
        for (const auto &book : books)
        {
            cout << "-------------------------" << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Book Title: " << book.bookTitle << endl;
            cout << "Author: " << book.author << endl;
            cout << "Number of Copies: " << book.numberOfCopies << endl;
            cout << "-------------------------" << endl;
        }
    }
};

// Example usage
int main()
{
    Library library;
    int choice;
    string isbn, title, author;
    int copies;

    while (true)
    {
        cout << "1. Add New Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Update Book Details" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Display All Books" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("CLS"); // Clear the console screen

        switch (choice)
        {
        case 1:
            cout << "Enter ISBN: ";
            cin >> isbn;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Number of Copies: ";
            cin >> copies;
            library.addNewBook(isbn, title, author, copies);
            break;
        case 2:
            cout << "Enter ISBN of the book you want to issue: ";
            cin >> isbn;
            library.issueBook(isbn);
            break;
        case 3:
            cout << "Enter ISBN of the book you want to return: ";
            cin >> isbn;
            library.returnBook(isbn);
            break;
        case 4:
            cout << "Enter ISBN of the book you want to update: ";
            cin >> isbn;
            cout << "Enter New Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter New Author Name: ";
            getline(cin, author);
            cout << "Enter New Number of Copies: ";
            cin >> copies;
            library.updateBookDetails(isbn, title, author, copies);
            break;
        case 5:
            cout << "Enter ISBN of the book you want to delete: ";
            cin >> isbn;
            library.deleteBook(isbn);
            break;
        case 6:
            system("CLS");
            library.displayAllBooks();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}