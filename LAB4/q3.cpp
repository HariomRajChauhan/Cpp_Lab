#include <iostream>
#include <string>

using namespace std;

class Sales
{
protected:
    float sales[3] = {0, 0, 0};

public:
    Sales() {}

    void getdata()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Sales for month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

class Publication
{
protected:
    string title;
    double price;

public:
    Publication(string title = "", double price = 0.0) : title(title), price(price) {}

    void getdata()
    {
        cout << "Enter title: ";
        cin.ignore();        // Ignore newline character from previous input
        getline(cin, title); // Use getline to read the entire line
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication, public Sales
{
protected:
    int page_count;

public:
    Book(string title = "", double price = 0.0, int page_count = 0)
        : Publication(title, price), page_count(page_count) {}

    void getdata()
    {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata() const
    {
        Publication::putdata();
        Sales::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

class Tape : public Publication, public Sales
{
protected:
    int playing_time;

public:
    Tape(string title = "", double price = 0.0, int playing_time = 0)
        : Publication(title, price), playing_time(playing_time) {}

    void getdata()
    {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter playing time: ";
        cin >> playing_time;
    }

    void putdata() const
    {
        Publication::putdata();
        Sales::putdata();
        cout << "Playing time: " << playing_time << endl;
    }
};

int main()
{
    Book b;
    Tape t;

    cout << "Book details: " << endl;
    b.getdata();
    cout << endl;
    b.putdata();
    cout << endl;

    cout << "Tape details: " << endl;
    t.getdata();
    cout << endl;
    t.putdata();
    cout << endl;

    return 0;
}
