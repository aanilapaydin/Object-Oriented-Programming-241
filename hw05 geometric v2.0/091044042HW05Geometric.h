/*
    Ali Anil Apaydýn
    091044042

    Description:Declaration of Geometric class

    Notes:CSE 241 Homework05

    File:091044042HW05Geometric.h

*/
#ifndef __091044042HW05GEOMETRIC_H_INCLUDED__
#define __091044042HW05GEOMETRIC_H_INCLUDED__
/*including 091044042HW05Geometric.h*/

#include <iostream>
#include <vector>
/*including iostream and vector*/

using namespace std;

class Geometric{    /*class Geomeric class declaration*/

    public:
        Geometric();        /*default constructor*/
        Geometric(int newK);    /*one parameter constructor*/
        const int getLimit(void)const;  /*getter limit k*/
        const double getElement(int num)const;  /*getter element*/
        const double evaluate(void)const;   /*evaluate function*/
        bool isEmpty(void)const;    /*isEmpty control function*/
        void add(void);     /*add element function*/
        void remove(void);  /*remove element function*/
        void mult(const double num);    /*multiple serie function*/
        void print(void)const;  /*print serie function*/
        bool isGreater(Geometric a)const;   /*isGreater control function*/
        static int aliveSeries(void);   /*number of alive series function*/
        const Geometric operator+(const Geometric& a)const;
        const Geometric operator-(const Geometric& a)const;
        const Geometric& operator*(const double a);
        friend ostream& operator<<(ostream& outputStream,const Geometric& a);
        friend istream& operator>>(istream& inputStream,Geometric& a);
        const double operator*(void)const;
        double& operator[](const int index);
        bool operator<(const Geometric& a)const;    /*operators overloading*/
        bool operator==(const Geometric& a)const;
        bool operator>(const Geometric& a)const;
        bool operator>=(const Geometric& a)const;
        bool operator<=(const Geometric& a)const;
        Geometric operator++(int i);
        Geometric operator++();
    private:
        unsigned short int k;       /*limit k number*/
        vector <double> serie;      /*geometric serie*/
        static short int numberOfSeries;    /*number of alive series*/
};

#endif      /*end of header*/
