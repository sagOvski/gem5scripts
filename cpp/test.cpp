//
// Created by sagovski on 20.06.18.
//


#include <iostream>
#include <tr1/functional>

#include "CoreSelectionPolicy.h"
#include "Core.h"
#include "Thread.h"


std::string intToString(int num)
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

int main(){
    std::cout<<"test"<<std::endl;
    Pastry p(8);
    p.print_info();

//    p.add_free_core(1234);
//    p.add_thread(4567);
//
//    p.add_free_core(9876);
//    p.add_thread(7654);
    int i;
    for(i = 0; i< 128; ++i) {
        p.add_free_core(rand() % 128);
        p.add_thread(rand() % 1024 + 2048);
    }
    
    p.print_info();
    
//    std::cout<<p.add_thread()<<std::endl;
//    std::cout<<p.add_free_core()<<std::endl;
//    std::cout<<p.map_threads_to_cores()<<std::endl;

//    Core c(3132);
//    std::cout<<c.get_core_id()<<std::endl;
//
//    Thread t(23453);
//    std::cout<<t.get_thread_id()<<std::endl;
//
//    std::size_t c_hsh = std::tr1::hash<std::string>(intToString(c.get_core_id()));
//    std::size_t t_hsh = std::tr1::hash<std::string>(intToString(t.get_thread_id()));
//
//    std::cout<<"hash: "<<c_hsh<<std::endl;
//    std::cout<<"t hash: "<<t_hsh<<std::endl;




}
