#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "List.hpp"

template <typename T>
class Stack
{
public:
    Stack()
    {
    }

    ~Stack()
    {
    }

    bool IsEmpty()
    {
        return _list.Length() == 0;
    }

    void Push(T t)
    {
        _list.Add(t);
    }

    T Top()
    {
        int len = _list.Length();
        if (len == 0)
        {
            throw new std::out_of_range("Stack is empty!");
        }
        return _list[len - 1];
    }

    T Pop()
    {
        int len = _list.Length();
        if (len == 0)
        {
            throw new std::out_of_range("Stack is empty!");
        }
        return _list.RemoveAt(len - 1);
    }

    void Clear()
    {
        _list.Clear();
    }

private:
    List<T> _list;
};

#endif // STACK_H
