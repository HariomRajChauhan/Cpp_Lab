

#include <iostream>
using namespace std;

class NepaliCurrency;

class USCurrency
{
private:
    float dollars;

public:
    USCurrency(float d) : dollars(d) {}

    float getDollars() const
    {
        return dollars;
    }

    friend bool operator==(NepaliCurrency, USCurrency);
    friend bool operator!=(NepaliCurrency, USCurrency);
    friend bool operator<(NepaliCurrency, USCurrency);
    friend bool operator<=(NepaliCurrency, USCurrency);
    friend bool operator>(NepaliCurrency, USCurrency);
    friend bool operator>=(NepaliCurrency, USCurrency);

    friend bool operator==(USCurrency,NepaliCurrency);
    friend bool operator!=(USCurrency,NepaliCurrency);
    friend bool operator<(USCurrency,NepaliCurrency);
    friend bool operator<=(USCurrency,NepaliCurrency);
    friend bool operator>(USCurrency,NepaliCurrency);
    friend bool operator>=(USCurrency,NepaliCurrency);
};


class NepaliCurrency
{
private:
    float nrs;

public:
    NepaliCurrency(float n) : nrs(n) {}

    float getNRS() const
    {
        return nrs;
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



friend bool operator==(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars == nrs.getNRS);
}
bool operator!=(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars != nrs.getNRS);
}
bool operator<(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars < nrs.getNRS);
}
bool operator<=(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars <= nrs.getNRS);
}
bool operator>(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars > nrs.getNRS);
}
bool operator>=(USCurrency usd,NepaliCurrency nrs){
    return (usd.getDollars >= nrs.getNRS);
}




bool operator==(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS == usd.getDollars);
}
bool operator!=(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS != usd.getDollars);
}
bool operator<(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS < usd.getDollars);
}
bool operator<=(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS <= usd.getDollars);
}
bool operator>(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS > usd.getDollars);
}
bool operator>=(NepaliCurrency nrs,USCurrency usd){
    return (nrs.getNRS >= usd.getDollars);
}



int main()
{
    USCurrency usd(5);         // 5 USD
    NepaliCurrency nrs(506.8); // 506.8 NRS

    

    return 0;
}
