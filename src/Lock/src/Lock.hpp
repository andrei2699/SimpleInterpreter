#ifndef LOCK_H
#define LOCK_H

#include <memory>
#include <mutex>

class Lock
{
public:
    explicit Lock(std::mutex *m);
    ~Lock();

private:
    std::shared_ptr<std::mutex> mutex_ptr;
};

void unlock(std::mutex *m);

#endif // LOCK_H
