#include<iostream>

using namespace std;

class Employee{
    private:
        int ENumber;
        string EName;
        float Basic_Salary;
        float DA;
        float Income_Tax;
        float Net_Salary;

    public:

        void ReadDataMembers(){
            cout << "Enter Employee Number: ";
            cin >> ENumber;
            cout << "Enter Employee Name: ";
            cin >> EName;
            cout << "Enter Basic Salary: ";
            cin >> Basic_Salary;
        }

        void PrintDataMembers(){


            cout << "Employee Number :" << ENumber << endl;
            cout << "Employee Name :" << EName << endl;
            cout << "Basic Salary :" << Basic_Salary << endl;
            cout << "Employee DA :" << DA << endl;
            cout << "Employee Income Tax :" << Income_Tax << endl;
            cout << "Employee Net Salary :" << Net_Salary << endl;
        }

        void Calculate();

};

void Employee::Calculate(){
    DA = 0.52 * Basic_Salary;
    float Gross_Salary = Basic_Salary + DA;
    Income_Tax = 0.30 * Gross_Salary;
    Net_Salary = Gross_Salary - Income_Tax;

}


int main(){
    Employee E[100];
    int n;
    cout << "How Many Members:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        E[i].ReadDataMembers();
        E[i].Calculate();
    }

    for (int i = 0; i < n; i++)
    {
        E[i].PrintDataMembers();
    }
    
    



    return 0;
}