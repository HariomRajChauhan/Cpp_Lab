#include<iostream>
#include<string>

using namespace std;

class Person {
    private:
        string name;
        string dob;
        
    public:
        void getdata() {
            cout << "Enter the name of the person: ";
            cin >> name;
            cout << "Enter the date of birth of the person (DD-MM-YYYY): ";
            cin >> dob;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Date of Birth: " << dob << endl;
        }

        friend void search(Person p[], int n);
};

void search(Person p[], int n) {
    string date;
    cout << "Enter the date of birth to search: ";
    cin >> date;
    for (int i = 0; i < n; i++) {
        if (p[i].dob == date) {
            cout << "Name: " << p[i].name << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    Person* p = new Person[n];
    for (int i = 0; i < n; i++) {
        p[i].getdata();
    }

    search(p, n);

    delete[] p;
    return 0;
}