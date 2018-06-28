//
// Created by sagovski on 20.06.18.
//


#include <iostream>
#include <map>
#include <tr1/functional>
#include <limits>

#include "CoreSelectionPolicy.h"
// #include "../../src/doxygen/stl.hh"


Pastry::Pastry(int ws, int core_count)
{
    set_window_size(ws);
    set_sys_core_count(core_count);
}

void Pastry::print_info()
{
    std::cout << " Pastry: window_size " << window_size << std::endl;
    std::cout << " Pastry: sys_core_count " << sys_core_count << std::endl;

    std::cout<< "Pastry: core_pool " << free_cores.size() << std::endl;
    std::cout << "Pastry: thread_pool " << executable_threads.size() << std::endl;
}

int Pastry::add_free_core(int cid)
{
    Core c(cid);
    c.set_core_hash(cid);
    free_cores.push_back(c);

    std::cout<< "Added core! "<< std::endl;
    c.print_info();

    if((window_size == free_cores.size()) && (window_size == executable_threads.size())) {
        return map_threads_to_cores();
    }
    return 0;
}

int Pastry::add_thread(int tid)
{
    Thread t(tid);
    t.set_thread_hash(t.get_thread_id() % sys_core_count);
    executable_threads.push_back(t);

    std::cout<< "Added thread! "<< std::endl;
    t.print_info();

    if((window_size == free_cores.size()) && (window_size == executable_threads.size())) {
        return map_threads_to_cores();
    }

    return 0;
}

int Pastry::map_threads_to_cores()
{
    std::map<int, int> tc_map;
    int i,j,min_diff_index = 0;
    std::size_t diff;
    std::size_t min_diff;

    for(i = 0, j=0; i< window_size; ++i, ++j) {
        tc_map.insert(std::pair<int, int>(free_cores[i].get_core_id(), executable_threads[i].get_thread_id()));
    }

    for(i=0; i<window_size; ++i) {
        min_diff = SIZE_MAX;
        for(j=0; j< window_size; ++j) {
            diff = free_cores[i].get_core_hash() - executable_threads[j].get_thread_hash();
            if(min_diff > diff){
                min_diff = diff;
                min_diff_index = j;
            }
        }
        tc_map.insert(std::pair<int, int>(free_cores[i].get_core_id(), executable_threads[min_diff_index].get_thread_id()));
    }

    std::map<int, int> :: iterator itr;
    std::cout << "Core <-> Thread mapping: " << std::endl;
    for(itr = tc_map.begin(); itr!=tc_map.end(); ++itr) {
        std::cout << itr->first << "\t" << itr->second << std::endl;
    }
    std::cout<< std::endl;

    free_cores.clear();
    executable_threads.clear();

    return 0;
}
