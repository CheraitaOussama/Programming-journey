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
