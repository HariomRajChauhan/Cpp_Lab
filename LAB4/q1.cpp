/*
1.Assume class person stores the Name, Age and ID, class employee stores the designation, basic salary, total overtime(hr) in a month and hourly rate and class computedSalary stores the total salary of the employee. Implement above concept using appropriate inheritance.

*/




#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string id;

public:
    Person(string name, int age, string id) : name(name), age(age), id(id) {}


    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee : public Person {
protected:
    string designation;
    double basic_salary;
    int total_overtime;
    double hourly_rate;

public:
    Employee(string name, int age, string id, string designation, double basic_salary, int total_overtime, double hourly_rate)
        : Person(name, age, id), designation(designation), basic_salary(basic_salary), total_overtime(total_overtime), hourly_rate(hourly_rate) {}

        void display() {
            Person::display();
            cout << "Designation: " << designation << endl;
            cout << "Basic Salary: " << basic_salary << endl;
            cout << "Total Overtime: " << total_overtime << endl;
            cout << "Hourly Rate: " << hourly_rate << endl;
        }
};

class ComputedSalary : public Employee {
public:
    ComputedSalary(string name, int age, string id, string designation, double basic_salary, int total_overtime, double hourly_rate)
        : Employee(name, age, id, designation, basic_salary, total_overtime, hourly_rate) {}

    double compute_salary() {
        double overtime_pay = total_overtime * hourly_rate;
        double total_salary = basic_salary + overtime_pay;
        return total_salary;
    }

    void display() {
        Employee::display();
        cout << "Total Salary of " << name << " is " << compute_salary() << endl;
    }
};

int main() {

    ComputedSalary cs("Rajesh", 25, "1", "Manager", 50000, 10, 1000);

    cs.display();



    return 0;
}

