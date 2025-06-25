// PerfectNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <iostream>
#include <chrono>

#define Integer typename
#define Logical typename

template <Integer N> bool IsPerfect(N i) {
    N factor1(2);
    N factor2;
    N sum(1);

    do
    {
        factor2 = i / factor1;
        if ((factor2 * factor1) == i)
        {
            sum += factor1 + factor2;
        }

        factor1++;
    } while (factor1 < factor2);

    return sum == i;
}


int main()
{
    std::locale loc("English_America");
    std::cout.imbue(loc);
    std::cerr.imbue(loc);
    size_t factor1, factor2, sum, lastpass, length;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::ratio<1, 1000>> lap;
    lastpass = 0;
    size_t runsize = 0x8000000000000000ULL;

    for (size_t i = 1; i < runsize; i++)
    {

        if (IsPerfect(i))
        {
            //perfect.push_back(i);
            std::cout << i << std::endl;
        }

        // report activity
        if ((i & 0xFFFFF) == 0x80000)
        {
            length = i - lastpass;
            lap = std::chrono::high_resolution_clock::now() - start;
            std::cerr << "Lap: " << i << ", length:" << length << ". Completed in " << lap.count() << " milliseconds" << std::endl;
            std::cerr.flush();
            lastpass = i;
            start = std::chrono::high_resolution_clock::now();
        }
    }


    return 0;
}

