//
// Created by sagovski on 21.06.18.
//

#include "Core.h"
#include <iostream>

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

void Core::set_core_hash(std::size_t ch)
{
    core_hash = ch;
}

std::size_t Core::get_core_hash()
{
    return core_hash;
}

void Core::print_info()
{
    std::cout<< "Core info: " << std::endl;
    std::cout<< "core_id: " << get_core_id() << std::endl;
    std::cout<< "core_hash: " << get_core_hash() << std::endl;
    std::cout<< std::endl;
}
