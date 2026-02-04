#pragma once
#include<iostream>
using namespace std;
#include <cstdlib>
#include "Generators.h"
using namespace Generators;
namespace Arrays {
    void ReadArray(int arr[100], int& arrLength)
    {
        cout << "Enter number Elements: \n";
        cin >> arrLength;
        cout << "Enter array elements;\n";
        for (int i = 0; i < arrLength; i++) {
            cout << "Element [" << i + 1 << "] :";
            cin >> arr[i];
        }
    }

    void  PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
    void FillArrayWithRandomNumbersWithoutArrLength(int arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            arr[i] = RandomNumber(1, 100);
        }
    }
    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[arrLength - 1 - i];
        }
    }
    short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
            {
                return i;
            }
        }
        return -1;
    }
    bool isNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
    int PositiveCount(int arr[100], int arrLength)
    {
        int counter = 0;
        for (int i = 0; i < arrLength; i++)
        {

            if (arr[i] >= 0)
            {
                counter++;
            }
        }
        return counter;
    }
    int NegativeCount(int arr[100], int arrLength)
    {
        int counter = 0;
        for (int i = 0; i < arrLength; i++)
        {

            if (arr[i] < 0)
            {
                counter++;
            }
        }
        return counter;
    }
    void PrintStringArray(string arr[100], int  arrLenght)
    {
        cout << "\nArray elemnets: \n\n";
        for (int i = 0; i < arrLenght; i++)
        {
            cout << "Array[" << i << "]: ";
            cout << arr[i] << endl;
        }
        cout << endl;

    }
    void  FillArrayWithRandomNumbers(int arr[100], int& arrLength)
    {

        cout << "Enter number of elements:" << endl;
        cin >> arrLength;


        for (int i = 0; i < arrLength; i++) {
            arr[i] = RandomNumber(1, 100);
        }
    }
    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] > Max) {
                Max = arr[i];
            }
        }
        return Max;
    }
    int MinNumberInArray(int arr[100], int arrLength) 
    {
        int Min = 0;
        Min = arr[0];
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] < Min) {
                Min = arr[i];
            }
        }
        return Min;
    }
    int SumArrayNumbers(int arr[100], int arrLength) 
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++) {
            Sum += arr[i];
        }
        return Sum;
    }
    float AverageArrayNumbers(int arr[100], int arrLength)
    {
        return (float)SumArrayNumbers(arr, arrLength) / arrLength;
    }
    void AddArrayElement(int Number, int arr[100], int& arrLength) 
    {
//its a new element so we need to add the length by 1
        arrLength++;
        arr[arrLength - 1] = Number;
    }
    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }


}
