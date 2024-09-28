#include<iostream>

using namespace std;

int main(){
    
    int *p = new int;

    cout << "Enter the value : ";
    cin >> *p ;

    cout << "The value is : " << *p;

    delete p;

    cout << "Hello";

    return 0;
}