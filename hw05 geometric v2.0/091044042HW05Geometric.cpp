/*
    Ali Anil Apaydýn
    091044042

    Description:Implementation of Geometric class function

    Notes:CSE 241 Homework05

    File:091044042HW05Geometric.cpp

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "091044042HW05Geometric.h"
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
        cout<<"  "<<serie.at(i);

    cout<<"\n";
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
/*binary + operator*/
const Geometric Geometric::operator+(const Geometric& a)const
{
    if(k<a.k)      /*controlling which one is greater*/
    {
      Geometric sum(a.k);   /*initilize sum according to greatness*/

      for(int i=0;i<=k;++i)    /*assign sum*/
          sum.serie[i]=serie[i]+(a.serie[i]);

      for(int i=k+1;i<=a.k;++i)
          sum.serie[i]=a.serie[i];

      return sum;
    }
    else
    {
      Geometric sum(k);

      for(int i=0;i<=a.k;++i)
          sum.serie[i]=serie[i]+(a.serie[i]);

      for(int i=(a.k)+1;i<=k;++i)
          sum.serie[i]=a.serie[i];

      return sum;
    }
}
/*binary - operator*/
const Geometric Geometric::operator-(const Geometric& a)const
{

    if(k>=a.k)          /*controlling which one is greater*/
    {
      Geometric sum(k); /*initilize sum according to greatness*/

      for(int i=0;i<=a.k;++i) /*assign sum*/
          sum.serie[i]=serie[i]-a.serie[i];
      for(int i=(a.k)+1;i<=k;++i)
          sum.serie[i]=serie[i];

      return sum;
    }
    else
    {
       Geometric sum(a.k);

       for(int i=0;i<=k;++i)
           sum.serie[i]=serie[i]-a.serie[i];
       for(int i=k+1;i<=a.k;++i)
           sum.serie[i]=-a.serie[i];

       return sum;
    }
}
/* * operator as multiply*/
const Geometric& Geometric::operator*(const double a)
{
    this->mult(a);
    return *this;
}
/*straam insertion operator implementation*/
ostream& operator<<(ostream& outputStream,const Geometric& a)
{
    outputStream<<"Your limit k value is "<<a.k<<"\n";
    outputStream<<"Your serie elements :\n";

    for(unsigned i=0;i<=a.k;++i)
    {
        outputStream<<"  "<<a.serie[i];
    }
    outputStream<<"\n";
    return outputStream;
}
/*stream extraction operator imlementation*/
istream& operator>>(istream& inputStream,Geometric& a)
{

    unsigned int i=0;

    cout<<"Enter your serie's values until limit k!\n";

    do{
        inputStream>>a.serie[i];
        ++i;
    }while(i<=a.k);

    return inputStream;
}
/* * operator as evaluate*/
const double Geometric::operator*(void)const
{
    return this->evaluate();
}
/*insert getter and getter function*/
double& Geometric::operator[](const int index)
{
    if(index>=0  && index<=k)/*check validity of index num*/
        return this->serie[index];
    else
    {
        cout<<"Invalid index! \n";
        exit (1);
    }
}
/*boolean < operator implementation*/
bool Geometric::operator<(const Geometric& a)const
{
    if(k < a.k)     /*controlling limit greatness*/
        return true;
    else if(k == a.k)   /*if limits are equal*/
    {
        int i;      /*checking element are equal*/
        for(i=0;serie[i]<a.serie[i] || i<=k;++i){}

        if(i<k)
            return false;
        else
            return true;
    }
    else
        return false;
}
/*boolean == oparetor implementation*/
bool Geometric::operator==(const Geometric& a)const
{
    unsigned int i=0;

    if(k == a.k)    /*checking all elemnt are equal to each*/
    {
        while(serie[i]==a.serie[i] && i<=k)
        {
            ++i;
        }
        if(i==k)
            return true;
        else
            return false;
    }
    else
        return false;
}
/*boolean > oparetor implementation*/
bool Geometric::operator>(const Geometric& a)const
{
    /* !(< || ==) is >*/
    return !(*this < a || *this == a);
}
/*boolean >= oparetor implementation*/
bool Geometric::operator>=(const Geometric& a)const
{
    /* !(< || ==) || == is >=*/
    return (!(*this < a || *this == a)||(*this == a));
}
/*boolean <= oparetor implementation*/
bool Geometric::operator<=(const Geometric& a)const
{
    /* !(>) is <= */
    return !(*this > a);
}
/*postfix icrementation opearator implementation*/
Geometric Geometric::operator++(int i)
{
    Geometric temp(k);  /*initilizer temp*/

    for(unsigned i=0;i<=k;++i)
    {                    /*assign to temp before incrementation*/
     temp.serie[i]=this->serie[i];
     ++(this->serie[i]);
    }

    return temp;    /*return original serie*/
}
/*prefix incrementation operator implementation*/
Geometric Geometric::operator++()
{
    for(unsigned i=0;i<=k;++i)  /*change the serie elements*/
        ++(this->serie[i]);

    return *this;   /*return changed serie*/
}
