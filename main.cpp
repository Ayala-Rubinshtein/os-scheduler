//
// Created by mby on 04/08/2020.
//

#include <vector>
#include "scheduler.h"
#include "print.h"
#include "swimming.h"

int main()
{
    Time _time(time(0));
    Print p1(_time, 1, 2);
    Print p2(_time, 2, 0.8);
    Print p3(_time, 3, 1);
    Swimming s1(_time, 6, 0.5);
    std::vector<ITask*> tasks = {&p3, &s1};
    Scheduler s(tasks, 1);
    s.run();

    return 0;
}
