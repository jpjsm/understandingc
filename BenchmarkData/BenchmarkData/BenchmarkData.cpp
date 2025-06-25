#include "stdafx.h"

#include <vector>  
#include <chrono>

#include "BenchmarkData.h"


BenchmarkData::BenchmarkData(std::size_t runSize)
{
    if (runSize < 10)
    {
        runSize = 10;
    }

    durations.reserve(runSize);
    max = seconds(-99999999);
    min = seconds(99999999);
    sum = seconds(0);
}

BenchmarkData::~BenchmarkData()
{
}

duration<double, std::ratio<1, 1000000>> BenchmarkData::Max()
{
    return max;
}

duration<double, std::ratio<1, 1000000>> BenchmarkData::Min()
{
    return min;
}

duration<double, std::ratio<1, 1000000>> BenchmarkData::Avg()
{
    return sum / durations.size();
}

duration<double, std::ratio<1, 1000000>> BenchmarkData::Sum()
{
    return sum;
}

void BenchmarkData::AddDuration(duration<double, std::ratio<1, 1000000>> d)
{
    durations.push_back(d);
    sum += d;
    if (d > max) max = d;
    if (d < min) min = d;
}

std::size_t BenchmarkData::Size()
{
    return durations.size();
}

duration<double, std::micro> BenchmarkData::RunValueAt(std::size_t i)
{
    if (i >= durations.size())
    {
        throw std::invalid_argument("Argument outside valid range; should be < number of runs (or items added).");
    }

    return duration<double, std::micro>(durations[i]);
}

