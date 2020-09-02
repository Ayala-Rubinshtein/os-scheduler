//
// Created by mby on 04/08/2020.
//
#include "Time.h"

Time::Time(unsigned long next_period_ms):m_next_period(next_period_ms)
{}

Time operator-(const Time& time1, const Time& time2)
{
    return Time(time1.getTime() - time2.getTime());
}

Time Time::now()
{
    unsigned long now = static_cast<unsigned long>(time(NULL));
    return Time(now);
}