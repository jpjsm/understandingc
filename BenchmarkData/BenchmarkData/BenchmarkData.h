#pragma once

using namespace std::chrono;

class BenchmarkData
{
public:
    BenchmarkData(std::size_t runSize);
    ~BenchmarkData();
    duration< double, std::ratio< 1, 1000000> >Max();
    duration< double, std::ratio< 1, 1000000> >Min();
    duration< double, std::ratio< 1, 1000000> >Avg();
    duration< double, std::ratio< 1, 1000000> >Sum();
    void AddDuration(duration< double, std::ratio< 1, 1000000> > d);
    std::size_t Size();
    duration< double, std::micro >RunValueAt(std::size_t i);

private:
    std::vector<duration< double, std::ratio< 1, 1000000> >> durations;

    duration< double, std::micro > max;
    duration< double, std::micro > min;
    duration< double, std::micro > sum;
};
