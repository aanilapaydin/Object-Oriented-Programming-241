/*
    Ali Anil Apayd�n
    091044042

    Description:Driver function Geometric class

    Notes:CSE 241 Homework05

    File:091044042HW05Main.cpp

*/
#include <iostream>
#include "091044042HW05Geometric.h"
/*including library and header*/

using namespace std;

short int Geometric::numberOfSeries=0;
/*initilize static variable*/
int main()      /*main function*/
{
    cout<<"Number of alive series :"<<Geometric::aliveSeries()<<"\n\n";
    /*printing number of alive series first*/

    Geometric a;
    Geometric b(3);
    Geometric c(-5);
    /*initilize geometric series*/

    a.add();    /*adding and removing element to a serie*/
    a.add();    /*and printing the a serie*/
    a.add();
    cout<<"a serie's limit: "<<a.getLimit()<<"\n";
    a.remove();
    cout<<"a serie's limit: "<<a.getLimit()<<"\n";

    /*getting 2.element from b abd evaluate b*/
    cout<<"b serie's 2.element: "<<b.getElement(2)<<"\n";
    cout<<"b serie's evaluated value: "<<b.evaluate()<<"\n";

    /*control if c is empty*/
    if(c.isEmpty())
        cout<<"\n"<<"c serie is empty\n";
    else
        cout<<"\n"<<"c serie is not empty\n";

    a.print();  /*printing a*/

    b.print();  /*printing b and multipled b*/
    b.mult(0.324);
    b.print();

    if(a.isGreater(b))  /*greatness comparison beween a and b*/
        cout<<"\n"<<"b is greater than a serie...\n";
    else
        cout<<"\n"<<"a is greater than b serie...\n";

    /*printing number of alive alive series*/
    cout<<"\nNumber of alive series :"<<Geometric::aliveSeries()<<"\n";

    /*testing overloaded operators*/

    (b+a).print();          /*overloaded + operator*/
    cout<<a-b;              /*overloaded - operator*/

    cout<<(a*2.0);          /* * operator as multiply*/

    Geometric temp(3);
    cin>>temp;              /*stream extraction*/
    cout<<temp;             /*stream insertion*/

    /*compare evaluate and * operator as evaluate*/
    cout<<"a serie's evaluated value: "<<a.evaluate()<<"\n";
    cout<<"a serie's evaluated value with operator *: "<<*a<<"\n";

    /*index oparetor as getter and setter*/
    a[1]=a[0];
    cout<<a;

    /*boolean comparison operators*/
    if(a<b)
        cout<<"a<b \n";
    if(a==b)
        cout<<"a=b \n";
    if(a>b)
        cout<<"a>b \n";
    if(a<=b)
        cout<<"a<=b \n";
    if(a>=b)
        cout<<"a>=b \n";

    /*pre-fix post-fix operators*/
    cout<<a
        <<a++
        <<++a;

    return 0;   /*program ends*/
}

