// Name        : Contacts.h
// Author      : Giovanni Parati
// Date           : 10/9/2020
// class for an array of Contact objects.

#include <string>
#include "Contact.h"
using namespace std;

class Contacts
{
private:
    Contact* array;
    int size;
    int sizemod;
    int items;
    int lastSearched;
public:
    Contacts();
    Contacts(Contact* c, int size);
    void print();
    void extend();
    void add(string name, int phone);
    void del(string name);
    int search(string name);
    int getItems();
    int getLastSearched();
    Contact getContact(int pos);
};