#pragma once
#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

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
