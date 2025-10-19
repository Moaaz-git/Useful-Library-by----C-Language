#pragma once

#include <iostream>
// #include <clsMyStack.h>

using namespace std;
template <class T>
class clsDynamicArray
{
protected:
    int _Size = 0;
    T *_TempArray;

public:
    T *OriginalArray;
    // pointer to the first item in array with data type T;

    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;

        _Size = size;
        // create array with _Size element and make pointer point to the first item
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }

    bool SetItem(int Index, T Value)
    {
        if (Index >= _Size || Index < 0)
        {
            return false;
        }
        OriginalArray[Index] = Value;
        return true;
    }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
            NewSize = 0;

        // create a new array to copy last elements to it
        _TempArray = new T[NewSize];

        // limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        // copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;
        delete[] OriginalArray;

        OriginalArray = _TempArray;
    }

    void Reverse()
    {
        _TempArray = new T[_Size];

        int Count = 0;
        for (int i = (_Size - 1); i >= 0; i--)
        {
            _TempArray[Count] = OriginalArray[i];
            Count++;
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    bool DeleteItemAt(int Index)
    {

        if (Index >= _Size || Index < 0)
            return false;

        _Size--;
        _TempArray = new T[_Size];

        // copy elements befor index
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        // ignore index and copy elements after index to [i -1] because size of temp is 9 but org is 10;
        //_size +1 : because we decrease size of array befor now to visit all elements in origin array
        // index + 1 : start from the element after elements we want te delete
        for (int i = Index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

        // _TempArray = new T[_Size];

        // for (int i = 0; i < _Size; i++)
        // {
        //     if (i >= Index)
        //     {
        //         _TempArray[i] = OriginalArray[i + 1];
        //         continue;
        //     }
        //     _TempArray[i] = OriginalArray[i];
        // }

        // _Size--;
        // delete[] OriginalArray;
        // OriginalArray = _TempArray;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Print()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << OriginalArray[i] << "  ";
        }
        cout << "\n";
    }

    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;
    }

    bool DeleteItem(T Value)
    {
        int Index = Find(Value);

        if (Index == -1)
            return false;

        DeleteItemAt(Index);
        return true;
    }

    bool InsertAt(int Index, T Value)
    {
        if (Index > _Size || Index < 0)
            return false;

        _Size++;
        _TempArray = new T[_Size];

        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }
        _TempArray[Index] = Value;
        for (int i = Index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }

    bool InsertAtBeginning(T Value)
    {
        return InsertAt(0, Value);
    }

    bool InsertAfter(int Index, T Value)
    {
        if(Index >= _Size)
        {
            return InsertAt[_Size - 1,Value];
        }
        return InsertAt(Index + 1, Value);
    }

    bool InsertBefor(int Index, T Value)
    {
        if(Index < 0)
        {
            return InsertAt[0,Value];
        }
        return InsertAt(Index - 1, Value);
    }

    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size, Value);
    }
};