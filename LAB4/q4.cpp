/*
Question no.4.

class Date
{
    int day, month, year;

public:
    Date();
    ~Date();
    void display(); // displays the date
    Date get();     // accesses the date members
    void set();     // sets the date members
};
class Time
{
    int hour;
    int minute;
    int second;

public:
    Time();
    ~Time();
    void display(); // displays the time
    Time get();     // accesses the time members
    void set();     // sets the time members
};
class DateAndTime : public Date, public Time
{
public:
    void display(); // prints date and time
};
a.Define an instance object of class DateTime called Watch.
b.Write a main() function that would initialize the values through the constructor functions, and then allows them to be reset through the set() functions.Be sure and display the results following the constructor before you use the set functions.
c.Through the use of the display() function, the time and date are to be displayed.Note that the display() functions in all three classes need to be defined, as well as the constructor and all the access functions.

*/


#include <iostream>
#include <ctime>
using namespace std;

class Date
{
protected:
    int day, month, year;

public:
    Date() : day(1), month(1), year(2000) {}
    ~Date() {}
    void display()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
    Date get()
    {
        return *this;
    }

    void set()
    {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
};

class Time
{
protected:
    int hour, minute, second;

public:
    Time() : hour(0), minute(0), second(0) {}
    ~Time() {}
    void display()
    {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }

    Time get()
    {
        return *this;
    }

    void set()
    {
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;
    }
};

class DateAndTime : public Date, public Time
{
public:
    DateAndTime() : Date(), Time() {}
    ~DateAndTime() {}
    void display()
    {
        Date::display();
        Time::display();
    }
};

int main()
{
    DateAndTime watch;
    cout << "Initial values:" << endl;
    watch.display();

    cout << "\nReset values:" << endl;
    watch.Date::set();
    watch.Time::set();

    cout << "\nUpdated values:" << endl;
    watch.display();

    return 0;
}
