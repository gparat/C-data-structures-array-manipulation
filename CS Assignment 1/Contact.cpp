// Name        : Contact.cpp
// Author      : Giovanni Parati
// Date           : 10/9/2020
// class for an individual Contact object.

#include <iostream>
#include "Contact.h"

Contact::Contact()
{
    name = "NoName";
    phone = 1111;
}

Contact::Contact(int p, string n): phone(p), name(n){}

//Contact::~Contact(){}

void Contact::setPhone(int i){
    phone=i;
}
void Contact::setName(string s){
    name=s;
}
int Contact::getPhone(){
    return phone;
}
string Contact::getName(){
    return name;
}
string Contact::print()
{
    return name+" "+to_string(phone);
}