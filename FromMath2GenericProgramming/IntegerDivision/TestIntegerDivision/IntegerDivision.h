#pragma once

#ifndef _IntegerDivision
#define _IntegerDivision

#define Integer typename

template <Integer I> struct QuotientReminder
{
public:
    I quotient;
    I reminder;
};

template<Integer I> QuotientReminder<I>* IntegerDivision(I n, I d);
#endif // !_IntegerDivision

