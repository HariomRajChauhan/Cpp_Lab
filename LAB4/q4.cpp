#include <iostream>
#include <ctime>
using namespace std;

class Date {
protected:
    int day, month, year;
public:
    Date() : day(1), month(1), year(2000) {}
    ~Date() {}
    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
    Date get() {
        return *this;
    }

    void set() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
};



class Time {
protected:
    int hour, minute, second;
public:
    Time() : hour(0), minute(0), second(0) {}
    ~Time() {}
    void display() {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }

    Time get() {
        return *this;
    }

    void set() {
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;
    }
};




class DateAndTime : public Date, public Time {
public:
    DateAndTime() : Date(), Time() {}
    ~DateAndTime() {}
    void display() {
        Date::display();
        Time::display();
    }
};



int main() {
    DateAndTime watch;
    cout << "Initial values:" << endl;
    watch.display();
    
    cout << "\nReset values:" << endl;
    // watch.set();
    watch.Time::set();

    cout << "\nUpdated values:" << endl;
    watch.display();
    
    return 0;
}
