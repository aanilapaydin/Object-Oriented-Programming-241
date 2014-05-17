/*
*   Created by Ali Anil APAYDIN
*
*   Date:18/10/2012
*
*   Description:The Temperture Class's
*               Functions Implementations
*   Notes:CSE241_HW03_091044042
*   File:091044042HW03Temp.cpp
*/
#include <iostream>                                 /*input output stream*/
#include "091044042HW03Temp.h"                      /*temperture class*/

using namespace std;                                /*cout*/

void Temperture::setTempKelvin(double newKelvin)    /*Kelvin degree setter function*/
{
    if(0 >= newKelvin)                              /*Checking validity*/
    {
        cout << "Your Kelvin is Invalid!! \n" << "Kelvin is automaticly assigned to 273.15";
        kelvin = 273.15;
    }
    else
        kelvin=newKelvin;
}
void Temperture::setTempFahrenheit(double newFahrenheit)    /*Fahrenheit degree setter function*/
{
    kelvin = ((5.0/9) * (newFahrenheit - 32)) + 273.15;
    setTempKelvin(kelvin);
}
void Temperture::setTempCelcius(double newCelcius)          /*Celcius degree setter function*/
{
    kelvin = newCelcius + 273.15;
    setTempKelvin(kelvin);
}
const double Temperture::getTempKelvin()const               /*Kelvin degree getter function*/
{
    return kelvin;
}
const double Temperture::getTempFahrenheit()const           /*Fahrenheit degree getter function*/
{
    return (((kelvin) - 273.15) / (5.0/9)) + 32;
}
const double Temperture::getTempCelcius()const               /*Celcius degree getter function*/
{
    return ((kelvin) - 273.15);
}
