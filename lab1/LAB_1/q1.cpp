/*
Problem 1:
Create a 'DISTANCE' class with :
- feet and inches as data members
- member function to input distance
- member function to output distance
- member function to add two distance objects
Write a main function to create objects of DISTANCE class. Input two distances and output the sum
*/

#include<iostream>

using namespace std;

class DISTANCE{
    private:
        int Feet,Inches;

    public:
        void Input_Distance(){
            cout << "Enter Feet : ";
            cin >>Feet;

            cout << "Enter Inches : ";
            cin >> Inches;

        }

        void Output_Distance(){
            cout << "Feet is : " << Feet <<endl <<"Inches is : " <<Inches << endl;
        }

        DISTANCE Add_Distance(DISTANCE& d1,DISTANCE& d2){
            DISTANCE d3;
            d3.Feet = d1.Feet + d2.Feet;
            
            
            d3.Inches = d1.Inches + d2.Inches;

            if (d3.Inches >12)
            {
                d3.Inches = d3.Inches%12;
                d3.Feet = (d3.Feet + d3.Inches)/12;
            }

        return d3;
}

};



int main(){
    DISTANCE d1,d2,d3; 
    d1.Input_Distance();
    d2.Input_Distance();
    d3 = d3.Add_Distance(d1,d2);
    d3.Output_Distance();



    return 0;
}