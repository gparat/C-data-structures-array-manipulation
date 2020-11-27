// Name        : Contacts.cpp
// Author      : Giovanni Parati
// Date           : 10/9/2020
// class for an array of Contact objects.

#include <iostream>
#include "Contacts.h"
using namespace std;

Contacts::Contacts()
{
    array = new Contact[0];
    size=0;
    sizemod=0;
    items=0;
    lastSearched=0;
}

Contacts::Contacts(Contact* c, int s)
{
    size=s;//number of spots in the array
    sizemod=s;//used to extend the array when needed, should not be changed
    array=c;//the phonebook array
    items=0;//number of contacts that have been added to the phonebook
    lastSearched=0;//stores an index to be remembered, set by search()
}

Contact Contacts::getContact(int pos){//returns a contact by index
    return array[pos];
}

int Contacts::getItems(){
    return items;
}

int Contacts::getLastSearched(){
    return lastSearched;
}

//return a phone # based on name
//also mark the index of that name. retrurns and sets lastSearched to -1 if name not found
int Contacts::search(string s){
    int pnum=0;
    int k=0;
    bool found=false;
    while(k<items&&!found){
        if(s.compare(array[k].getName())==0){
            lastSearched=k;
            pnum=array[k].getPhone();
            found=true;
        }
        k++;
    }
    if(!found){
        lastSearched=-1;
        return -1;
    }
    return pnum;
}

//print the entire phonebook to the console
void Contacts::print(){
    for(int i=0; i<items; i++){
        cout<<array[i].print()<<endl;
    }
}

//extend the array
void Contacts::extend(){
    Contact *temp=new Contact[size+sizemod];
    for(int i=0; i<size; i++){
        temp[i]=array[i];
    }
    delete[] array;
    array=temp;
    size+=sizemod;
}

//adds a contact to the end of the phonebook. if its index would be too high, also call extend()
void Contacts::add(string s, int n){
    if(items>=size){
        extend();
    }
    array[items].setName(s);
    array[items].setPhone(n);
    items++;
}

//remove a contact by creating a new array that doesn't have that contact
void Contacts::del(string s){
    search(s);//sets lastSearched
    if(lastSearched==-1){
        cout<<"Name not found."<<endl;
    }
    else{
        Contact *temp=new Contact[size];
        int i=0;
        int k=0;
        while(i<items){
            if(i!=lastSearched){
                temp[k]=array[i];
                k++;
            }
            i++;
        }
        items--;
        delete[] array;
        array=temp;
    }
}