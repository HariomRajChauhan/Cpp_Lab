// 4. Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.

// class to class data type conversion
// source class = Time24
// destination class = Time12

// source class --> destination class


#include <iostream>

using namespace std;

class Time24
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time24() : hours(0), minutes(0), seconds(0) {}
    Time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void Display()
    {
        cout << "Time24: " << hours << ":" << minutes << ":" << seconds << endl;
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
};

class Time12
{
private:
    int hours;
    int minutes;
    int seconds;
    string meridiem;

public:
    Time12() : hours(0), minutes(0), seconds(0), meridiem("AM") {}
    Time12(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        if (hours >= 12)
        {
            meridiem = "PM";
            hours -= 12;
        }
        else
        {
            meridiem = "AM";
        }
    }

    void Display()
    {
        cout << "Time12: " << hours << ":" << minutes << ":" << seconds << " " << meridiem << endl;
    }

    Time12(const Time24 &t)
    {
        hours = t.getHours();
        minutes = t.getMinutes();
        seconds = t.getSeconds();
        if (hours >= 12)
        {
            meridiem = "PM";
            hours -= 12;
        }
        else
        {
            meridiem = "AM";
        }
    }
};

int main()
{
    Time24 t(13, 30, 45);
    Time12 t2 = t;
    t.Display();
    t2.Display();

    return 0;
}
