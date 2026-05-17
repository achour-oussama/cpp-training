#include "../include/ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(int numThreads, ConcurrentQueue<std::shared_ptr<Task>>& queue)
    : queue_(queue) {
    for (int i = 0; i < numThreads; ++i) {
        workers_.emplace_back(&ThreadPool::worker_loop, this);
    }
    running_ = true;
}

void ThreadPool::worker_loop() {
    std::shared_ptr<Task> task;
    while (queue_.wait_pop(task)) {
        if (task) {
            task->execute();
            completed_tasks_++;
        }
    }
}

void ThreadPool::start() {
    // Workers are already started in constructor
    std::cout << "ThreadPool started with " << workers_.size() << " threads\n";
}

void ThreadPool::stop() {
    if (!running_) return;
    
    queue_.done();
    for (auto& worker : workers_) {
        if (worker.joinable()) {
            worker.join();
        }
    }
    running_ = false;
    std::cout << "ThreadPool stopped. Completed tasks: " << completed_tasks_ << "\n";
}

ThreadPool::~ThreadPool() {
    stop();
}

int ThreadPool::get_completed_tasks() const {
    return completed_tasks_.load();
}

bool ThreadPool::is_running() const {
    return running_;
}
