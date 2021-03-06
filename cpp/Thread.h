//
// Created by sagovski on 21.06.18.
//

#ifndef GEM5_THREAD_H
#define GEM5_THREAD_H


#include <stdint.h>
#include <tr1/functional>

class Thread
{
protected:
    uint16_t thread_id;
    std::size_t thread_hash;
    
public:
    Thread(uint16_t t_id);
    uint16_t get_thread_id();
    void set_thread_hash(std::size_t th);
    std::size_t get_thread_hash();
    
    void print_info();
    
private:
    void set_thread_id(uint16_t& t_id);
};


#endif //GEM5_THREAD_H
