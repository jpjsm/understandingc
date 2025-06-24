// PalindromicPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iostream>  
#include <vector>  
#include <chrono>
#include <map>
#include <string>
#include "../../Sieve/Sieve/Sieve.h"

using namespace std::chrono;



int main()
{
    size_t ordermagnitude = 35;
    size_t primestofind = 1ULL << ordermagnitude;
    std::vector<uint8_t> sieve(primestofind + 1);

    high_resolution_clock::time_point start = high_resolution_clock::now();
    sift(begin(sieve), primestofind);
    duration<double, std::ratio<1, 1000>> time2sift = high_resolution_clock::now() - start;

    std::cerr << "Time to Sieve first " << (size_t)primestofind << " possible primes: " << time2sift.count() << " milliseconds." << std::endl;

    size_t palindromecount(0);
    start = high_resolution_clock::now();
    size_t maxprime(0);
    size_t p;
    for (size_t i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            p = ValueFromIndex(i);
            if (p > maxprime) maxprime = p;
            std::string prime = std::to_string(p);
            std::string emirp(prime);
           reverse(emirp.begin(), emirp.end());

           if (prime == emirp )
           {
               palindromecount++;
               std::cout << p << std::endl;
           }
        }
    }

    duration<double, std::ratio<1, 1000>> time2palindrome = high_resolution_clock::now() - start;

    std::cerr << "Time to find  first " << palindromecount << " palindrome primes of " << maxprime <<" max prime: " << time2palindrome.count() << " milliseconds." << std::endl;



    return 0;
}

