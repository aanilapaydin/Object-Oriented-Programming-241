/*
    Ali Anil Apaydin
    091044042

    Description:Declaration of File Class

    Notes:CSE 241 Homework08

    File:091044042HW06File.h

*/
#ifndef _091044042FILE_H_INCLUDED  //defining 091044042File.h
#define _091044042FILE_H_INCLUDED

#include "091044042Document.h"  //including base class and string class
#include <string>

using namespace std;  //including namespace

class File : public Document  //class File
{
  public:
    File(void);  //default constructor
    //2 parameter constructor
    File(string newPathname,string newBody);
    string getPathname() const;  //setter function
    void setPathname(string newPathname); //getter functions
    File& operator=(const File& rtSide); //assignment operator
  private:
    string pathname; //private memmber
};

#endif  //end of header file
