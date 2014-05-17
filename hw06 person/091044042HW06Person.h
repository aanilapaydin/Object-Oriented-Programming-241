/*
    Ali Anil Apaydin
    091044042

    Description:Declaration of Person class

    Notes:CSE 241 Homework06

    File:091044042HW06Person.h

*/
#ifndef _091044042HW06PERSON_H_INCLUDED /*defining person.h*/
#define _091044042HW06PERSON_H_INCLUDED

#include <iostream>

using namespace std;
namespace PersonNS{             /*namespace PersonNS*/

#define MALE 1                  /*constant macros*/
#define FEMALE 2
#define NOW_TIME 2012
#define MAX_NAME_CAPACITY 25



    class Person{           /*class person*/
        public:
            Person();               /*default and 4 parameter constructor*/
            Person(const char *newName,const char *newSurname,int newBirth,int newSex);
            const char* getName()const;         /*gettters*/
            const char* getSurname()const;
            const unsigned int getBirthYear()const;
            const unsigned short int getSex()const;
            void setName(const char* newName);      /*setters*/
            void setSurname(const char* newSurname);
            void setBirthYear(const unsigned int newBirthYear);
            void setSex(const unsigned short int newSex);
            bool operator==(const Person& second)const;     /*operator == */
            friend ostream& operator <<(ostream& outputStream,const Person& a);
            friend istream& operator >>(istream& inputStream,Person& a);  /*stream insertion & extraction*/
            const Person& operator=(const Person& second);      /*assigment operator*/
            ~Person();      /*destructor*/
            Person(const Person& newPerson);       /*copy constructor*/
        private:
            char *name;         /*member variables*/
            char *surname;
            unsigned int birthyear;
            unsigned short int sex;
    };
}

#endif
