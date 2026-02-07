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
}
