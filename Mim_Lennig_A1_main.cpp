//
//  main.cpp
//  COEN352Assign1
//
//  Created by Miriam Lennig on 2016-09-18.
//  Copyright © 2016 Mim Lennig. All rights reserved.
//

#include <iostream>
#include <string>
#include "Mim_Lennig_A1_header.hpp"
using namespace std;

void divider(){
    cout << "******************************************************************************************************************************************" << endl << endl;
}

int main() {
    divider();
    cout << "Creating people and printing them out: " << endl << endl;
    divider();
    
    //srand(int(time(NULL)));     //Initialize random number generator with random seed
    Person* x = new Person;
    Person* y = new Person;
    Person* z = new Person;
    cout << "Person x: " << endl;
    x->print();
    cout << endl;
    cout << "Person y: " << endl;
    y->print();
    cout << endl;
    cout << "Person z: " << endl;
    z->print();
    cout << endl;
    
    divider();
    cout << "Creating a container of type PersonContainer and adding objects of type Person to it: " << endl << endl;
    divider();
    
    PersonContainer person_list;
    
    cout << "person_list.addPerson(*x): " << endl;
    person_list.addPerson(*x);
    person_list.print();
    
    cout << endl;
    
    cout << "person_list.addPerson(*y): " << endl;
    person_list.addPerson(*y);
    person_list.print();
    cout << endl;
    
    cout << "person_list.addPerson(*z): " << endl;
    person_list.addPerson(*z);
    person_list.print();
    
    divider();
    cout << "Testing delete function: " << endl << endl;
    divider();
    
    cout << "person_list.deletePerson(*x): " << endl;
    person_list.deletePerson(*x);
    person_list.print();
    
    cout << "person_list.deletePerson(*z): " << endl;
    person_list.deletePerson(*z);
    person_list.print();
    
    cout << "person_list.addPerson(*x): " << endl;
    person_list.addPerson(*x);
    person_list.print();
    

    cout << "person_list.deletePerson(*y): " << endl;
    person_list.deletePerson(*y);
    person_list.print();
    
    cout << "person_list.addPerson(*y): " << endl;
    person_list.addPerson(*y);
    person_list.print();
    
    cout << "person_list.addPerson(*z): " << endl;
    person_list.addPerson(*z);
    person_list.print();
    
    divider();
    
    cout << "person_list.deletePerson(y->get_first_name(), y->get_last_name()): " << endl;
    person_list.deletePerson(y->get_first_name(), y->get_last_name());
    person_list.print();
    
    divider();
    
    cout << "person_list.addPerson(*y): " << endl;
    person_list.addPerson(*y);
    person_list.print();
    
    divider();
    cout << "Testing sort function: " << endl << "person_list.sort();" << endl << endl;
    divider();
    person_list.sort();
    person_list.print();
    
    
    
    divider();
    cout << "Testing search function: " << endl << endl;
    divider();
    
    divider();
    cout << "person_list.search(1484492);" << endl <<  "person_list.search(1650073);" << endl << "person_list.search(1817709);" << endl <<endl;
    divider();
    
    person_list.search(1484492);
    cout << endl;
    person_list.search(1650073);
    cout << endl;
    person_list.search(1817709);
    cout << endl;

    
    divider();
    cout << "PersonContainer can hold any number of persons: " << endl << endl;
    divider();
    
    cout << "person_list2 = PersonContainer(5): "<< endl;
    PersonContainer person_list2 = PersonContainer(5);
    person_list2.print();
    
    divider();
    cout << "Sorting Person objects by Student ID: " << endl;
    cout << "person_list2.sort(): " << endl << endl;
    divider();
    
    person_list2.sort();
    person_list2.print();
    
    divider();
    
    cout << "person_list2.deletePerson(1042009): "<< endl;
    person_list2.deletePerson(1042009);
    person_list2.print();
    
    divider();
    cout << "Sorting Person objects by Student ID: " << endl;
    cout << "person_list2.sort(): " << endl << endl;
    divider();
    
    person_list2.sort();
    person_list2.print();
    
    divider();
    
    cout << "person_list2.deletePerson(1938554): "<< endl;
    person_list2.deletePerson(1938554);
    person_list2.print();
    
    divider();
    cout << "Sorting Person objects by Student ID: " << endl;
    cout << "person_list2.sort(): " << endl << endl;
    divider();
    
    person_list2.sort();
    person_list2.print();
    
    divider();
    
    int num_persons;
    cout << "num_persons = (rand() % 21)" << endl;
    num_persons = (rand() % 21);
    cout << "num_persons: " << num_persons << endl << endl;
    
    cout << "person_list3 = PersonContainer(num_persons): "<< endl;
    PersonContainer person_list3 = PersonContainer(num_persons);
    person_list3.print();
    
    divider();
    cout << "Sorting Person objects by Student ID: " << endl;
    cout << "person_list3.sort(): " << endl << endl;
    divider();
    
    person_list3.sort();
    person_list3.print();

    divider();
    cout << "person_list3.search(1907920): " <<endl << endl;
    divider();
    person_list3.search(1907920);
    
    divider();
    cout << "PersonContainer(num_persons);" << endl;
    cout << "PersonContainer person_listTest = PersonContainer(num_persons);" << endl;
    cout << "person_listTest.print(); " << endl << endl;
    divider();
    
    num_persons = 20000;
    PersonContainer person_listTest = PersonContainer(num_persons);
    person_listTest.print();
    
    divider();
    cout << "person_listTest.sort();" << endl;
    cout << "person_listTest.print();" << endl << endl;
    divider();
    
    person_listTest.sort();
    person_listTest.print();
    
    divider();
    cout << "person_listTest.deletePerson(Kill, Hargrave);" << endl <<  "person_listTest.deletePerson(Janey, Serra);" << endl << "person_listTest.deletePerson(Willow, Quinn);" << endl <<endl;
    divider();
    person_listTest.deletePerson("Kill", "Hargrave");
    person_listTest.deletePerson("Janet", "Serra");
    person_listTest.deletePerson("Willow", "Quinn");
    person_listTest.deletePerson(1080168);
    person_listTest.deletePerson(1080205);
    person_listTest.deletePerson(1080331);
    person_listTest.deletePerson(1080360);
    person_listTest.sort();
    person_listTest.print();
    
    divider();
    cout << "person_listTest.search(1993145);" << endl <<  "person_listTest.search(1993145);" << endl << "person_listTest.search(1993238);" << endl << "person_listTest.search(1993252);" << endl << "person_listTest.search(1993304);"  << endl <<endl;
    divider();
    
    person_listTest.search(1993145);
    cout << endl;
    person_listTest.search(1993145);
    cout << endl;
    person_listTest.search(1993238);
    cout << endl;
    person_listTest.search(1993252);
    cout << endl;
    person_listTest.search(1993304);
    cout << endl;
 
    
    
   


    
  
    

    
    
}
