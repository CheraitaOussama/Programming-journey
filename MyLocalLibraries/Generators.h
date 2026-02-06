#pragma once
#include<iostream>
#include "Numbers.h"
#include <string>
#include <cstdlib>
using namespace std;
using namespace Numbers;
namespace Generators {
    int RandomNumber(int From, int To)
    {
        int RandNumber = rand() % (To - From + 1) + From;
        return RandNumber;

    }
    int   TimesRepeated(int CheckNumber, int arr[100], int Length)
    {
        int counter = 0;
        for (int i = 0; i < Length; i++)
        {
            if (arr[i] == CheckNumber)
            {
                counter++;
            }
        }
        return counter;
    }
    float GetFractionPart(float Number)
    {
        return Number - (int)Number;
    }
    enum enType { CapitalLetter = 1, SmallLetter = 2, Number = 3, SpecialCharcter = 4 };
    char GetRandomCharacter(enType CharType) {
        switch (CharType) {
        case enType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break; }
        case enType::CapitalLetter: {
            return char(RandomNumber(65, 90));
            break; }
        case enType::SpecialCharcter: {
            return char(RandomNumber(33, 47));
            break; }
        case enType::Number: {
            return char(RandomNumber(48, 57));
            break; }

        }
    }

    int ReverseNumber(int number)
    {
        int Remainder = 0, Number2 = 0;
        while (number > 0) {
            Remainder = number % 10;
            number = number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }
    int Factorial(int num)
    {
        int F = 1;
        for (int counter = num; counter >= 1; counter--) {

            F = F * counter;
        }
        return F;
    }

    float CalculateRemainder(float TotalBill, float TotalCashedPaid)
    {

        return TotalCashedPaid - TotalBill;
    }
    float TotalBillAfterServiceAndTax(float TotalBill) {
        TotalBill = TotalBill * 1.10;
        TotalBill = TotalBill * 1.16;

        return TotalBill;
    }
    string Tabs(short NumberOfTabs) 
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++) {
            t = t + "\t";
            cout << t;
        }
        return t;
    }
    bool ValidateNumberInRange(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }
    enum enWhatToSum { All = 0, Odd = 1, Even = 2 };
    int SumRange(int N, enWhatToSum WhatToSum)
    {
        int Sum = 0;

        if (WhatToSum == enWhatToSum::Odd) {
            for (int Counter = 1; Counter <= N; Counter++) {
                if (CheckOddOrEven(Counter) == enOddOrEven::odd)
                    Sum += Counter;
            }
        }
        else if (WhatToSum == enWhatToSum::Even) {
            for (int Counter = 1; Counter <= N; Counter++) {
                if (CheckOddOrEven(Counter) == enOddOrEven::even)
                    Sum += Counter;
            }
        }
        else if (WhatToSum == enWhatToSum::All) {
            for (int Counter = 1; Counter <= N; Counter++) {
                Sum += Counter;
            }
        }


        return Sum;
    }
    float DaystoWeeks(float NumberOfDays)
    {
        return (float)NumberOfDays / 7;
    }
    float HourstoWeeks(float NumberOfHours)
    {
        return (float)NumberOfHours / (24 * 7);
    }
    float HourstoDays(float NumberOfHours)
    {
        return (float)NumberOfHours / 24;
    }
    int SumOfDigits(int Number)
    {
        cout << endl;
        int Reminder = 0, Sum = 0;
        while (Number > 0) {
            Reminder = Number % 10;
            Number = Number / 10;
            Sum += Reminder;
        }
        return Sum;
    }
}
