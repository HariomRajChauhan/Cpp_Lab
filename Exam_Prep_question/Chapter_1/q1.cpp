#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    void Display()
    {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }

    void Input()
    {
        cout << "Enter Time: " << endl;
        cout << "Enter Hours: ";
        cin >> hours;
        cout << "Enter Minutes: ";
        cin >> minutes;
        cout << "Enter Seconds: ";
        cin >> seconds;
        cout << endl;
    }

    void AddTime(Time t1, Time t2)
    {
        seconds = t1.seconds + t2.seconds;
        minutes = seconds / 60;
        seconds = seconds % 60;

        minutes = minutes + t1.minutes + t2.minutes;
        hours = minutes / 60;
        minutes = minutes % 60;

        hours = hours + t1.hours + t2.hours;
    }

    void SubtractTime(Time t1, Time t2)
    {

        int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
        int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

        int diff = totalSeconds1 - totalSeconds2;

        if (diff < 0)
        {
            cout << "Time is Negative. Setting to Zero." << endl;
            hours = minutes = seconds = 0;
        }
        else
        {
            hours = diff / 3600;
            diff = diff % 3600;
            minutes = diff / 60;
            seconds = diff % 60;
        }
    }
};

int main()
{
    Time t1, t2, t3, t4;

    t1.Input();
    t2.Input();

    t3.AddTime(t1, t2);

    t3.Display();

    t4.SubtractTime(t1, t2);

    t4.Display();

    return 0;
}