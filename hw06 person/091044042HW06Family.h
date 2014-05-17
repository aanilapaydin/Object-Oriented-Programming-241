/*
    Ali Anil Apaydin
    091044042

    Description:Declaration of Family class

    Notes:CSE 241 Homework06

    File:091044042HW06Family.h

*/
#ifndef _091044042HW06FAMILY_H_INCLUDED         /*defining family.h*/
#define _091044042HW06FAMILY_H_INCLUDED

#include <iostream>                 /*including libraries*/
#include "091044042HW06Person.h"

using namespace std;            /*including namespaces*/
using namespace PersonNS;

namespace FamilyNS{         /*namespace FmailyNS*/

    class Family{           //family class
        public:
            Family();       //default constructor
            Family(const Person& mother,const Person& father);//2 parameter constructor
            const Person& getMother()const; //getters
            const Person& getFather()const;
            const Person* getChildren()const;
            static int getNumOfLivingFams();    //static getter function
            //stream insertion &extraction operators
            friend ostream& operator<<(ostream& outputStream,const Family& a);
            friend istream& operator>>(istream& inputStream,Family& a);
            bool operator==(const Family& second)const; //comparison == operator
            bool operator!=(const Family& second)const; //not equal operator
            const Person operator[](const int index)const; //index operator
            const Family operator+(const Family& second); //binary + oparetor
            const Family& operator+=(const Person& newChild); //+= operator
        private:
            Person *famMembers; //person array
            unsigned short int famCapacity; //array capacity
            unsigned short int famUsed; //array used number
            static unsigned short int numOfLivingFam; //number of living families
    };
}

#endif

