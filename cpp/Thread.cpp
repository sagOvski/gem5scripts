//
// Created by sagovski on 21.06.18.
//

#include "Thread.h"
#include <iostream>

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

void Thread::set_thread_hash(std::size_t th)
{
    thread_hash = th;
}

std::size_t Thread::get_thread_hash()
{
    return thread_hash;
}

void Thread::print_info()
{
    std::cout<< "Thread info: " << std::endl;
    std::cout<< "thread_id: " << get_thread_id() << std::endl;
    std::cout<< "thread_hash: " << get_thread_hash() << std::endl;
    std::cout<< std::endl;
}