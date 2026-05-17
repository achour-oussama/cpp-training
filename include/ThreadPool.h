#pragma once

#include <thread>
#include <vector>
#include <atomic>
#include <memory>
#include "ConcurrentQueue.h"    
#include "Task.h"

class ThreadPool {
public:
    ThreadPool(int numThreads, ConcurrentQueue<std::shared_ptr<Task>>& queue);
    void start();
    void stop();
    ~ThreadPool();
    int get_completed_tasks() const;
    bool is_running() const;
private:
    void worker_loop();
    std::vector<std::thread> workers_;
    ConcurrentQueue<std::shared_ptr<Task>>& queue_;
    std::atomic<bool> done_{false};
    std::atomic<int> completed_tasks_{0};
    bool running_{false};
};