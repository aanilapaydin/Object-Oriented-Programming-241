/*
    Ali Anil Apaydin
    091044042

    Description:Implementation of Family class

    Notes:CSE 241 Homework06

    File:091044042HW06Family.cpp

*/
#include <iostream>
#include <cstdlib>      //including libraries
#include <cstring>
#include <cmath>
#include "091044042HW06Person.h"
#include "091044042HW06Family.h"

using namespace std;       //including namespaces
using namespace PersonNS;

namespace FamilyNS{     //namespace FamilyNS

Family::Family():famCapacity(2),famUsed(2)  //defalut constructor
{
    famMembers = new Person[famCapacity];
    numOfLivingFam++;
}
//2 parameter constructor
Family::Family(const Person& mother,const Person& father):famCapacity(2),famUsed(2)
{
    famMembers = new Person[famCapacity];

    famMembers[0]=mother;
    famMembers[1]=father;

    numOfLivingFam++;

}
//getter mother func
const Person& Family::getMother()const
{
    return this->famMembers[0];
}
//getter father func
const Person& Family::getFather()const
{
    return this->famMembers[1];
}
//getter children func
const Person* Family::getChildren()const
{
    return &famMembers[2];
}
//getter number of living families
int Family::getNumOfLivingFams()
{
    return numOfLivingFam;
}
//stream insertion operator
ostream& operator<<(ostream& outputStream,const Family& a)
{
    for(int i=0;i<a.famUsed;++i)
    {
        if(i==0)
            cout<<"Mother:\n";
        else if(i==1)
            cout<<"Father:\n";
        else
            cout<<"Children:\n";

        outputStream<<a.famMembers[i];
    }

    return outputStream;
}
//stream extraction operator
istream& operator>>(istream& inputStream,Family& a)
{
    cout<<"Mother...\n";
    inputStream>>a.famMembers[0];
    cout<<"Father...\n";
    inputStream>>a.famMembers[1];

    return inputStream;
}
//comparison == operator
bool Family::operator==(const Family& second)const
{
    int temp=0;

    for(int i=0;i<famUsed;++i)
            temp+=(famMembers[i]==second.famMembers[i]);

    if(famUsed-temp==1)
        return true;
    else
        return false;
}
//not equal operator
bool Family::operator!=(const Family& second)const
{
    return !(*this==second);
}
//index operator
const Person Family::operator[](const int index)const
{
    return famMembers[index];
}
//binary + operator
const Family Family::operator+(const Family& second)
{
    for(int i=2;i<famUsed;++i)
    {
        for(int j=2;j<second.famUsed;++j)
        {
            if((fabs(famMembers[i].getBirthYear()-second.famMembers[j].getBirthYear())<=5)&&
               (fabs(famMembers[i].getSex()-second.famMembers[j].getSex())==1))
               {
                   if(famMembers[i].getSex()==FEMALE)
                       return Family(famMembers[i],second.famMembers[j]);
                   else
                       return Family(second.famMembers[j],famMembers[i]);
               }
        }
    }
    cout<<"Returning first family!!\n";
    return *this;
}
// += operator
const Family& Family::operator+=(const Person& newChild)
{
    famMembers=new Person;

    famMembers[famCapacity]=newChild;

    famCapacity++;
    famUsed++;

    return *this;
}
}
