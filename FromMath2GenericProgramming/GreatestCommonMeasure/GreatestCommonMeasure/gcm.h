#pragma once

#ifndef _gcm
#define _gcm

#define line_segment typename

#include <algorithm>

static size_t g0;
static size_t g1;

template<line_segment L> L gcm00(L a, L b)
{
/*
    if (a == b)      return a;
    if (b < a)       return gcm00(a - b, b);
    // if (b < a)    return gcm00(a, b - a);
*/
    
    while (a != b)
    {
        g0++;
        if (b < a)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return a;
}



template<line_segment L> L gcm01(L a, L b)
{
/*
    if (a == b)      return a;
    if (b < a) std::swap(a, b);

    // (b > a)
    L b2 = b << 1;
    while (b2 < a) b2 <<= 1;
    b2 >>= 1;
    
    return gcm01(a, b - a);
*/
    while (a != b)
    {
        g1++;

        if(b < a) std::swap(a, b);

        L a2 = a;
        while (a2 < b) 
        {
            a2 <<= 1;
            g1++;
        }

        a2 >>= 1;
        b -= a2;
    }

    return a;
}
#endif // !_gcm
