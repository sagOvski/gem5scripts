//
// Created by sagovski on 20.06.18.
//

#ifndef GEM5_CORESELECTIONPOLICY_H
#define GEM5_CORESELECTIONPOLICY_H

#include <vector>
#include "Thread.h"
#include "Core.h"

class CoreSelectionPolicy
{
protected:
    int window_size;
    int sys_core_count;

    std::vector<Core> free_cores;
    std::vector<Thread> executable_threads;

public:
    // Constructors
    CoreSelectionPolicy();
    CoreSelectionPolicy(int ws, int cs);

    // Member Functions
    void set_window_size(int& ws);
    void set_sys_core_count(int& cs);
    void print_info();
    std::string intToString(int num);

    // Virtual Functions
    int add_free_core(int);
    int add_thread(int);
    int map_threads_to_cores();
};

class Pastry : public CoreSelectionPolicy
{
public:
    Pastry(int ws, int cs);
    void print_info();

    int add_free_core(int);
    int add_thread(int);
    int map_threads_to_cores();
};

#endif //GEM5_CORESELECTIONPOLICY_H
