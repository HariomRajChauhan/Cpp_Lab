/*

3. Modify Q.2 to add base class sales that holds an array of three floats so that it can record the dollar sales of a particular publication for the last three months. Include getdata() function to get three Sales amount from the user and a putdata() function to display sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data.   

*/

#include <iostream>
#include <string>

using namespace std;

class Sales{
    protected:
        float sales[3];

    public:
        Sales(float sales[3]) {
            for (int i = 0; i < 3; i++) {
                this->sales[i] = sales[i];
            }
        }

        void getdata(){
            for (int i = 0; i < 3; i++) {
                cout << "Enter sales for month " << i + 1 << ": ";
                cin >> sales[i];
            }
        }

        void putdata(){
            for (int i = 0; i < 3; i++) {
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
    Publication(string title, double price) : title(title), price(price) {}

    void getdata()
    {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata()
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
    Book(string title, double price, int page_count, float sales[3]) : Publication(title, price), Sales(sales), page_count(page_count) {}

    void getdata()
    {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata()
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
    Tape(string title, double price, int playing_time, float sales[3]) : Publication(title, price), Sales(sales), playing_time(playing_time) {}

    void getdata()
    {
        Publication::getdata();
        Sales::getdata();
        cout << "Enter playing time: ";
        cin >> playing_time;
    }

    void putdata()
    {
        Publication::putdata();
        Sales::putdata();
        cout << "Playing time: " << playing_time << endl;
    }
};

int main()
{
    float sales[3] = {0, 0, 0};
    Book b("Book", 100, 100, sales);
    Tape t("Tape", 50, 50, sales);

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

