/*
    Ali Anil Apaydin
    091044042

    Description:Declaration of Document Class

    Notes:CSE 241 Homework08

    File:091044042HW06Document.h

*/
#ifndef _091044042DOCUMENT_H_INCLUDED  //defining 091044042Document.h
#define _091044042DOCUMENT_H_INCLUDED

#include <string>   //including string class

using namespace std;  //including namespace

class Document  //class Document
{
    public:
        Document(void);  //default constructor
        Document(string newText);  //1 parameter constructor
        string getText(void) const;  //getter function
        void setText(string newText);  //setter function
        Document& operator=(const Document& rtSide); //assigment operator
    private:
        string text;  //private member
};

#endif  //end of header file
