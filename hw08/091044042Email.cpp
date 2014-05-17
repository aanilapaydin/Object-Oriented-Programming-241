/*
    Ali Anil Apaydin
    091044042

    Description:Implementation of Email class

    Notes:CSE 241 Homework08

    File:091044042HW06Email.cpp

*/
#include "091044042Email.h"   //including base and string class
#include <string>

using namespace std; //including namespace

Email::Email(void) : Document()     //default constructor
{

}
//4 parameter constructor
Email::Email(string newSender,string newRecipient,string newTitle,string newBody) : Document(newBody)
{
    sender = newSender;
    recipient = newRecipient;
    title = newTitle;
}
// set sender function
void Email::setSender(string newSender)
{
    sender=newSender;
}
// set recipient function
void Email::setRecipient(string newRecipient)
{
    recipient=newRecipient;
}
// set title function
void Email::setTitle(string newTitle)
{
    title=newTitle;
}
// get sender function
string Email::getSender(void) const
{
    return sender;
}
// get recipient function
string Email::getRecipient(void) const
{
    return recipient;
}
// get title function
string Email::getTitle(void) const
{
    return title;
}
// assignment operator
Email& Email::operator=(const Email& rtSide)
{
    Document::operator=(rtSide);
    sender=rtSide.sender;
    recipient=rtSide.recipient;
    title=rtSide.title;
    return *this;
}
