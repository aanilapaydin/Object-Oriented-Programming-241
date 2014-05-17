/*
    Ali Anil Apaydin
    091044042

    Description:Implementation of File Class

    Notes:CSE 241 Homework08

    File:091044042HW06File.cpp

*/
#include "091044042File.h" //including base and string class
#include <string>

using namespace std;  //including namespace

File::File(void) : Document() //default constructor
{

}
//2 parameter constructor
File::File(string newPathname,string newBody) : Document(newBody),pathname(newPathname)
{

}
// get pathname function
string File::getPathname() const
{
    return pathname;
}
// set pathname function
void File::setPathname(string newPathname)
{
    pathname=newPathname;
}
// assignment operator
File& File::operator=(const File& rtSide)
{
    Document::operator=(rtSide);
    pathname = rtSide.pathname;
    return *this;
}
