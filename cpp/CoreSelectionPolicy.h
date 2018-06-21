//
// Created by sagovski on 20.06.18.
//

#ifndef GEM5_CORESELECTIONPOLICY_H
#define GEM5_CORESELECTIONPOLICY_H

class CoreSelectionPolicy
{
protected:
    int window_size;

public:
    // Constructors
    CoreSelectionPolicy();
    CoreSelectionPolicy(int ws);
    
    // Member Functions
    void set_window_size(int& ws);
    void print_info();
    
    // Virtual Functions
    int add_free_core();
    int add_thread();
    int map_threads_to_cores();
};

class Pastry : public CoreSelectionPolicy
{
public:
    Pastry(int ws);
    void print_info();
    // Virtual Functions
    int add_free_core();
    int add_thread();
    int map_threads_to_cores();
};

#endif //GEM5_CORESELECTIONPOLICY_H
