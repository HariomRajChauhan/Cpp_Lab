#include<iostream>

using namespace std;

class UsCurrency{
    private:
        float dollars;

    public:
        UsCurrency(float d):dollars(d){}

        float getDollars(){
            return dollars;
        }

        friend bool operator==(NepaliCurrency&, UsCurrency&);
        friend bool operator!=(NepaliCurrency&, UsCurrency&);
        friend bool operator<(NepaliCurrency&, UsCurrency&);
        friend bool operator<=(NepaliCurrency&, UsCurrency&);
        friend bool operator>(NepaliCurrency&, UsCurrency&);
        friend bool operator>=(NepaliCurrency&, UsCurrency&);

        friend bool operator==(UsCurrency&, NepaliCurrency&);
        friend bool operator!=(UsCurrency&, NepaliCurrency&);
        friend bool operator<(UsCurrency&, NepaliCurrency&);
        friend bool operator<=(UsCurrency&, NepaliCurrency&);
        friend bool operator>(UsCurrency&, NepaliCurrency&);
        friend bool operator>=(UsCurrency&, NepaliCurrency&);
        
};

class NepaliCurrency{
    private:
        float nrs;

    public:
        NepaliCurrency(float n):nrs(n){}

        float getNRS(){
            return nrs;
        }

        friend bool operator==(NepaliCurrency&, UsCurrency&);
        friend bool operator!=(NepaliCurrency&, UsCurrency&);
        friend bool operator<(NepaliCurrency&, UsCurrency&);
        friend bool operator<=(NepaliCurrency&, UsCurrency&);
        friend bool operator>(NepaliCurrency&, UsCurrency&);
        friend bool operator>=(NepaliCurrency&, UsCurrency&);

        friend bool operator==(UsCurrency&, NepaliCurrency&);
        friend bool operator!=(UsCurrency&, NepaliCurrency&);
        friend bool operator<(UsCurrency&, NepaliCurrency&);
        friend bool operator<=(UsCurrency&, NepaliCurrency&);
        friend bool operator>(UsCurrency&, NepaliCurrency&);
        friend bool operator>=(UsCurrency&, NepaliCurrency&);

};

bool operator==(NepaliCurrency &n, UsCurrency &u){
    return n.nrs == u.dollars * 118.0;
}

bool operator!=(NepaliCurrency &n, UsCurrency &u){
    return n.nrs != u.dollars * 118.0;
}

bool operator<(NepaliCurrency &n, UsCurrency &u){
    return n.nrs < u.dollars * 118.0;
}

bool operator<=(NepaliCurrency &n, UsCurrency &u){
    return n.nrs <= u.dollars * 118.0;
}

bool operator>(NepaliCurrency &n, UsCurrency &u){
    return n.nrs > u.dollars * 118.0;
}

bool operator>=(NepaliCurrency &n, UsCurrency &u){
    return n.nrs >= u.dollars * 118.0;
}

bool operator==(UsCurrency &u, NepaliCurrency &n){
    return u.dollars == n.nrs / 118.0;
}

bool operator!=(UsCurrency &u, NepaliCurrency &n){
    return u.dollars != n.nrs / 118.0;
}

bool operator<(UsCurrency &u, NepaliCurrency &n){
    return u.dollars < n.nrs / 118.0;
}

bool operator<=(UsCurrency &u, NepaliCurrency &n){
    return u.dollars <= n.nrs / 118.0;
}

bool operator>(UsCurrency &u, NepaliCurrency &n){
    return u.dollars > n.nrs / 118.0;
}

bool operator>=(UsCurrency &u, NepaliCurrency &n){
    return u.dollars >= n.nrs / 118.0;
}




int main(){
    UsCurrency usd(1);
    NepaliCurrency nrs(118);
    cout << (usd == nrs) << endl;
    cout << (usd != nrs) << endl;
    cout << (usd < nrs) << endl;
    cout << (usd <= nrs) << endl;
    cout << (usd > nrs) << endl;
    cout << (usd >= nrs) << endl;
    return 0;
}