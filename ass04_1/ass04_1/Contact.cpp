//
//  Contact.cpp
//  ass04_1
//
//  Created by Shy on 12/5/17.
//  Copyright © 2017 Shy. All rights reserved.
//

#include "Contact.hpp"


#include <iostream>
#include <string>
using namespace std;

//======================================================
// define the overloaded << operator
//======================================================
ostream& operator<<(ostream& os, /*const*/ Contact& c){
    os << c.Name << " " << c.Phone << endl;
    return os;
}

//======================================================
// define the new constructor
//======================================================
Contact::Contact(string name, string phone){
    Name = name;
    Phone = phone;
}

//======================================================
// setName
//======================================================
void Contact::setName(string nIN){
    Name = nIN;
}

//======================================================
// setNumber
//======================================================
void Contact::setNumber(string pIN){
    Phone = pIN;
}

//======================================================
// getName()
//======================================================
string Contact::getName(){
    return Name;
}
//======================================================
// getNumber()
//======================================================
string Contact::getNumber(){
    return Phone;
}

//****************************************************************
// define the overloaded < operator
//****************************************************************
bool Contact::operator<(Contact& item){
    if ( this->getName() < item.getName() ){
        return true;
    }
    else{
        return false;
    }
}

//****************************************************************
// define the overloaded > operator
//****************************************************************
bool Contact::operator>(Contact& item){
    if ( this->getName() > item.getName() ){
        return true;
    }
    else{
        return false;
    }
}

//****************************************************************
// define the overloaded == operator
//****************************************************************
bool Contact::operator==(Contact& item){
    if ( this->getName() == item.getName() ){
        return true;
    }
    else{
        return false;
    }
}

//****************************************************************
// define the overloaded != operator
//****************************************************************
bool Contact::operator!=(Contact& item){
    if ( this->getName() != item.getName() ){
        return true;
    }
    else{
        return false;
    }
}


