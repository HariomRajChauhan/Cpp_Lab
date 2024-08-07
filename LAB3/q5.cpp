// 5. Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.

// class to class data type conversion
// source class = Time12
// destination class = Time24

// source class --> destination class

#include <iostream>

using namespace std;

class Time12
{
private:
    int hours;
    int minutes;
    int seconds;
    string meridiem;

public:
    Time12() : hours(0), minutes(0), seconds(0), meridiem("AM") {}
    Time12(int h, int m, int s, string mer) : hours(h), minutes(m), seconds(s), meridiem(mer) {}

    void Display()
    {
        cout << "Time12: " << hours << ":" << minutes << ":" << seconds << " " << meridiem << endl;
    }

    int getHours() const
    {
        return hours;
    }
    int getMinutes() const
    {
        return minutes;
    }
    int getSeconds() const
    {
        return seconds;
    }
    string getMeridiem() const
    {
        return meridiem;
    }
};


class Time24
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time24() : hours(0), minutes(0), seconds(0) {}
    Time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time24(const Time12 &t12)
    {
        hours = t12.getHours();
        minutes = t12.getMinutes();
        seconds = t12.getSeconds();
        if (t12.getMeridiem() == "PM")
        {
            hours += 12;
        }
    }

    void Display()
    {
        cout << "Time24: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};



int main()
{
    Time12 t12(5, 30, 45, "PM");
    t12.Display();

    Time24 t24 = t12;
    t24.Display();

    return 0;
}