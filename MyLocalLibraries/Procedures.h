#pragma once
#include<iostream>
using namespace std;
namespace Procedures {

    void Swap(int& A, int& B) 
    {
        int temp;
        temp = A;
        A = B;
        B = temp;
    }
    void GameOverScreen()
    {
        cout << "\n\n-------------------------------------------------\n\n";
        cout << "\t\t+++ G a m e  O v e r+++\t\t\n";
        cout << "\n\n-------------------------------------------------\n\n";
    }
    void PrintName(string Name)
    {
        cout << "\n Your Name is :" << Name << endl;
    }
    void  PrintDigits(int Number)
    {
        cout << endl;
        int Reminder = 0;
        while (Number > 0) {
            Reminder = Number % 10;
            Number = Number / 10;
            cout << Reminder << endl;
        }
    }

}
