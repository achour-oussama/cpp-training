#pragma once

#include <iostream>
#include <thread>

class Task {
protected:
    int id;
    
public:    
    Task(int id) : id(id) {}
    virtual void execute() {
        std::cout << "Task " << id << " executed on thread " << std::this_thread::get_id() << "\n";
    }
    virtual ~Task() = default;

};