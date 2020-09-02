//
// Created by mby on 04/08/2020.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H

//#include <ctime>
#include <iostream>

class Time
{

public:
    Time(unsigned long);
    static Time now();
    unsigned long getTime()const;
    void setTime(unsigned long time);

private:
    unsigned long m_next_period;
};

inline unsigned long Time::getTime() const
{
    return m_next_period;
}

inline void Time::setTime(unsigned long time)
{
    m_next_period += time;
}
#endif //SCHEDULER_TIME_H
