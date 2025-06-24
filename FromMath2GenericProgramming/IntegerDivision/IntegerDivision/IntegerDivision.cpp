// IntegerDivision.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "IntegerDivision.h"

template<Integer I> QuotientReminder<I>* IntegerDivision(I n, I d)
{
    I f, p;
    QuotientReminder* qr = new QuotientReminder();

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
