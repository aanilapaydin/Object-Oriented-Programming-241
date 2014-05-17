/*
*   Created by Ali Anil APAYDIN
*
*   Date:18/10/2012
*
*   Description:The Temperture Class
*
*   Notes:CSE241_HW03_091044042
*   File: 091044042HW03Temp.h
*/

#ifndef __091044042HW03TEMP_H_INCLUDED__ /*including 091044042HW03Temp.h */
#define __091044042HW03TEMP_H_INCLUDED__

class Temperture{                        /*temperture class decleration*/

    public:
        void setTempKelvin(double );     /*setter functions*/
        void setTempFahrenheit(double );
        void setTempCelcius(double );
        const double getTempKelvin()const;  /*getter functions*/
        const double getTempFahrenheit()const;
        const double getTempCelcius()const;
    private:
        double kelvin;                      /*private member variable*/

};

#endif                                   /*end of temperture class header file*/
