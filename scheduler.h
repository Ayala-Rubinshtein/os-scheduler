//
// Created by mby on 04/08/2020.
//

#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include "ITask.h"

#include <cstdio>
#include <queue>
#include <iostream>

class Scheduler{

public:
    Scheduler(std::vector<ITask*> tasks, unsigned long size_cycle);
    void run();
    void add(ITask* task);

private:
    unsigned long m_cycle_len;
    std::queue<ITask*> m_queue;
};

inline Scheduler::Scheduler(std::vector<ITask*> tasks, unsigned long size_cycle):m_cycle_len(size_cycle)
{
    std::cout<<"schedular constructor"<<std::endl;
    int i=0;
    for(;i<tasks.size();i++)
    {
        add(tasks[i]);
    }
    std::cout<<"end schedular constructor"<<std::endl;
}

inline void Scheduler::add(ITask* task)
{
    m_queue.push(task);
}

#endif //SCHEDULER_SCHEDULER_H
