//
// Created by sagovski on 21.06.18.
//

#include "Core.h"

Core::Core(uint16_t cr_id) {
    set_core_id(cr_id);
}

void Core::set_core_id(uint16_t& cr_id)
{
    core_id = cr_id;
}

uint16_t Core::get_core_id()
{
    return core_id;
}