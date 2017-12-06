//****************************************************************
//
//  Author:         Beau Shirdavani
//  Date:           12-5-2017
//  Title:          Assignment 04 - part 1
//  File:           main.cpp
//
//  PROBLEM*        The code below row 194 was used in testing
//                  and it worked perfectly. However, when I reuse
//                  the same code in my menu application, the Filter
//                  function breaks.... I don't have enough time to fix this
//
//****************************************************************

#include <iostream>

#include "Contact.hpp"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

int main() {

    
    BinarySearchTree<Contact>* Book;
    Book = new BinarySearchTree<Contact>();
    
    cout << "***MY PHONEBOOK APPLICATION***" << endl;
    
    string filePATHname;
    string iMacFilePath;
    iMacFilePath = "/Users/shy/Documents/ComputerSci/cs300/ass04/phonebook1.txt";
    char selection;
    string nameADD;
    string phoneADD;
    string searchName;
    string filterName;
    while (selection != 'Q')
    {
        cout << endl << "Please choose an operation:" << endl;
        cout << "A (Add) | L (Load) | S (Search) | P (Print) | F (Filter) | Q (Quit): " ;
        cout << selection << endl;
        cin >> selection;
        //getline(cin, selection);
        cout << selection << endl;
        

        //****************************************************************
        //                                                             ADD
        if (selection == 'A')
        {
            cin.clear();
            cin.ignore();
            cout << "Enter name to add: ";
            cin >> nameADD;
            cin.clear();
            cin.ignore();
            cout << "Enter number to add: ";
            cin >> phoneADD;
            cin.clear();
            cin.ignore();
            
            Contact* tempContact;
            tempContact = new Contact();
            tempContact->setName(nameADD);
            tempContact->setNumber(phoneADD);
            Book->insert(*tempContact);
            // deallocate tempContact
            tempContact = nullptr;
            delete tempContact;
        }
        //****************************************************************
        //                                                             LOAD
        else if (selection == 'L')
        {
            cout << "Enter a filename (including the path): ";
            cin.clear();
            cin.ignore();
            cin >> filePATHname;

            ifstream filenameIN_2(filePATHname);
            if (!filenameIN_2)
            {
                cout << "cannot find file" << endl;
            }
            // get rowcount for infile
            FILE* fp;
            int rows = 1;
            int j;
//            char* fileSpec = filePATHname;
            fp = fopen(filePATHname.c_str(), "r");
            if (fp == NULL)
            {
                printf("We can't open the file.");
                fclose(fp);
                return 1;
            }
            else
            {
                while(( j=fgetc(fp))!=EOF)
                {
                    if (j == '\n')
                        rows++;
                }
                cout << "Number of rows in data file: " << rows << endl;
            }
            // import data to tree
//            BinarySearchTree<Contact>* Book;
//            Book = new BinarySearchTree<Contact>();
            string first;
            string last;
            string num;
            for ( int i = 0; i < rows; i++ ){
                Contact* tempContact;
                tempContact = new Contact();
                getline(filenameIN_2, first, ' ');
                getline(filenameIN_2, last, ' ');
                getline(filenameIN_2, num);
                tempContact->setName(first + ' ' + last);
                tempContact->setNumber(num);
                cout << "inserting: " << first << endl;
                Book->insert(*tempContact);
                // deallocate tempContact
                tempContact = nullptr;
                delete tempContact;
            }
        }
        //****************************************************************
        //                                                             SEARCH
        else if (selection == 'S')
        {
            cout << "Enter a name: ";
            cin.clear();
            cin.ignore();
            cin >> searchName;
            
            Contact* tempContact;
            tempContact = new Contact();
            tempContact->setName(searchName);
            tempContact->setNumber("fake number");
            
            cout << "Phone: " << Book->searchNEW(*tempContact).getNumber() << endl;
            
            // deallocate tempContact
            tempContact = nullptr;
            delete tempContact;
            
        }
        //****************************************************************
        //                                                             PRINT
        else if (selection == 'P')
        {
            Book->inOrder();
        }
        //****************************************************************
        //                                                             FILTER
        else if (selection == 'F')
        {
            cout << "Enter a name: ";
            cin.clear();
            cin.ignore();
            cin >> filterName;
            
            Contact* tempContact;
            tempContact = new Contact();
            tempContact->setName(filterName);
            tempContact->setNumber("fake number");
            
            Book->inOrderFILTER(*tempContact);
            
            // deallocate tempContact
            tempContact = nullptr;
            delete tempContact;
            
        }
        //else break;
    }
    
    
    cout << "Good Bye" << endl;
    
    
    
    
    
    
    

    
    // All of this code here works. But it fails when I use the exact same code in my menu above....
    
    
    
    // test import from file
//    string iMacFilePath;
//    iMacFilePath = "/Users/shy/Documents/ComputerSci/cs300/ass04/phonebook1.txt";
//    ifstream filenameIN_2(iMacFilePath);
//    if (!filenameIN_2)
//    {
//        cout << "cannot find file" << endl;
//    }
//    
//    // get rowcount for infile
//    FILE* fp;
//    int rows = 1;
//    int j;
//    fp = fopen("/Users/shy/Documents/ComputerSci/cs300/ass04/phonebook1.txt", "r");
//    if (fp == NULL)
//    {
//        printf("We can't open the file.");
//        fclose(fp);
//        return 1;
//    }
//    else
//    {
//        while(( j=fgetc(fp))!=EOF)
//        {
//            if (j == '\n')
//                rows++;
//        }
//        cout << "Number of rows: " << rows << endl;
//    }
//    
//    // import data to tree
//    BinarySearchTree<Contact>* Book;
//    Book = new BinarySearchTree<Contact>();
//    string first;
//    string last;
//    string num;
//    for ( int i = 0; i < rows; i++ ){
//        Contact* tempContact;
//        tempContact = new Contact();
//        getline(filenameIN_2, first, ' ');
//        getline(filenameIN_2, last, ' ');
//        getline(filenameIN_2, num);
//        tempContact->setName(first + ' ' + last);
//        tempContact->setNumber(num);
//        Book->insert(*tempContact);
//        
//        // deallocate tempContact
//        tempContact = nullptr;
//        delete tempContact;
//    }
//    
//    // test print the tree
//    cout << "printing IN Order traversal of book" << endl;
//    Book->inOrder();
//    // printing count of contacts
//    cout << "printing size of tree book" << endl;
//    cout << "nodeCount: " << Book->nodeCount() << endl;
//    
//    // test filtered print up until function
//    cout << "printing InOrderFILTER()" << endl << endl;
//    Contact* maria;
////    maria = new Contact("MARIA DAVIS", 6297086);
//    maria = new Contact();
//    maria->setNumber("973437");
//    maria->setName("MARIA DAVIS");
//    cout << endl << "filter: " << *maria << endl << endl;
//    Book->inOrderFILTER(*maria);
    
    return 0;
}



