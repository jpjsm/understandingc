// GraphNumberOfPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>  
#include <vector>  
#include <chrono>
#include <map>
#include "../../Sieve/Sieve/Sieve.h"

using namespace std::chrono;


int main()
{
    int ordermagnitude = 24;
    int primestofind = 1 << ordermagnitude;
    std::vector<uint8_t> sieve(primestofind + 1);

    std::cout << "starting sift " << std::endl;

    high_resolution_clock::time_point start = high_resolution_clock::now();
    sift(begin(sieve), primestofind);
    duration<double, std::ratio<1, 1000>> time2sift = high_resolution_clock::now() - start;

    std::cout << "Average time to Sieve first " << (int)primestofind << " possible primes: " << time2sift.count() << " milliseconds." << std::endl;

    int bit1 = 1;
    int bit2 = 3;
    int bit3 = 7;
    std::map<int, int>primes;

    for (size_t i = 0; i < ordermagnitude + 1; i++)
    {
        primes[bit1|1] = 0;
        primes[bit2|1] = 0;
        primes[bit3|1] = 0;

        bit1 <<= 1;
        bit2 <<= 1;
        bit3 <<= 1;
    }

    int primesfound = 1; // including two (2) as the first prime
    primes[2] = primesfound;
    int value = 3;
    for (int cii = 0; cii < sieve.size(); cii++)
    {
        if (sieve[cii])
        {
            primesfound++;
        }

        if (primes.count(value))
        {
            primes[value] = primesfound;
        }

        value += 2;
    }

    for (std::map<int, int>::iterator index = primes.begin(); index != primes.end(); index++)
    {
        std::cout << (*index).first << "," << (*index).second << std::endl;
    }

    return 0;
}

