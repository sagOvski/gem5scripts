//
// Created by sagovski on 20.06.18.
//


#include <iostream>
#include "CoreSelectionPolicy.h"

Pastry::Pastry(int ws)
{
    set_window_size(ws);
}

void Pastry::print_info()
{
    std::cout << " Pastry: window_size " << window_size << std::endl;
}

int Pastry::add_free_core()
{
    return 0;
}

int Pastry::add_thread()
{
    return 0;
}

int Pastry::map_threads_to_cores()
{
    return 0;
}