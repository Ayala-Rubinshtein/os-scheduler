//
// Created by mby on 04/08/2020.
//

#ifndef SCHEDULER_PRINT_H
#define SCHEDULER_PRINT_H

#include "ITask.h"
#include "Time.h"

#include <cstdio>
#include <iostream>

struct Print:public ITask{

public:
    Print(Time begin, size_t num_cycle, unsigned long wait);
    /*virtual*/ ~Print(){};
    /*virtual*/ void run();
    /*virtual*/ unsigned long getNextRunPeriod(); // in milliseconds
    /*virtual*/ void setNextTime();
    /*virtual*/ void decreaseCycles();
    /*virtual*/ size_t getCycleLeft();

private:
    Time m_begin_time;
    size_t m_num_of_cycles;
    unsigned long m_wait_between_cycles;
};

inline Print::Print(Time begin, size_t num_cycle, unsigned long wait):
    m_begin_time(begin),
    m_num_of_cycles(num_cycle),
    m_wait_between_cycles(wait*1000){}

inline unsigned long Print::getNextRunPeriod()
{

    if(m_begin_time.getTime()-time(NULL)<0)
    {
        return 0;
    }
    return m_begin_time.getTime()-(unsigned long)time(NULL);
}

inline void Print::run()
{
    setNextTime();
    decreaseCycles();
    std::cout<<"function print"<<std::endl;
}

inline void Print::setNextTime()
{
    m_begin_time.setTime(m_wait_between_cycles);
}

inline void Print::decreaseCycles()
{
    m_num_of_cycles--;
}

inline size_t Print::getCycleLeft()
{
    return m_num_of_cycles;
}

#endif //SCHEDULER_PRINT_H
