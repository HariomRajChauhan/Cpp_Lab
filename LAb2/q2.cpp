

#include <iostream>
using namespace std;

class NepaliCurrency;

class USCurrency
{
private:
    float dollars;

public:
    USCurrency(float d) : dollars(d) {}

    float getDollars()
    {
        return dollars;
    }

    friend bool operator==(NepaliCurrency&, USCurrency&);
    friend bool operator!=(NepaliCurrency&, USCurrency&);
    friend bool operator<(NepaliCurrency&, USCurrency&);
    friend bool operator<=(NepaliCurrency&, USCurrency&);
    friend bool operator>(NepaliCurrency&, USCurrency&);
    friend bool operator>=(NepaliCurrency&, USCurrency&);

    friend bool operator==(USCurrency&,NepaliCurrency&);
    friend bool operator!=(USCurrency&,NepaliCurrency&);
    friend bool operator<(USCurrency&,NepaliCurrency&);
    friend bool operator<=(USCurrency&,NepaliCurrency&);
    friend bool operator>(USCurrency&,NepaliCurrency&);
    friend bool operator>=(USCurrency&,NepaliCurrency&);
};


class NepaliCurrency
{
private:
    float nrs;

public:
    NepaliCurrency(float n) : nrs(n) {}

    float getNRSInDollar()
    {
        return nrs/101.36;
    }

    friend bool operator==(NepaliCurrency &, USCurrency &);
    friend bool operator!=(NepaliCurrency &, USCurrency &);
    friend bool operator<(NepaliCurrency &, USCurrency &);
    friend bool operator<=(NepaliCurrency &, USCurrency &);
    friend bool operator>(NepaliCurrency &, USCurrency &);
    friend bool operator>=(NepaliCurrency &, USCurrency &);

    friend bool operator==(USCurrency &,NepaliCurrency &);
    friend bool operator!=(USCurrency &,NepaliCurrency &);
    friend bool operator<(USCurrency &,NepaliCurrency &);
    friend bool operator<=(USCurrency &,NepaliCurrency &);
    friend bool operator>(USCurrency &,NepaliCurrency &);
    friend bool operator>=(USCurrency &,NepaliCurrency &);
};



bool operator==(USCurrency & usd,NepaliCurrency &nrs){
    return (usd.getDollars() == nrs.getNRSInDollar());
}
bool operator!=(USCurrency &usd,NepaliCurrency &nrs){
    return (usd.getDollars() != nrs.getNRSInDollar());
}
bool operator<(USCurrency &usd,NepaliCurrency &nrs){
    return (usd.getDollars() < nrs.getNRSInDollar());
}
bool operator<=(USCurrency &usd,NepaliCurrency &nrs){
    return (usd.getDollars() <= nrs.getNRSInDollar());
}
bool operator>(USCurrency &usd,NepaliCurrency &nrs){
    return (usd.getDollars() > nrs.getNRSInDollar());
}
bool operator>=(USCurrency &usd,NepaliCurrency &nrs){
    return (usd.getDollars() >= nrs.getNRSInDollar());
}




bool operator==(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() == usd.getDollars());
}
bool operator!=(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() != usd.getDollars());
}
bool operator<(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() < usd.getDollars());
}
bool operator<=(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() <= usd.getDollars());
}
bool operator>(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() > usd.getDollars());
}
bool operator>=(NepaliCurrency &nrs,USCurrency &usd){
    return (nrs.getNRSInDollar() >= usd.getDollars());
}



int main()
{
    USCurrency usd(5);         // 5 USD
    NepaliCurrency nrs(56.8); // 506.8 NRS

    if(usd > nrs){
        cout << "USD is greater than NRS" << endl;
    }

    else if(usd < nrs){
        cout << "USD is less than NRS" << endl;
    }

    else if (usd == nrs){
        cout << "USD is equal to NRS" << endl;
    }

    if (usd >= nrs){
        cout << "USD is greater than or equal to NRS" << endl;
    }

    if (usd <= nrs){
        cout << "USD is less than or equal to NRS" << endl;
    }

    if (usd != nrs){
        cout << "USD is not equal to NRS" << endl;
    }

    else {
        cout << "BANG BANG";
    }

    

    return 0;
}
