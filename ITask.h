//
// Created by mby on 04/08/2020.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

#include <cstdio>

struct ITask{

public:
    virtual ~ITask(){};
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
    virtual void setNextTime() = 0;
    virtual void decreaseCycles() = 0;
    virtual size_t getCycleLeft() = 0;
};

#endif //SCHEDULER_ITASK_H
