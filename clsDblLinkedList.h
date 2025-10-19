#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;
    int _Index = -1;

public:
    class Node
    {
    public:
        T Value;
        Node *Next;
        Node *Prev;

        Node()
        {
            Value;
            Next = NULL;
            Prev = NULL;
        }
    };

    Node *head = NULL;

    void InsertAtBegining(T Value)
    {

        /*
         1-Create a new node with the desired value.
         2-Set the next pointer of the new node to the current head of the list.
         3-Set the previous pointer of the current head to the new node.
         4-Set the new node as the new head of the list.
     */

        Node *new_Node = new Node;
        new_Node->Value = Value;
        if (head == NULL)
        {
            head = new_Node;
            _Size++;
            _Index++;
            return;
        }
        else
        {
            new_Node->Next = head;
            head->Prev = new_Node;
            head = new_Node;
            _Size++;
            _Index++;
        }
    }

    void PrintList()
    {
        Node *Current = head;

        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }

        cout << "\n";
        delete Current;
    }

    Node *Find(T Value)
    {
        Node *Current = head;

        while (Current != NULL)
        {
            if (Current->Value == Value)
            {
                return Current;
            }
            Current = Current->Next;
        }

        return NULL;
    }

    void InsertAfter(Node *PrevNode, T Value)
    {

        /*  1 - Create a new node with the desired value.
        2-Set the next pointer of the new node to the next node of the current node.
        3-Set the previous pointer of the new node to the current node.
        4-Set the next pointer of the current node to the new node.
        5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node *new_Node = new Node;
        new_Node->Value = Value;

        if (PrevNode->Next == NULL)
        {
            PrevNode->Next = new_Node;
            new_Node->Prev = PrevNode;
            _Size++;
            _Index++;
            return;
        }
        else
        {
            new_Node->Next = PrevNode->Next;
            new_Node->Prev = PrevNode;
            PrevNode->Next->Prev = new_Node;
            PrevNode->Next = new_Node;
            _Index++;
            _Size++;
        }
    }

    void InsertAtEnd(T Value)
    {

        /*
        1-Create a new node with the desired value.
        2-Traverse the list to find the last node.
        3-Set the next pointer of the last node to the new node.
        4-Set the previous pointer of the new node to the last node.
        */
        Node *new_Node = new Node;
        new_Node->Value = Value;

        Node *Current = head;
        if (head == NULL)
        {
            head = new_Node;
            _Index++;
            _Size++;
            return;
        }

        else
        {
            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }
            Current->Next = new_Node;
            new_Node->Prev = Current;
            _Index++;
            _Size++;
        }
    }

    void DeleteNode(Node *NodeToDelete)
    {
        /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
                3-Delete the current node.
                */
        if (head == NULL || NodeToDelete == NULL)
        {
            cout << "\nCan't Delete Node Because it is empty....  [:(]. \n";
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->Next;
            delete NodeToDelete;
            _Index--;
            _Size--;
            return;
        }

        if (NodeToDelete->Next != NULL)
        {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }

        if (NodeToDelete->Prev != NULL)
        {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }
        _Size--;
        _Index--;
        delete NodeToDelete;
    }

    void DeleteAtFirst()
    {

        /*
        1-Store a reference to the head node in a temporary variable.
        2-Update the head pointer to point to the next node in the list.
        3-Set the previous pointer of the new head to NULL.
        4-Delete the temporary reference to the old head node.
        */
        if (head == NULL)
        {
            cout << "\nCan't Delete Node Because it is empty....  [:(]. \n";
            return;
        }

        else
        {
            Node *Current = head;
            head = head->Next;
            if (head != NULL)
            {
                head->Prev = NULL;
            }
            delete Current;
            _Index--;
            _Size--;
        }
    }

    void DeleteEnd()
    {

        /*
        1-Traverse the list to find the last node.
        2-Set the next pointer of the second-to-last node to NULL.
        3-Delete the last node.
        */

        if (head == NULL)
        {
            cout << "\nCan't Delete Node Because it is empty....  [:(]. \n";
            return;
        }

        if (head->Next == NULL)
        {
            delete head;
            head = NULL;
            _Index--;
            _Size--;
            return;
        }
        else
        {
            Node *Current = head;
            while (Current->Next->Next != NULL)
            {
                Current = Current->Next;
            }
            Node *Temp = Current->Next;
            Current->Next = NULL;
            delete Temp;
            _Index--;
            _Size--;
        }
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteAtFirst();
        }
    }

    void Reverse()
    {
        // Abo hadhoud Code
        //________________________________________________________________________//

        // Node *Current = head;
        // Node *temp = nullptr;
        // while (Current != NULL)
        // {
        //     temp = Current->Prev;
        //     Current->Prev = Current->Next;
        //     Current->Next = temp;

        //     Current = Current->Prev;
        // }

        // if (temp != NULL)
        //     head = temp->Prev;

        //________________________________________________________________________//

        Node *current = head;
        Node *newHead = nullptr; // سنحتفظ هنا بالرأس الجديد مباشرة
        while (current != nullptr)
        {
            // swap prev and next
            Node *tmp = current->Prev;
            current->Prev = current->Next;
            current->Next = tmp;

            // بعد التبديل، current هي عقدة معكوسة جزئياً؛
            // نحفظها كآخر عقدة معالجة — هي ستكون الرأس الجديد في النهاية
            newHead = current;

            // ننتقل إلى العقدة التالية في الترتيب الأصلي
            current = current->Prev;
        }
        if (newHead != nullptr)
            head = newHead;
    }

    Node *GetNode(int Index)
    {
        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node *Current = head;
        while (Counter != Index && Current != NULL && (Current->Next != NULL))
        {
            Current = Current->Next;
            Counter++;
        }

        return Current;
    }

    T GetItem(int Index)
    {
        Node *ItemNode = GetNode(Index);

        if (ItemNode == NULL)
        {
            return T(NULL);
        }
        else
        {
            T Item = ItemNode->Value;
            return Item;
        }
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node *ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }

        else
            return false;
    }

    bool InsertAfter(int Index, T NewValue)
    {
        if (Index > _Size - 1 || Index < 0)
            return false;

        Node *ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, NewValue);
            return true;
        }
        else
            return false;
    }
};