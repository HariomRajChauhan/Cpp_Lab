// 4. Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.


#include <iostream>
using namespace std;

class Time24 {
public:
    int hour, minute, second;

    Time24(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

    void to12HourFormat() {
        string period = "AM";
        int hour12 = hour;
        if (hour >= 12) {
            period = "PM";
            if (hour > 12) hour12 -= 12;
        }
        if (hour == 0) hour12 = 12;
        cout << "24-hour format: " << hour << ":" << minute << ":" << second << " = 12-hour format: " << hour12 << ":" << minute << ":" << second << " " << period << endl;
    }
};

int main() {
    int hour, minute, second;
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter minute: ";
    cin >> minute;
    cout << "Enter second: ";
    cin >> second;


    Time24 time(hour, minute, second);
    time.to12HourFormat();
    return 0;
}
