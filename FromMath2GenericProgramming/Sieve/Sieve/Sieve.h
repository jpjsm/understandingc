#pragma once

#define RandomAccessIterator typename
#define Integer typename


#include <vector>  

template <Integer N> N ValueFromIndex(N i) {
    return i + i + 3;
}

template <RandomAccessIterator I, Integer N>void mark_sieve(I first, I last, N factor) {
    //assert(first != last)
    *first = false;
    while (last - first > factor)
    {
        first += factor;
        *first = false;
    }
}

template <RandomAccessIterator I, Integer N> void sift(I first, N n) {
    std::fill(first, first + n, true);
    N i(0);
    N index_square(3);
    N factor = 3;

    while (index_square < n)
    {
        if (first[i])
        {
            mark_sieve(first + index_square, first + n, factor);
        }

        ++i;
        index_square += factor;
        factor += N(2);
        index_square += factor;
    }

}

template <RandomAccessIterator I, Integer N>void print_sieve(I first, N n) {
    N i{ 0 };
    std::cout << 2;
    while (i < n) {
        if (*first) {
            std::cout << " " << ValueFromIndex(i);
        }
        ++first;
        ++i;
    }
    std::cout << std::endl;
}

