//
// Created by mby on 04/08/2020.
//

#ifndef SCHEDULER_SWIMMING_H
#define SCHEDULER_SWIMMING_H

#include "ITask.h"
#include "Time.h"

#include <cstdio>
#include <iostream>

struct Swimming:public ITask{

public:
    Swimming(Time begin, size_t num_cycle, size_t wait);
    /*virtual*/ ~Swimming(){};
    /*virtual*/ void run();
    /*virtual*/ unsigned long getNextRunPeriod(); // in milliseconds
    /*virtual*/ void setNextTime();
    /*virtual*/ void decreaseCycles();
    /*virtual*/ size_t getCycleLeft();

private:
    Time m_begin_time;
    size_t m_num_of_cycles;
    size_t m_wait_between_cycles;
};

inline Swimming::Swimming(Time begin, size_t num_cycle, size_t wait):
        m_begin_time(begin),
        m_num_of_cycles(num_cycle),
        m_wait_between_cycles(wait){}

inline unsigned long Swimming::getNextRunPeriod(){

    if(m_begin_time.getTime()-time(NULL) < 0)
    {
        return 0;
    }
    return m_begin_time.getTime()-(unsigned long)time(NULL);
}

inline void Swimming::run()
{
    setNextTime();
    decreaseCycles();
    std::cout<<"function swimming"<<std::endl;
}

inline void Swimming::setNextTime()
{
    m_begin_time.setTime(m_wait_between_cycles);
}

inline void Swimming::decreaseCycles()
{
    m_num_of_cycles--;
}

inline size_t Swimming::getCycleLeft()
{
    return m_num_of_cycles;
}

#endif //SCHEDULER_SWIMMING_H
