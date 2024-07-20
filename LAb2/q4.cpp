// 4. Create a class called 'TIME' that has
// - three integer data members for hours, minutes and seconds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format


#include <iostream>
using namespace std;

class TIME {
private:
    int hours, minutes, seconds;

public:
    TIME() : hours(0), minutes(0), seconds(0) {}
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    TIME operator+(const TIME &t) const {
        int s = seconds + t.seconds;
        int m = minutes + t.minutes + s / 60;
        int h = hours + t.hours + m / 60;
        return TIME(h % 24, m % 60, s % 60);
    }

    TIME operator-(const TIME &t) const {
        int tot1 = hours * 3600 + minutes * 60 + seconds;
        int tot2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = abs(tot1 - tot2);
        return TIME(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    bool operator>(const TIME &t) const {
        if (hours > t.hours) return true;
        if (hours == t.hours && minutes > t.minutes) return true;
        if (hours == t.hours && minutes == t.minutes && seconds > t.seconds) return true;
        return false;
    }

    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    TIME t1(5, 45, 30);
    TIME t2(2, 30, 45);

    TIME t3 = t1 + t2;
    TIME t4 = t1 - t2;

    cout << "t1 + t2 = "; t3.display();
    cout << "t1 - t2 = "; t4.display();

    if (t1 > t2)
        cout << "t1 is greater than t2" << endl;
    else
        cout << "t1 is not greater than t2" << endl;

    return 0;
}
