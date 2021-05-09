//
//  PersonList.hpp
//  COEN352Assign1
//
//  Created by Miriam Lennig on 2016-09-18.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//  Class Declarations

#ifndef PersonList_hpp
#define PersonList_hpp

#include <iostream>
using namespace std;

class Person{
    string first_name;
    string last_name;
    string rand_fname ();
    string rand_lname();
    int ID;
    double studentGrades [7];
    int rand_ID ();
    double rand_studentGrade();
public:
    Person();
    string get_first_name();
    string get_last_name();
    int getID();
    void print();
};


class PersonContainer {
    Person* personArray;
    int size = 0;
public:
    PersonContainer();
    ~PersonContainer();
    PersonContainer(int);
    void addPerson(Person&);
    void deletePerson(Person&);
    void deletePerson(string, string); 
    void deletePerson(unsigned);
    void sort();
    void print();
    Person* search(unsigned);
    
};









#endif /* PersonList_hpp */
