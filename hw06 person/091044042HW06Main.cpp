/*
    Ali Anil Apaydin
    091044042

    Description:Main driver

    Notes:CSE 241 Homework06

    File:091044042HW06Main.cpp

*/
#include <iostream>
#include "091044042HW06Person.h"      //including libraries
#include "091044042HW06Family.h"

using namespace std;
using namespace PersonNS;   //including namespaces
using namespace FamilyNS;

unsigned short int Family::numOfLivingFam=0;    //static member variable initilize


int main()      //main function
{
    //testing Person class
    Person mother;          //deault constructor
    Person father("Osman","Apaydin",1958,1);    //4 parameter cons

    cout<<father;   //stream insertion
    cout<<"\n"<<father.getName()<<"\n";     //getters
    cout<<father.getSurname()<<"\n";
    cout<<father.getBirthYear()<<"\n";
    cout<<father.getSex()<<"\n";

    mother.setName("Bircan");   //setters
    mother.setSurname("Apaydin");
    mother.setBirthYear(1959);
    mother.setSex(2);

    cout<<mother;

    Person stepMother(mother); //copy constructor

    if(stepMother==mother)     //comparison == operator
        cout<<"\nstepMother is equal to mother \n\n";
    else
        cout<<"\nstepMother is equal to mother \n\n";

    {
    Person president;
    cin>>president;     //stream extraction
    cout<<president;

    father=president;   //assignment & destructor
    cout<<father;
    }

    //testing Family class
    Family myFam(mother,father);  //2 parameter cons.
    cout<<myFam;    //stream insertion

    cout<<myFam.getMother();    //getters
    cout<<myFam.getFather();

    //static getter
    cout<<"Number of living families:"<<myFam.getNumOfLivingFams()<<"\n";

    Family yourFam; //default cons.

    cin>>yourFam;   //stream extraction

    if(myFam==yourFam)  //comparison == operator
        cout<<"We are brothers\n";
    if(myFam!=yourFam)  //not equal operator
        cout<<"We are not brothers\n";

    cout<<"My Mother:"<<myFam[0]<<"\n"; //index operator

    cout<<myFam+yourFam;    //binary + operator

    return 0;   //program ends
}
