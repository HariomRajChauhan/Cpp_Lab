
// 5. Create a 'STRING' class which char* and length as data member and
// overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations. Use
// constructor and destructor whenever suitable.


#include <iostream>
#include <cstring>
using namespace std;

class STRING {
private:
    char *str;
    int length;

public:
    STRING() : str(nullptr), length(0) {}
    STRING(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    ~STRING() {
        delete[] str;
    }

    STRING operator+(const STRING &s) const {
        char *temp = new char[length + s.length + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        STRING result(temp);
        delete[] temp;
        return result;
    }

    STRING &operator=(const STRING &s) {
        if (this == &s) return *this;
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
        return *this;
    }

    bool operator==(const STRING &s) const {
        return strcmp(str, s.str) == 0;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    STRING s1("Hello, ");
    STRING s2("World!");

    STRING s3 = s1 + s2;
    s3.display();

    STRING s4;
    s4 = s1;
    s4.display();

    if (s1 == s4)
        cout << "s1 and s4 are equal" << endl;
    else
        cout << "s1 and s4 are not equal" << endl;

    return 0;
}

