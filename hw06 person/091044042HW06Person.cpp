/*
    Ali Anil Apaydin
    091044042

    Description:Implementation of Person class

    Notes:CSE 241 Homework06

    File:091044042HW06Person.cpp

*/
#include <iostream>
#include <cstdlib>              /*including libraries*/
#include <cstring>
#include "091044042HW06Person.h"

using namespace std;

namespace PersonNS{         /*namespace PersonNS*/

/*defalut constructor*/
Person::Person(void):birthyear(NOW_TIME),sex(MALE)
{
    name=new char[MAX_NAME_CAPACITY];
    strcpy(name,"");
    surname=new char[MAX_NAME_CAPACITY];
    strcpy(surname,"");
}
/*4 parameter constructor*/
Person::Person(const char *newName,const char *newSurname,int newBirth,int newSex)
{
    name=new char[MAX_NAME_CAPACITY];
    strcpy(name,newName);
    surname=new char[MAX_NAME_CAPACITY];
    strcpy(surname,newSurname);
    birthyear=newBirth;
    sex=newSex;
}
/*copy constructor*/
Person::Person(const Person& newPerson):birthyear(newPerson.birthyear),sex(newPerson.sex)
{
    name=new char[MAX_NAME_CAPACITY];
    strcpy(name,newPerson.name);
    surname=new char[MAX_NAME_CAPACITY];
    strcpy(surname,newPerson.surname);
}
/*get name function*/
const char* Person::getName()const
{
    return name;
}
/*get surname function*/
const char* Person::getSurname()const
{
    return surname;
}
/*get birthyear function*/
const unsigned int Person::getBirthYear()const
{
    return birthyear;
}
/*get sex function*/
const unsigned short int Person::getSex()const
{
    return sex;
}
/*set name function*/
void Person::setName(const char* newName)
{
    strcpy(name,newName);
}
/*set surname function*/
void Person::setSurname(const char* newSurname)
{
    strcpy(surname,newSurname);
}
/*set birthyear function*/
void Person::setBirthYear(const unsigned int newBirthYear)
{
    birthyear=newBirthYear;
}
/*set sex function*/
void Person::setSex(const unsigned short int newSex)
{
    sex=newSex;
}
/*stream insertion operator*/
ostream& operator <<(ostream& outputStream,const Person& a)
{
    outputStream<<"Name:"<<a.name<<"\n";
    outputStream<<"Surname:"<<a.surname<<"\n";
    outputStream<<"Birth Year:"<<a.birthyear<<"\n";
    outputStream<<"Sex:"<<a.sex<<"\n";

    return outputStream;
}
/*stream extraction operator*/
istream& operator >>(istream& inputStream,Person& a)
{
    cout<<"Name:\n";
    inputStream>>a.name;
    cout<<"Surname:\n";
    inputStream>>a.surname;
    cout<<"BirthYear:\n";
    inputStream>>a.birthyear;
    cout<<"Sex:\n";
    inputStream>>a.sex;

    return inputStream;
}
/*assignment operator*/
const Person& Person::operator=(const Person& second)
{
    for(int i=0;i<=strlen(name);++i)
        name[i]='\0';
    strcpy(name,second.name);
    for(int i=0;i<=strlen(surname);++i)
        surname[i]='\0';
    strcpy(surname,second.surname);

    birthyear=second.birthyear;
    sex=second.sex;

    return *this;
}
/*destructor*/
Person::~Person()
{
    cout<<"Destructor...\n";
    delete name;
    delete surname;
}
/*comparison == operator*/
bool Person::operator==(const Person& second)const
{
    int temp=0;

    temp+=strcmp(name,second.name);
    if(temp==0)
    {
        temp+=strcmp(surname,second.surname);
        if(temp==0)
        {
            if(birthyear==second.birthyear && sex==second.sex)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
}
