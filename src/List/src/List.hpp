#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <typename T>
class List
{
public:
    List(T arr[], int size)
    {
        Init();

        for (int i = 0; i < size; i++)
        {
            Add(arr[i]);
        }
    }

    List(const List &other)
    {
        Init();

        for (int i = 0; i < other._currentIndex; i++)
        {
            Add(other._list[i]);
        }
    }

    List()
    {
        Init();
    }

    ~List()
    {
        Clear();
    }

    T &operator[](int i)
    {
        if (i < 0 || i >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return _list[i];
    }

    int Length()
    {
        return _currentIndex;
    }

    void Add(T t)
    {
        if (_size == 0)
        {
            _size = 1;
            _list = new T[_size];
        }
        else if (_currentIndex >= _size)
        {
            T *newList = new T[_size * 2];
            for (int i = 0; i < _size; i++)
            {
                newList[i] = _list[i];
            }
            delete[] _list;
            _list = newList;

            _size *= 2;
        }

        _list[_currentIndex] = t;
        _currentIndex++;
    }

    T RemoveAt(int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        T value = _list[index];

        for (int i = index; i < _currentIndex - 1; i++)
        {
            _list[i] = _list[i + 1];
        }
        _currentIndex--;

        return value;
    }

    void Clear()
    {
        if (_size > 0)
        {
            _currentIndex = 0;
            _size = 0;
            delete[] _list;
        }
    }

private:
    int _size;
    int _currentIndex;
    T *_list;

    inline void Init()
    {
        _size = 0;
        _currentIndex = 0;
    }
};

#endif // LIST_H
