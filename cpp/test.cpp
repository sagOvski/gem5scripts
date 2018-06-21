//
// Created by sagovski on 20.06.18.
//


#include <iostream>

#include "CoreSelectionPolicy.h"

int main(){
    std::cout<<"test"<<std::endl;
    Pastry p(2);
    p.print_info();
    std::cout<<p.add_thread()<<std::endl;
    std::cout<<p.add_free_core()<<std::endl;
    std::cout<<p.map_threads_to_cores()<<std::endl;
}