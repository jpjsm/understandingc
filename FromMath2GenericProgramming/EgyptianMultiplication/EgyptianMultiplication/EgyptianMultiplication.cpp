// EgyptianMultiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int multiply0(unsigned int a, unsigned int b)
{
    unsigned int r = 0;
    if (b == 0) return r;

    while (a > 0)
    {
        if (a & 1) r += b;
        a >>= 1;
        b = b + b;
    }

    return r;
}

int main()
{
    unsigned int c = multiply0(43, 3);
    return 0;
}

