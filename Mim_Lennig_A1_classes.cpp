//
//  PersonList.cpp
//  COEN352Assign1
//
//  Created by Miriam Lennig on 2016-09-18.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//  Class Definitions

#include "Mim_Lennig_A1_header.hpp"
#include <vector>
#include <string>

string Person::get_first_name(){
    return first_name;
}

string Person::get_last_name(){
    return last_name;
}

int Person::getID(){
    return ID;
}

string Person::rand_fname(){
    // Returns a random first name
    vector<string> firstName = {"Jim", "James", "Janet", "Kill" , "Jessica", "Buffy", "Willow", "Tara", "Xander", "Angel", "Lana", "Spike", "Jennifer", "Regina", "Emma", "Rupert", "Malcom", "Zoë", "Hoban", "Inara", "Jayne", "Kaylee", "Simon", "Saffron", "Bridget", "Yolanda", "Shepard"};
    
    int ifirst;
    
    ifirst = rand() % firstName.size();
    return firstName[ifirst];
    
}

string Person::rand_lname(){
    // Returns a random last name
    vector<string> lastName  = {"Quinn", "Quicksilver", "Hargrave", "Grave", "Jones", "Summers", "Rosenberg", "Harris", "Vampire", "Maclay", "Parrilla", "Marsters", "Morrison", "Mills", "Swan", "Giles", "Reynolds", "Washburne", "Serra", "Cobb", "Frye", "Tam", "Book"};
    
    int ilast;
    
    ilast = rand() % lastName.size();
    return lastName[ilast];
}


int Person::rand_ID(){
    // Returns a random ID number
    return (rand() % 1000000) + 1000000;
}

double Person::rand_studentGrade(){
    // Returns a random student grade
    return ((rand() % 10001) / 100.0);  
}


Person::Person(){
    // This is the default constructor, it assigns random values for first name, last name, ID number
    
    first_name = rand_fname();
    last_name = rand_lname();
    ID = rand_ID();
    for( int i = 0; i < 7; i ++)
        studentGrades[i] = rand_studentGrade();
}

void Person::print(){
    cout << "Name: " << first_name << " " << last_name << endl;
    cout << "Student ID: " << ID << endl;
    cout << "Student Grades: ";
    for(int i = 0; i < 7; i++)
        cout << studentGrades[i] << "   ";
    cout << endl;
}


PersonContainer::PersonContainer(int num_persons){
    size = num_persons;
    personArray = new Person[size];
    
}

PersonContainer::PersonContainer(){
    size = 0; 
}

PersonContainer::~PersonContainer(){
    delete[] personArray;
}

void PersonContainer::addPerson(Person& x){
    // Adds a Person object to personArray container
    if (size != 0){
        // Generate a new array that is the size of the old array + 1
        Person* newPersonArray = new Person [size + 1];
        
        for(int i = 0; i < size; i ++)
            newPersonArray[i] = personArray[i];
        
        // Append x at the end of the array and then increase variable size by 1
        newPersonArray[size++] = x;
        
        delete [] personArray;
        personArray = newPersonArray;
    }
    else {
        Person* newPersonArray = new Person[1];
        size = 1;
        newPersonArray[0] = x;
        personArray = newPersonArray;
    }
}

void PersonContainer::print(){
    for (int i = 0; i < size; i++){
        cout << i + 1 << ": " << endl;
        (personArray + i)->print();
        cout << endl;
    }
}


void PersonContainer::deletePerson(Person& x){
    // Deletes a Person object from personArray container
    for(int i = 0; i < size; i ++){
        // Check to see if the ID of the Person object passed in matches the ID
        // of a person object held in the container
        if (x.getID() == personArray[i].getID()){
            // Decrease variable size by 1
            size -= 1;
            // Generate a new array that is one space smaller
            // than the old array
            Person* newPersonArray = new Person[size];
            
            // Fill newly sized array with elements
            // from old array up until Person to be deleted
            for (int k = 0; k < i; k++)
                newPersonArray[k] = personArray[k];
            
            // Overwrite the Person being deleted
            // and shift the rest of the elements over
            for(int k = i; k < size; k++)
                newPersonArray[k] = personArray[k + 1];
            
            delete[] personArray;
            personArray = newPersonArray;
            
            return;
        }
    }
}

void PersonContainer::deletePerson(string fname, string lname){
    for(int i = 0; i < size; i ++){
        
        string firstname = personArray[i].get_first_name();
        string lastname = personArray[i].get_last_name();
        
        if ((fname == firstname) && (lname == lastname) ){
            size -= 1;
            Person* newPersonArray = new Person[size];
            
            for (int k = 0; k < i; k++)
                newPersonArray[k] = personArray[k];
            
            for(int k = i; k < size; k++)
                newPersonArray[k] = personArray[k + 1];
            
            delete[] personArray;
            personArray = newPersonArray;
            
            return;

        }
    }
}

Person* PersonContainer::search(unsigned idNumber){
    for(int i = 0; i < size; i++){
        if(idNumber == personArray[i].getID()){
            cout << "The person searched for is: " << endl;
            personArray[i].print();
            return personArray + i;
        }
    }
    return 0;
}

void PersonContainer::sort(){
    // Sorts Person objects by ID number
    // Begin at index 0 and increment index once inner loop has run thru
    for (int j = 0; j < size; j ++){
        // Begin at index j and compare ID# of index j and i as i is incremented
        for (int i = j; i < size; i ++){
            // Check if the ID# of index j is larger than that of index i
            if (personArray[j].getID() > personArray[i].getID()){
                // Place larger Person in a dummy variable
                Person dummy = personArray[j];
                // Copy smaller Person into larger Person's place
                personArray[j] = personArray[i];
                // Copy larger person into smaller Person's place
                personArray[i] = dummy;
            }
        }
    }
}

void PersonContainer::deletePerson(unsigned idNumber){
    for(int i = 0; i < size; i++){
        if(idNumber == personArray[i].getID())
            deletePerson (personArray[i]);
    }
}



