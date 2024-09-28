#include<iostream>

using namespace std;

class SimpleClass{
    private:
        int a;

    public:
        SimpleClass(int i=0){
            a = i;
            a++;
        }

        void display(){
            std::cout << "Value is " << a << std::endl;
        }       
};
int main(){

    int n;
    std::cout << "Enter number of Obj ";
    cin >> n;

    SimpleClass *obj = new SimpleClass[n];

    for (int i = 0; i < n; i++)
    {
        obj[i] = SimpleClass(i+1);
        
    }
    for (int i = 0; i < n; i++)
    {
        obj[i].display();
        
    }

    delete obj;
    


    


    return 0;
}