// 8. A parking garage charges a $2.00 minimum fee to park for up to three hours. The garage charges an additional $0.50 per hour for each hour or part thereof in excess of three hours. People who park their cars for longer than 24 hours will pay $8.00 per day. Write a program that calculates and prints the parking charges. The inputs to your program are the date and time when a car enters the parking garage, and the date and time when the same car leaves the parking garage. Keep track of number of cars in the garage overloading ++ and -- operators.


#include <iostream>
#include <ctime>
using namespace std;

class ParkingGarage {
private:
    int cars;

public:
    ParkingGarage() : cars(0) {}

    double calculateCharges(tm entry, tm exit) {
        time_t entryTime = mktime(&entry);
        time_t exitTime = mktime(&exit);
        double hours = difftime(exitTime, entryTime) / 3600;

        if (hours <= 3) return 2.0;
        if (hours > 24) return 8.0 * (hours / 24);
        return 2.0 + 0.5 * (hours - 3);
    }

    ParkingGarage &operator++() {
        ++cars;
        return *this;
    }

    ParkingGarage &operator--() {
        --cars;
        return *this;
    }

    int getCars() const {
        return cars;
    }
};

int main() {
    ParkingGarage garage;
    tm entry = {0, 0, 8, 14, 6, 2024 - 1900}; // 8:00 AM, July 14, 2024
    tm exit = {0, 0, 15, 14, 6, 2024 - 1900}; // 3:00 PM, July 14, 2024

    ++garage; // car enters
    double charges = garage.calculateCharges(entry, exit);
    cout << "Parking charges: $" << charges << endl;

    --garage; // car leaves
    cout << "Number of cars in garage: " << garage.getCars() << endl;

    return 0;
}

