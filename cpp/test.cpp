//
// Created by sagovski on 20.06.18.
//


#include <iostream>
#include <tr1/functional>

#include "CoreSelectionPolicy.h"
#include "Core.h"
#include "Thread.h"



int main(){
    std::cout<<"test"<<std::endl;
    Pastry p(2);
    p.print_info();
    std::cout<<p.add_thread()<<std::endl;
    std::cout<<p.add_free_core()<<std::endl;
    std::cout<<p.map_threads_to_cores()<<std::endl;

    Core c(3132);
    std::cout<<c.get_core_id()<<std::endl;

    Thread t(23453);
    std::cout<<t.get_thread_id()<<std::endl;

    std::size_t c_hsh = std::tr1::hash<std::string>(std::to_string(c.get_core_id()));
    std::size_t t_hsh = std::tr1::hash<std::string>(std::to_string(t.get_thread_id()));

    std::cout<<"hash: "<<c_hsh<<std::endl;
    std::cout<<"t hash: "<<t_hsh<<std::endl;
}
