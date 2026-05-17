#include "../Task.h"    

class SleepTask : public Task {
public:
    SleepTask(int id) : Task(id) {}

    void execute() override {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};