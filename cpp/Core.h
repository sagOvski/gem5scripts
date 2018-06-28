//
// Created by sagovski on 21.06.18.
//

#ifndef GEM5_CORE_H
#define GEM5_CORE_H

#include <stdint.h>
#include <tr1/functional>

class Core
{
protected:
    uint16_t core_id;
    std::size_t core_hash;
    
public:
    Core(uint16_t cr_id);
    uint16_t get_core_id();
    void set_core_hash(std::size_t ch);
    std::size_t get_core_hash();
    void print_info();
    
private:
    void set_core_id(uint16_t& cr_id);
};


#endif //GEM5_CORE_H
