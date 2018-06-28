//
// Created by sagovski on 20.06.18.
//

#include <iostream>
#include "CoreSelectionPolicy.h"

CoreSelectionPolicy::CoreSelectionPolicy()
{
}

CoreSelectionPolicy::CoreSelectionPolicy(int ws)
{
    set_window_size(ws);
    window_size = ws;
}

void CoreSelectionPolicy::set_window_size(int & ws)
{
    window_size = ws;
}

void CoreSelectionPolicy::print_info()
{
    std::cout << " CoreSelectionPolicy: window_size " << window_size << std::endl;
}

std::string CoreSelectionPolicy::intToString(int num)
{
    std::string numAsStr;
    while (num)
    {
        char toInsert = (num % 10) + 48;
        numAsStr.insert(0, 1, toInsert);
        num /= 10;
    }
    return numAsStr;
}