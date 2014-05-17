/*
    Ali Anil Apaydin
    091044042

    Description:Implementation of DocumentClass

    Notes:CSE 241 Homework08

    File:091044042HW06Document.cpp

*/
#include "091044042Document.h"  //including base header and string class
#include <string>

using namespace std;  //including namespace

Document::Document() : text("")  //default constructor
{}
//1 parameter constructor
Document::Document(string newText) : text(newText)
{}
// get Text function
string Document::getText(void) const
{
    return text;
}
// set Text function
void Document::setText(string newText)
{
    text = newText;
}
//assignment operator
Document& Document::operator=(const Document& rtSide)
{
    text = rtSide.text;
    return *this;
}
