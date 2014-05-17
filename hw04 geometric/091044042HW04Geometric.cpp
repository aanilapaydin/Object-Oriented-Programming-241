#include <iostream>
#include <vector>
#include <cmath>
#include "091044042HW04Geometric.h"
/*including libraries and header*/

using namespace std;

Geometric::Geometric():k(0)  /*default constructor*/
{
    numberOfSeries++;       /*incresing alive series and initilize serie*/
    for(int i=0;i<=k;++i)
        serie.push_back(pow(0.5,i));
}
Geometric::Geometric(int newK)  /*one parameter constructor*/
{
    numberOfSeries++;       /*incresing alive series*/
    if(newK < 0)    /*control k validity and initilize serie*/
    {
        cout << "Invalid limit k! \n"
             << "Your limit k is auotomaticly assigned to zero!\n\n";
        k=0;
        for(int i=0;i<=k;++i)
            serie.push_back(pow(0.5,i));
    }
    else
    {
        k=newK;
        for(int i=0;i<=k;++i)
            serie.push_back(pow(0.5,i));
    }
}
const int Geometric::getLimit()const    /*getter limit k*/
{
    return k;
}
const double Geometric::getElement(int num)const    /*getter element*/
{
    return serie.at(num);
}
const double Geometric::evaluate()const     /*evaluate function*/
{
    double sum=0;

    for(int i=0;i<=k;++i)   /*evaluation*/
        sum+=serie.at(i);

    return sum;
}
bool Geometric::isEmpty()const   /*control if serie empty*/
{
    if(k==0)
        return true;
    else
        return false;
}
void Geometric::add()       /*add element to serie*/
{
    serie.push_back(pow(0.5,++k));
}
void Geometric::remove()    /*remove last element from the serie*/
{
    if(isEmpty())       /*control if serie is empty*/
        cout<<"Your serie is already empty!\n";
    else
    {
        serie.pop_back();
        --k;
    }
}
void Geometric::mult(const double num) /*multiple serie with given double num*/
{
    for(int i=0;i<=k;++i)
        serie.at(i)*=num;
}
void Geometric::print()const    /*printing the serie*/
{
    cout<<"\nYour Geometric Serie: \n";
    for(int i=0;i<=k;++i)
        cout<<i+1<<". element "<<serie.at(i)<<"\n";
}
bool Geometric::isGreater(Geometric a)const /*series greatness comparison*/
{
    if(a.evaluate()>evaluate()) /*if second is greater*/
        return true;
    else                        /*else*/
        return false;
}
int Geometric::aliveSeries()    /*getter number of alive series*/
{
    return numberOfSeries;
}
