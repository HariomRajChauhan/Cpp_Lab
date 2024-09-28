#include <iostream>
using namespace std;

// Function to demonstrate pass by reference
void incrementByReference(int &ref) {
    ref++;
}

// Function to demonstrate return by reference
int& getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    // Demonstrate pass by reference
    int a = 5;
    cout << "Before increment: " << a << endl;
    incrementByReference(a);
    cout << "After increment: " << a << endl;

    // Demonstrate return by reference
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Before modification: " << arr[2] << endl;
    getElement(arr, 2) = 100;  // Modify the element at index 2
    cout << "After modification: " << arr[2] << endl;

    return 0;
}