/*
    Ali Anil Apaydin
    091044042

    Description:Main Function

    Notes:CSE 241 Homework08

    File:091044042HW06Main.cpp

*/
#include <iostream>     //including base,child headers,string class,input
#include <string>       //output stream
#include "091044042Document.cpp"
#include "091044042Email.cpp"
#include "091044042File.cpp"

using namespace std;  //including namespace

//find keyword function implemantation
bool ContainsKeyword( const Document& docObject, string keyword)
{
    if (docObject.getText().find(keyword) != string::npos)
        return true;

    return false;
}
//main function
int main()
{
    //declaration and initilizing  2 email and 2 file objects
    Email project("aanilapaydin@gmail.com","abdullahakay@gyte.edu.tr","Homework 8","Here my homework 8");
    Email sparta("KingLeonidas","theHeraldOfPersianEmpire","sparta","This is Sparta!");
    File file1("This fire is out of control","She gonna burn this city");
    File file2("Elvis Presley","My heart beats like Rock'n Roll");

    //finding keyword 'my' in the objects
    if(ContainsKeyword(project,"my"))
        cout<<"Project contains 'my' word\n";
    if(ContainsKeyword(sparta,"my"))
        cout<<"Sparta contains 'my' word\n";
    if(ContainsKeyword(file1,"my"))
        cout<<"file1 contains 'my' word\n";
    if(ContainsKeyword(file2,"my"))
        cout<<"file2 contains 'my' word\n";

    return 0;   //program ends
}  //end of main function
