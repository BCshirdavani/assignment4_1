//
//  Contact.hpp
//  ass04_1
//
//  Created by Shy on 12/5/17.
//  Copyright © 2017 Shy. All rights reserved.
//

#ifndef Contact_hpp
#define Contact_hpp




#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class Contact{
    string Name;
    string Phone;
public:
    // default constructor
    Contact(){};
    // Make new constructor
    Contact(string name, string phone);
    // OVERLAOD the << operator to print Contacts
    friend ostream& operator<< (ostream& os, /*const*/ Contact& c);
    // setName
    void setName(string);
    // setNumber
    void setNumber(string);
    // getName()
    string getName();
    // getNumber()
    string getNumber();
    // OVERLOAD < operator
    bool operator<(Contact&);
    // OVERLOAD > operator
    bool operator>(Contact&);
    // OVERLOAD == operator
    bool operator==(Contact&);
    // OVERLOAD != operator
    bool operator!=(Contact&);
};





#endif /* Contact_hpp */
