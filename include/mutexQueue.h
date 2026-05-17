#include  "ConcurrentQueue.h"
#include "Task.h"
#include <mutex>
#include <vector>
#include <queue>

template<typename T>
class MutexQueue : public ConcurrentQueue<T> {  

    private:
    std::queue<T> queue_;  
    std::mutex mtx_;

public:
    MutexQueue() ;

    void push(const T& item) override;

    bool try_pop(T& out) override ;

};
