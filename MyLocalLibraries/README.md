# My C++ Utility Libraries

This repository contains a set of reusable **C++ header libraries**
designed to make programming **simpler, cleaner, and more efficient**.

The libraries provide ready-to-use functions for:
- User input handling
- Number operations
- Random value generation
- Array manipulation
- General helper procedures

They are especially useful for learning, practicing, and building
small to medium C++ projects.

---

## Libraries Overview

- **Readers.h**  
  Functions for reading numbers and strings from the user.

- **Generators.h**  
  Functions to generate random numbers, characters, words, and operations.

- **Numbers.h**  
  Functions to check number properties such as:
  Prime, Odd/Even, Perfect numbers, and more.

- **Arrays.h**  
  Utility functions for array operations:
  Fill, Search, Copy, Print, Max, Min, Sum, Average, etc.

- **Procedures.h**  
  General helper functions used across different programs.

---

## Features

- Clean and reusable C++ functions
- Eliminates the need to rewrite common utilities
- Speeds up learning and project development
- Suitable for beginner and intermediate C++ programmers

---

## Example Usage

```cpp
#include <iostream>
#include "Readers.h"
#include "Generators.h"
#include "Numbers.h"
#include "Arrays.h"
#include "Procedures.h"

int main() {
    int num = Readers::ReadNumber();

    if (Numbers::CheckPrime(num) == Numbers::enPrimeNotPrime::Prime)
        std::cout << num << " is Prime\n";
    else
        std::cout << num << " is Not Prime\n";

    int randNum = Generators::RandomNumber(1, 50);
    std::cout << "Random number: " << randNum << std::endl;

    return 0;
}
