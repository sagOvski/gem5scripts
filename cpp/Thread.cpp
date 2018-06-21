//
// Created by sagovski on 21.06.18.
//

#include "Thread.h"

Thread::Thread(uint16_t t_id)
{
    set_thread_id(t_id);
}

void Thread::set_thread_id(uint16_t &t_id)
{
    thread_id = t_id;
}

uint16_t Thread::get_thread_id()
{
    return thread_id;
}
