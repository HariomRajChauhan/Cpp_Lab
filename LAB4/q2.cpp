/*

2. Create a class publication that stores the title and price of a publication. From this class derive two classes:book, which adds a page count and tape, which adds a playing time in minutes. Each of these three classes should have getdata() function to get its data from the user at the keyboard and putdata() function to display its data.

*/


#include <iostream>
#include <string>

using namespace std;

class Publication{
    protected:
        string title;
        double price;

    public:
        Publication(string title, double price) : title(title), price(price) {}

        void getdata(){
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter price: ";
            cin >> price;
        }

        void putdata(){
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};

class Book : public Publication{
    protected:
        int page_count;

    public:
        Book(string title, double price, int page_count) : Publication(title, price), page_count(page_count) {}

        void getdata(){
            Publication::getdata();
            cout << "Enter page count: ";
            cin >> page_count;
        }

        void putdata(){
            Publication::putdata();
            cout << "Page count: " << page_count << endl;
        }
};

class Tape : public Publication{
    protected:
        int playing_time;

    public:
        Tape(string title, double price, int playing_time) : Publication(title, price), playing_time(playing_time) {}

        void getdata(){
            Publication::getdata();
            cout << "Enter playing time: ";
            cin >> playing_time;
        }

        void putdata(){
            Publication::putdata();
            cout << "Playing time: " << playing_time << endl;
        }
};

int main(){
    Book b("Book", 100, 100);
    b.getdata();
    b.putdata();
    cout << endl;

    Tape t("Tape", 200, 200);
    t.getdata();
    t.putdata();

    return 0;
}