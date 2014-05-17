/*
*   Created by Ali Anil APAYDIN
*
*   Date:18/10/2012
*
*   Description:Driver file(main function)
*
*   Notes:CSE241_HW03_091044042
*   File :091044042HW03Main.cpp
*/

#include <iostream>                                 /*input output stream*/
#include <iomanip>                                  /*input output manipulators*/
#include "091044042HW03Temp.cpp"                    /*temperture class*/

using namespace std;                                /*cout*/

int main()                                          /*main function*/
{
    Temperture izmir,istanbul,ankara;               /*Objects decleration*/

    izmir.setTempCelcius(35.0);                     /*initilize object with different setters*/
    istanbul.setTempFahrenheit(86.6);
    ankara.setTempKelvin(303.3);

    cout.setf(ios::fixed);                          /*printing 2 digit after the comma*/
    cout.setf(ios::showpoint);
    cout << setprecision(2);

    cout<<"              KELVIN    CELCIUS    FAHRENHEIT\n";      /*printing objects with different getters*/

    cout<<"Izmir   :     "<<izmir.getTempKelvin()<<"     "
                          <<izmir.getTempCelcius()<<"     "
                          <<izmir.getTempFahrenheit()<<"\n";

    cout<<"Istanbul:     "<<istanbul.getTempKelvin()<<"     "
                          <<istanbul.getTempCelcius()<<"     "
                          <<istanbul.getTempFahrenheit()<<"\n";

    cout<<"Ankara  :     "<<ankara.getTempKelvin()<<"     "
                          <<ankara.getTempCelcius()<<"     "
                          <<ankara.getTempFahrenheit()<<"\n";

    return 0;                                               /*program ends*/
}
