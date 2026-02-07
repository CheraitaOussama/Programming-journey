#pragma once

#include<iostream>
using namespace std;
#include <cstdlib>
namespace Numbers{

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
enPrimeNotPrime CheckPrime(int num)
{
    float M = round(num / 2);
    for (int counter = 2; counter <= M; counter++)
    {
        if (num % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;

}
enum enOddOrEven { odd = 1, even = 2 };
enOddOrEven CheckOddOrEven(int num) {

    if (num % 2 != 0)
        return enOddOrEven::odd;
    else
        return enOddOrEven::even;
}
enPrimeNotPrime ChekPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++) {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;

}
bool IsPerfectNumber(int Number)
{
    int sum = 0;
    for (int i = 1; i < Number; i++) {
        if (Number % i == 0) {
            sum += i;
        }
    }
    return Number == sum;
}
}
