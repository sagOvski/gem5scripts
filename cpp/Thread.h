//
// Created by sagovski on 21.06.18.
//

#ifndef GEM5_THREAD_H
#define GEM5_THREAD_H


#include <stdint-gcc.h>

class Thread
{
protected:
    uint16_t thread_id;
    
public:
    Thread(uint16_t t_id);
    uint16_t get_thread_id();
    
private:
    void set_thread_id(uint16_t& t_id);
};


#endif //GEM5_THREAD_H
