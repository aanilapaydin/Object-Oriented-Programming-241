/*
 * File:   091044042HW02.cpp
 * Created by Ali Anıl APAYDIN
 *
 * Created on 21 Ekim 2012 Pazar, 15:51
 *
 * Description: This program gets the word from the user and seperates it
 *              to root and suffixes.
 *
 * Notes:       CSE241_HW02_091044042
 *
 */

#include <iostream>                                                             /*input output stream*/
#include <cstdlib>                                                              /*exit*/
#include <string>                                                               /*compare,clear,length,erase,insert*/

using namespace std;                                                            /*cin,cout*/

string findRoot(string);                                                        /*function declerations*/
void findSuffixes(string);

int main()                                                                      /*main function*/
{
    string noun;                                                                /*word*/

    cout << "Enter the Word: \n";                                               /*getting word from the user*/
    cin >> noun;

    cout << "\nAnalysis \n";                                                    /*functions calling*/
    noun = findRoot(noun);
    findSuffixes(noun);

    return 0;                                                                   /*program ends*/
}

string findRoot(string noun)                                                    /*finding root function implementation*/
{
    string root;                                                                /*local variable root*/

    if (0 == noun.compare(0, 5, "abone")) {                                     /*checking the root in the word*/
        root.insert(0, noun, 0, 5);                                             /*if there is,program assign to root*/
    } else if (0 == noun.compare(0, 3, "ada")) {
        root.insert(0, noun, 0, 3);
    } else if (0 == noun.compare(0, 5, "adres")) {
        root.insert(0, noun, 0, 5);
    } else if (0 == noun.compare(0, 5, "araba")) {
        root.insert(0, noun, 0, 5);
    } else if (0 == noun.compare(0, 4, "afis")) {
        root.insert(0, noun, 0, 4);
    } else if (0 == noun.compare(0, 5, "cumba")) {
        root.insert(0, noun, 0, 5);
    } else if (0 == noun.compare(0, 6, "macera")) {
        root.insert(0, noun, 0, 6);
    } else if (0 == noun.compare(0, 6, "mahmuz")) {
        root.insert(0, noun, 0, 6);
    } else if (0 == noun.compare(0, 6, "seciye")) {
        root.insert(0, noun, 0, 6);
    } else if (0 == noun.compare(0, 5, "seher")) {
        root.insert(0, noun, 0, 5);
    } else if (0 == noun.compare(0, 8, "sentetik")) {
        root.insert(0, noun, 0, 8);
    } else if (0 == noun.compare(0, 6, "seyyah")) {
        root.insert(0, noun, 0, 6);
    } else if (0 == noun.compare(0, 6, "icinde")) {
        root.insert(0, noun, 0, 6);
    } else if (0 == noun.compare(0, 7, "disinda")) {
        root.insert(0, noun, 0, 7);
    } else if (0 == noun.compare(0, 5, "sihhi")) {
        root.insert(0, noun, 0, 5);
    }

    if (0 == root.length()) {                                                   /*checking if there is no root*/
        cout << "Invalid root!!\n";
        exit(1);
    }

    cout << root << ": Root \n";                                                /*printing the root and erasing from the word*/
    noun.erase(0, root.length());
    return noun;                                                                /*returning changed noun to main function*/
}

void findSuffixes(string noun)                                                  /*finding suffixes function implementation*/
{

    string tempSuffix;                                                          /*local variable temporary suffix*/

    while (0 != noun.length())                                                  /*while end if there is no suffix in the word*/
    {
        if (0 == noun.compare(0, 3, "siz") || 0 == noun.compare(0, 3, "suz"))   /*checking suffixes in the word*/
        {                                                                       /*if threre is program assigns it to the tempSuffix*/
            tempSuffix.insert(0, noun, 0, 3);                                   /*erases it from the word and clears tempSuffix for*/
            cout << "-" << tempSuffix << ": Without Condition Suffix \n";       /*the loop*/
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if (0 == noun.compare(0, 3, "ler") || 0 == noun.compare(0, 3, "lar"))
        {
            tempSuffix.insert(0, noun, 0, 3);
            cout << "-" << tempSuffix << ": Plural Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 1, "a")) || (0 == noun.compare(0, 1, "e")))
        {
            tempSuffix.insert(0, noun, 0, 1);
            cout << "-" << tempSuffix << ": Movement Towards Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 2, "ya")) || (0 == noun.compare(0, 2, "ye")))
        {
            tempSuffix.insert(0, noun, 0, 2);
            cout << "-" << tempSuffix << ": Movement Towards Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if (0 == noun.compare(0, 3, "den") || 0 == noun.compare(0, 3, "dan") ||
            0 == noun.compare(0, 3, "ten") || 0 == noun.compare(0, 3, "tan"))
        {
            tempSuffix.insert(0, noun, 0, 3);
            cout << "-" << tempSuffix << ": Movement Away Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 4, "inin")) || (0 == noun.compare(0, 4, "unun")))
        {
            tempSuffix.insert(0, noun, 0, 1);
            cout << "-" << tempSuffix << ": Object Condition Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
            tempSuffix.insert(0, noun, 0, 3);
            cout << "-" << tempSuffix << ": Ownership Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if (0 == noun.compare(0, 3, "nin") || 0 == noun.compare(0, 3, "nun"))
        {
            tempSuffix.insert(0, noun, 0, 3);
            cout << "-" << tempSuffix << ": Ownership Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 2, "da")) || (0 == noun.compare(0, 2, "de")) ||
           (0 == noun.compare(0, 2, "ta")) || (0 == noun.compare(0, 2, "te")))
        {
            tempSuffix.insert(0, noun, 0, 2);
            cout << "-" << tempSuffix << ": Static Position Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 2, "yi")) || (0 == noun.compare(0, 2, "yu")))
        {
            tempSuffix.insert(0, noun, 0, 2);
            cout << "-" << tempSuffix << ": Object Condition Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 2, "in")) || (0 == noun.compare(0, 2, "un")))
        {
            tempSuffix.insert(0, noun, 0, 2);
            cout << "-" << tempSuffix << ": Ownership Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
        if ((0 == noun.compare(0, 1, "i")) || (0 == noun.compare(0, 1, "u")))
        {
            tempSuffix.insert(0, noun, 0, 1);
            cout << "-" << tempSuffix << ": Object Condition Suffix \n";
            noun.erase(0, tempSuffix.length());
            tempSuffix.clear();
        }
    }                                                                           /*end of while*/
}                                                                               /*end of function findSuffixes*/
