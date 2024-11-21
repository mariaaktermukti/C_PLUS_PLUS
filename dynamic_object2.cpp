#include<bits/stdc++.h>
using namespace std;
class Cricketer
{
    public:
    int jersey_no;
    string country;
};

int main()
{
    // create dynamic object dhoni
    Cricketer* dhoni= new Cricketer();
    dhoni->jersey_no=7;
    dhoni->country= "India";
    // another dynamic oject kohli
    Cricketer* kohli= new Cricketer();

    kohli->jersey_no= dhoni->jersey_no;
    kohli->country= dhoni->country;

    delete dhoni;

    cout << "Jersey No :" << kohli->jersey_no << endl;
    cout << "Country : " << kohli->country << endl;

    delete kohli;

    return 0;
}