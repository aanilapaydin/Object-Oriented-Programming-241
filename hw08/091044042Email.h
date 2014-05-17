/*
    Ali Anil Apaydin
    091044042

    Description:Declaration of Email Class

    Notes:CSE 241 Homework08

    File:091044042HW06Email.h

*/
#ifndef _091044042EMAIL_H_INCLUDED      //defining 091044042Email.h
#define _091044042EMAIL_H_INCLUDED

#include "091044042Document.h"      //including base class and string class
#include <string>

using namespace std;        //including namespace

class Email:public Document     //class Email
{
    public:
       Email(void); //default constructor
       //4 parameter constructor
       Email(string newSender,string newRecipient,string newTitle,string newBody);
       void setSender(string newSender);    //setter functions
       void setRecipient(string newRecipient);
       void setTitle(string newTitle);
       string getSender(void) const;        //getter functions
       string getRecipient(void) const;
       string getTitle(void) const;
       Email& operator=(const Email& rtSide);   //assignment operator
    private:
        string sender;      //private members
        string recipient;
        string title;
};

#endif      //end of header file
