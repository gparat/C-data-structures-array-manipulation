// Name        : Contact.h
// Author      : Giovanni Parati
// Date           : 10/9/2020
// class for an individual Contact object.
#include <string>
using namespace std;

class Contact
{
private:
    string name;
    int phone;

public:
    Contact();
    Contact(int p, string n);
    //~Contact();

    string print();
    void setName(string s);
    void setPhone(int i);

    string getName();
    int getPhone();
};