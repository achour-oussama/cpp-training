#pragma once

#include <thread>
#include <memory>
#include <chrono>
#include "Task.h"
#include "ConcurrentQueue.h"

class Producer {
public:
    Producer(ConcurrentQueue<std::shared_ptr<Task>>& queue, int numTasks, int delay_ms = 0);
    void start();
    void wait();
    ~Producer();

private:
    void produce();
    ConcurrentQueue<std::shared_ptr<Task>>& queue_;
    int numTasks_;
    int delay_ms_;
    std::thread producer_thread_;
};

