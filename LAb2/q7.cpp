// 7. Overload >> and << operators to input and display time.

#include <iostream>
using namespace std;

class TIME {
private:
    int hours, minutes, seconds;

public:
    TIME() : hours(0), minutes(0), seconds(0) {}
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    friend ostream &operator<<(ostream &out, const TIME &t);
    friend istream &operator>>(istream &in, TIME &t);
};

ostream &operator<<(ostream &out, const TIME &t) {
    out << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}

istream &operator>>(istream &in, TIME &t) {
    cout << "Enter hours: ";
    in >> t.hours;
    cout << "Enter minutes: ";
    in >> t.minutes;
    cout << "Enter seconds: ";
    in >> t.seconds;
    return in;
}

int main() {
    TIME t;
    cin >> t;
    cout << "The time is " << t << endl;
    return 0;
}

