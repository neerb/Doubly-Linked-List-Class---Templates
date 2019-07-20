#include "DoublyLinkedListClassTemplated.h"
#include <iostream>

template <class T>
DoublyLinkedListTemplated<T>::DoublyLinkedListTemplated()
{
    //Defaulted values if so desired
    /*
    head = new Node;
    head->val = 0;
    */
}

template <class T>
DoublyLinkedListTemplated<T>::DoublyLinkedListTemplated(T initialVal)
{
    head = new Node;
    head->val = initialVal;
}

template <class T>
void DoublyLinkedListTemplated<T>::append(T val)
{
    Node *next = head;

    if(head != nullptr)
    {
        while (next->right != nullptr)
            next = next->right;

        next->right = new Node;
        next->right->val = val;
        next->right->left = next;

        end = next->right;
    }
    else
    {
        head = new Node;
        head->val = val;

        end = head;
    }
}

template <class T>
void DoublyLinkedListTemplated<T>::push(T val)
{
    Node *newHead = new Node;
    newHead->val = val;
    newHead->right = head;
    head->left = newHead;
    head = newHead;
}

template <class T>
void DoublyLinkedListTemplated<T>::pop()
{
    //Prevents user from having an empty list
    if(head->right != nullptr)
    {
        Node *savedEnd = end;

        end = savedEnd->left;

        end->right = nullptr;

        delete savedEnd;
    }
}

template <class T>
int DoublyLinkedListTemplated<T>::deleteNode(int pos)
{
    int returnCode = 0;
    Node *next = head;

    if(pos != 0)
    {
        for (int i = 0; i < pos && next != nullptr; i++)
        {
            next = next->right;
        }

        try {
            if(next == end)
            {
                Node *savedEnd = end;

                end = savedEnd->left;

                end->right = nullptr;

                delete savedEnd;
            }
            else {

                next->left->right = next->right;

                next->right->left = next->left;

                delete next;
            }
        }
        catch (int) {
            returnCode = -1;
        }
    }
    else {
        Node *savedhead = head;

        head = head->right;

        head->left = nullptr;

        delete savedhead;
    }

    return returnCode;
}

//Linear search on linked list from left to right
template <class T>
int DoublyLinkedListTemplated<T>::searchNode(T searchVal)
{
    int searchPos = 0;
    Node *next = head;

    while(next != nullptr && next->val != searchVal)
    {
        next = next->right;
        searchPos++;
    }

    if(next == nullptr)
        searchPos = -1;

    return searchPos;
}

//Making use of bubble sort
template <class T>
void DoublyLinkedListTemplated<T>::sortList()
{
    bool sorted = false;
    Node *next;

    while(!sorted)
    {
        sorted = true;
        next = head;

        while(next->right != nullptr)
        {
            if(next->right->val < next->val)
            {
                int temp = next->val;
                next->val = next->right->val;
                next->right->val = temp;

                sorted = false;
            }

            next = next->right;
        }
    }
}

template <class T>
void DoublyLinkedListTemplated<T>::displayAllNodes()
{
    Node *next = head;

    while(next != nullptr)
    {
        std::cout << next->val;
        next = next->right;

        if(next != nullptr)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

template <class T>
void DoublyLinkedListTemplated<T>::reverseTraverseDisplay()
{
    Node *previous = end;

    while(previous != nullptr)
    {
        std::cout << previous->val;
        previous = previous->left;

        if(previous != nullptr)
            std::cout << ", ";
    }

    std::cout << std::endl;
}

template <class T>
DoublyLinkedListTemplated<T>::~DoublyLinkedListTemplated()
{
    Node *current = head;
    Node *next;

    while(current != NULL)
    {
        next = current->right;
        free(current);
        current = next;
    }

    head = NULL;
    end = NULL;
}