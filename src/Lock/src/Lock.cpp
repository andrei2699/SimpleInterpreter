#include "Lock.hpp"
#include <iostream>

Lock::Lock(std::mutex *m)
{
    std::cout << "Lock" << std::endl;

    m->lock();
    mutex_ptr.reset(m, unlock);
}

Lock::~Lock()
{
}

void unlock(std::mutex *m)
{
    std::cout << "Unlock" << std::endl;

    m->unlock();
}