// TestIntegerDivision.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define Integer typename

#include <iostream>
#include <stdexcept>

template <Integer I> struct QuotientReminder
{
public:
    I quotient;
    I reminder;

    QuotientReminder()
    {

    }

    QuotientReminder(I q, I r)
    {
        quotient = q;
        reminder = r;
    }
};

template<Integer I> QuotientReminder<I>* IntegerDivision(I n, I d)
{
    if (d == I(0))
    {
        throw std::invalid_argument("Denominator must be non-zero");
    }

    I f, p;
    QuotientReminder<I>* qr = new QuotientReminder<I>();

    qr->reminder = n;
    qr->quotient = 0;

    while (qr->reminder >= d)
    {
        f = d;
        p = 1;
        while (qr->reminder >= f)
        {
            f <<= 1;
            p <<= 1;
        }

        f >>= 1;
        p >>= 1;

        qr->reminder -= f;
        qr->quotient += p;
    }

    return qr;
}

template<Integer I> QuotientReminder<I>* IntegerDivision2(I n, I d)
{
    if (d == I(0))
    {
        throw std::invalid_argument("Denominator must be non-zero");
    }

    I f, p;
    QuotientReminder<I>* qr = new QuotientReminder<I>();

    qr->reminder = n;
    qr->quotient = 0;

    f = d;
    p = 1;

    while (qr->reminder > f)
    {
        f <<= 1;
        p <<= 1;
    }

    while (qr->reminder >= d)
    {

        f >>= 1;
        p >>= 1;

        if (qr->reminder >= f)
        {
            qr->reminder -= f;
            qr->quotient += p;
        }
    }

    return qr;
}


int main()
{
    typedef unsigned long long L;

    QuotientReminder<L> e1(1ULL, 1ULL);
    QuotientReminder<L>* t1 = IntegerDivision2<L>(3ULL, 2ULL);
    if (e1.quotient != t1->quotient || e1.reminder != t1->reminder)
    {
        std::cout << "ERROR: Expected different than recieved: e("<< e1.quotient << "," << e1.reminder << ") != t1(" << t1->quotient << "," << t1->reminder << ")" << std::endl;
    }

    QuotientReminder<L>* t2 = IntegerDivision2<L>(1001ULL, 169ULL);

    return 0;
}

