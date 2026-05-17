#include "../include/Producer.h"
#include <iostream>
#include <chrono>

Producer::Producer(ConcurrentQueue<std::shared_ptr<Task>>& queue, int numTasks, int delay_ms)
    : queue_(queue), numTasks_(numTasks), delay_ms_(delay_ms) {} 

void Producer::start() {
    producer_thread_ = std::thread(&Producer::produce, this);
}

void Producer::produce() {
    std::cout << "Producer started, generating " << numTasks_ << " tasks\n";
    for (int i = 0; i < numTasks_; ++i) {
        auto task = std::make_shared<Task>(i);
        queue_.push(task);
        
        if (delay_ms_ > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
        }
    }
    std::cout << "Producer finished generating all tasks\n";
}

void Producer::wait() {
    if (producer_thread_.joinable()) {
        producer_thread_.join();
    }
}

Producer::~Producer() {
    if (producer_thread_.joinable()) {
        producer_thread_.join();
    }
}