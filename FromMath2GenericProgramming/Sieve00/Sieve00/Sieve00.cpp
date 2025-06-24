// Sieve00.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#define RandomAccessIterator typename
#define Integer typename



#include <iostream>  
#include <vector>  
#include <chrono>
#include <string>  
#include "../../../BenchmarkData/BenchmarkData/BenchmarkData.h"
#include "../../Sieve/Sieve/Sieve.h"

//using namespace std;
using namespace std::chrono;


int main()
{
    int runs(10000);
    int primestofind(100000);
    uint8_t n_08(100);
    std::vector<uint8_t> sieve_08(primestofind +1);
    BenchmarkData SievingUint08(runs);

    uint16_t n_16(100);
    std::vector<uint16_t> sieve_16(primestofind + 1);
    BenchmarkData SievingUint16(runs);

    uint32_t n_32(100);
    std::vector<uint32_t> sieve_32(primestofind + 1);
    BenchmarkData SievingUint32(runs);

    uint64_t n_64(100);
    std::vector<uint64_t> sieve_64(primestofind + 1);
    BenchmarkData SievingUint64(runs);

    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i = 0; i < runs; i++)
    {
        start = high_resolution_clock::now();
        sift(begin(sieve_08), primestofind);
        SievingUint08.AddDuration( high_resolution_clock::now() - start);

        start = high_resolution_clock::now();
        sift(begin(sieve_16), primestofind);
        SievingUint16.AddDuration(high_resolution_clock::now() - start);

        start = high_resolution_clock::now();
        sift(begin(sieve_32), primestofind);
        SievingUint32.AddDuration(high_resolution_clock::now() - start);

        start = high_resolution_clock::now();
        sift(begin(sieve_64), primestofind);
        SievingUint64.AddDuration(high_resolution_clock::now() - start);
    }

    std::cout << "Average time to Sieve first " << (int)primestofind << " possible primes: " << SievingUint08.Avg().count() << " microseconds." << std::endl;
    std::cout << "Average time to Sieve first " << (int)primestofind << " possible primes: " << SievingUint16.Avg().count() << " microseconds." << std::endl;
    std::cout << "Average time to Sieve first " << (int)primestofind << " possible primes: " << SievingUint32.Avg().count() << " microseconds." << std::endl;
    std::cout << "Average time to Sieve first " << (int)primestofind << " possible primes: " << SievingUint64.Avg().count() << " microseconds." << std::endl;
    return 0;
}

