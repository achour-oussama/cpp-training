#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <memory>

#include "../include/Task.h"
#include "../include/ConcurrentQueue.h"
#include "../include/ThreadPool.h"
#include "../include/Producer.h"

int main()
{
    std::cout << "=== Producer-Consumer Pattern Demo ===\n\n";

    // Create the concurrent queue
    ConcurrentQueue<std::shared_ptr<Task>> task_queue;

    // Create thread pool with 4 worker threads
    ThreadPool pool(4, task_queue);
    pool.start();

    // Create producer that will generate 20 tasks
    Producer producer(task_queue, 20, 10); // 20 tasks, 10ms delay between each
    producer.start();

    // Wait for producer to finish
    producer.wait();

    // Wait for all tasks to be processed
    pool.stop();

    std::cout << "\n=== Demo Complete ===\n";
    std::cout << "Total tasks completed: " << pool.get_completed_tasks() << "\n";

    return 0;
}