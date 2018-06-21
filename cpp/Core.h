//
// Created by sagovski on 21.06.18.
//

#ifndef GEM5_CORE_H
#define GEM5_CORE_H

#include <stdint.h>

class Core
{
protected:
    uint16_t core_id;
    
public:
    Core(uint16_t cr_id);
    uint16_t get_core_id();
    
private:
    void set_core_id(uint16_t& cr_id);
};


#endif //GEM5_CORE_H
