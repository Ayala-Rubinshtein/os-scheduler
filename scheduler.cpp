//
// Created by mby on 04/08/2020.
//

#include "scheduler.h"

#include <unistd.h>


void Scheduler::run(){
    std::cout<<"schedular run"<<std::endl;
    while (!m_queue.empty())
    {
        std::cout<<"run"<<std::endl;
        ITask *t = m_queue.front();
        m_queue.pop();
        sleep(t->getNextRunPeriod()/1000);
        //std::cout<<"cycle: "<<tmp->cycles_left<<std::endl;
        t->run();
        if(t->getCycleLeft() > 0)
        {
            m_queue.push(t);
        }
    }
    std::cout<<"end run"<<std::endl;
}

/*Queue* Scheduler::deQueue(){
    std::cout<<"schedular dequeue"<<std::endl;
    Queue* tmp=m_head;
    m_head = m_head->next;
    return tmp;
}

void Scheduler::enQueue(Queue* add_tail){
    std::cout<<"schedular enqueue"<<std::endl;

    if(!m_head)
    {
        std::cout<<"if enqueue"<<std::endl;
        m_head = add_tail;
        m_tail = m_head;
    }
    else
    {
        m_tail->next = add_tail;
        m_tail = m_tail->next;
    }
}*/