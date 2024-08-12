#include <iostream>
#include <cstring>

using namespace std;

class Student {
protected:
    int rn;
    char name[20];

public:
    Student(int r, const char *n) {
        this->rn = r;
        strcpy(name, n);
    }

    virtual void display() {
        cout << "Roll No: " << rn << endl;
        cout << "Name: " << name << endl;
    }
};

class ExternalExam : virtual public Student {
protected:
    int m[7];

public:
    ExternalExam(int r, const char *n, int *marks) : Student(r, n) {
        for (int i = 0; i < 7; i++) {
            m[i] = marks[i];
        }
    }

    void display() {
        Student::display();
        for (int i = 0; i < 7; i++) {
            cout << "Marks in subject " << i + 1 << ": " << m[i] << endl;
        }
    }
};

class FinalExam : virtual public Student {
protected:
    int m[7];

public:
    FinalExam(int r, const char *n, int *marks) : Student(r, n) {
        for (int i = 0; i < 7; i++) {
            m[i] = marks[i];
        }
    }

    void display() {
        Student::display();
        for (int i = 0; i < 7; i++) {
            cout << "Marks in subject " << i + 1 << ": " << m[i] << endl;
        }
    }
};

class Result : public ExternalExam, public FinalExam {
protected:
    float avgmark;

public:
    Result(int r, const char *n, int *marks1, int *marks2) 
        : Student(r, n), ExternalExam(r, n, marks1), FinalExam(r, n, marks2) {
        float sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += marks1[i] + marks2[i];
        }
        avgmark = sum / 14; // Average of all marks
    }

    void display() {
        ExternalExam::display();
        FinalExam::display();
        cout << "Average marks: " << avgmark << endl;
    }
};

int main() {
    int marks1[7] = {10, 20, 30, 40, 50, 60, 70};
    int marks2[7] = {70, 60, 50, 40, 30, 20, 10};

    Result r(1, "John Doe", marks1, marks2);
    r.display();

    return 0;
}