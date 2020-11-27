// Name        : main.cpp
// Author      : Giovanni Parati
// Date           : 10/9/2020
// Description : reads an input file (phonebook) into an array and allows operations to be performed on the array. 
//Can add, delete, search, list. Saves changes to the original phonebook file on exit.

#include <iostream>
#include <fstream>
#include "Contacts.h"
using namespace std;

int main(){
    const int sizeMod=1000;//array extends by this ammount
    const string fname="phonebook.txt";
    int arraySize=150000;//initial size, can be increased
    Contacts contacts (new Contact[arraySize], arraySize);//stores the phonebook
    ifstream ifile;
    ifile.open(fname);
    string line;
    string n1;
    string n2;
    int num;
    char cmd;
    string tcmd;
    string cname1;
    string cname2;
    string cname;
    int cnum;
    
    while(!ifile.eof()){//reading the file 3 tokens at a time, then setting up the corresponding contact object in the array
        ifile>>n1>>n2>>num;
        contacts.add(n1+" "+n2, num);
    }
    
    cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
    cout<<"Please choose an operation:"<<endl;
    while(cmd!='Q'){//process use input until exit command
        cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit): ";
        cin>>tcmd;
        cmd=tcmd.at(0);
        if(cmd=='A'){//add
        cout<<"Enter name: ";
        cin>>cname1>>cname2;
        cout<<"Enter phone: ";
        cin>>cnum;
        cname=cname1+" "+cname2;
        contacts.add(cname, cnum);
        }
        else if(cmd=='D'){//delete
            cout<<"Enter name: ";
            cin>>cname1>>cname2;
            cname=cname1+" "+cname2;
            contacts.del(cname);
        } 
        else if(cmd=='L'){//list
            contacts.print();
        }
        else if(cmd=='S'){//search
            cout<<"Enter name: ";
            cin>>cname1>>cname2;
            cname=cname1+" "+cname2;
            int pn=contacts.search(cname);
            if(pn==-1&&contacts.getLastSearched()==-1){
                cout<<"Name not found."<<endl;
            }
            else{
                cout<<"Phone Number: "<<pn<<endl;
            }
        }
        else if(cmd!='Q'){
            cout<<"Invalid command"<<endl;
        }
    }
    ofstream outfile("phonebook.txt");
    
    int ct;
    for(ct=0; ct<contacts.getItems()-1; ct++){//save to file
        outfile<<contacts.getContact(ct).print();
        outfile<<endl;
    }
    outfile<<contacts.getContact(ct).print();

    cout<<"end"<<endl;
    return 0;
}
