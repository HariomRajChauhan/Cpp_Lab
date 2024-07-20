// 6. Modify above class to work with compile time memory allocation i.e. with char [].

#include <iostream>
#include <cstring>
using namespace std;

class STRING {
private:
    char str[100];
    int length;

public:
    STRING() : length(0) {
        str[0] = '\0';
    }

    STRING(const char *s) {
        length = strlen(s);
        strcpy(str, s);
    }

    STRING operator+(const STRING &s) const {
        STRING result;
        result.length = length + s.length;
        strcpy(result.str, str);
        strcat(result.str, s.str);
        return result;
    }

    STRING &operator=(const STRING &s) {
        if (this == &s) return *this;
        length = s.length;
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
