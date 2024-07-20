// 5. Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.

#include <iostream>
using namespace std;

class Time12 {
public:
    int hour, minute, second;
    string period;

    Time12(int hour, int minute, int second, string period) : hour(hour), minute(minute), second(second), period(period) {}

    void to24HourFormat() {
        int hour24 = hour;
        if (period == "PM") {
            if (hour != 12) hour24 += 12;
        } else if (hour == 12) hour24 = 0;
        cout << "12-hour format: " << hour << ":" << minute << ":" << second << " " << period << " = 24-hour format: " << hour24 << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int hour, minute, second;
    string period;
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter minute: ";
    cin >> minute;
    cout << "Enter second: ";
    cin >> second;
    cout << "Enter period (AM/PM): ";
    cin >> period;

    Time12 time(hour, minute, second, period);
    time.to24HourFormat();
    return 0;
}