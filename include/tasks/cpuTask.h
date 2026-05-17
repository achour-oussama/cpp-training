#include "../Task.h"


class CpuTask : public Task {
public:
    CpuTask(int id) : Task(id) {}

    void execute() override {
        volatile long sum = 0;
        for (int i = 0; i < 1000000; ++i)
            sum += i;
    }
};