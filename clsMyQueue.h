#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{
protected:
    clsDblLinkedList<T> _MyList;

public:
    void push(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }

    void pop()
    {
        _MyList.DeleteAtFirst();
    }

    void Print()
    {
        _MyList.PrintList();
    }

    int Size()
    {
        return _MyList.Size();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(Size() - 1);
    }

    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    bool UpdateItem(int Index, T NewValue)
    {
        return _MyList.UpdateItem(Index, NewValue);
    }

    void InsertAfter(int Index, T Value)
    {
        _MyList.InsertAfter(Index, Value);
    }

    void InsertAtFront(T Value)
    {
        _MyList.InsertAtBegining(Value);
    }

    void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyList.Clear();
    }
};