#pragma once
#include<iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "Generators.h"
using namespace Generators;
namespace Readers {
    int ReadNumber()
    {
        int num;
        cout << "\n Enter a Number?" << endl;
        cin >> num;
        return num;
    }
    string ReadText(string message) 
    {
        string text = " ";
        cout << message << endl;
        getline(cin, text);
        return text;
    }
    int ReadNumberInRange(int from, int to) {
        int Number;
        do {
            cout << "Please enter Number In Range " << from << " to " << to << endl;
            cin >> Number;

        } while (Number<from || Number>to);
        return Number;
    }
    float ReadfloatNumber(string message) 
    {

        float Number = 0;
        cout << message << endl;
        cin >> Number;
        return Number;
    }
    int ReadNumberInRange(string message, int From, int To)
    {
        int Number = 0;
        do {
            cout << message << endl;
            cin >> Number;

        } while (Number<From || Number>To);
        return Number;
    }
     enWhatToSum ReadWhatToSum()
     {
         enWhatToSum WhatToSum;
         int temp = 0;
         cout << "Please enter 0 to sum All Numbers or 1 to sum odd numbers or 2 to sum even number?" << endl;
         cin >> temp;
         if (temp == enWhatToSum::All) {
             return enWhatToSum::All;
         }
         else if (temp == enWhatToSum::Even) {
             return enWhatToSum::Even;
         }
         else if (temp == enWhatToSum::Odd) {
             return enWhatToSum::Odd;
         }

     }
     unsigned int ReadPositiveNumber(string Message)
     {
         int Number;
         do {
             cout << Message << endl;
             cin >> Number;
         } while (Number < 0);
         return Number;
     }
     float ReadNumber(string message) {
         float Number = 0;
         cout << message << endl;
         cin >> Number;
         return Number;
     }
}
