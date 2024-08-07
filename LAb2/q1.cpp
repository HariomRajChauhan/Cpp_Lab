// To write a C++ program to swap two private data members using friend functions.


#include<iostream>

using namespace std;

class SWAPDATA{
    private:
        int FirstData;
        int SecondData;

    public:
        void GetData(){
            cout << "Enter the first data: ";
            cin >> FirstData;
            cout << "Enter the second data: ";
            cin >> SecondData;
        }

        void DisplayData(){
            cout << "First Data is: " << FirstData << endl;
            cout << "Second Data is: " << SecondData << endl;
        }

        friend void SwapData(SWAPDATA &obj);
};

void SwapData(SWAPDATA &obj){
    int temp;
    temp = obj.FirstData;
    obj.FirstData = obj.SecondData;
    obj.SecondData = temp;
}

int main(){
    
    SWAPDATA obj12;

    obj12.GetData();
    cout << "Before Swapping: " << endl;
    obj12.DisplayData();
    SwapData(obj12);
    cout << "After Swapping: " << endl;
    obj12.DisplayData();



    return 0;
}