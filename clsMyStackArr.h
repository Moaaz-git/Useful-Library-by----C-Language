#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
    void push(T Value)
    {
        clsMyQueueArr<T>::_MyList.InsertAtBeginning(Value);
    }

    T Top()
    {
        return clsMyQueueArr<T>::front();
    }

    T Bottom()
    {
        return clsMyQueueArr<T>::back();
    }
};