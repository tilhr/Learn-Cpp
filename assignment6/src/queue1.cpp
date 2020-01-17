/*
 * queue1.cpp
 *
 *  Created on: Dec 31, 2019
 *      Author: tylerrodgers
 */



#include "queue1.h"

template<class ItemType>
QueType<ItemType>::QueType(int max)
// Paramaterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    size = 0;
    items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::QueType()              // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically allocated.

{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    size = 0;
    items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::~QueType()                     // Class destructor
{
    delete [] items;
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state
//       and size has been set to zero.
{
    front = maxQue - 1;
    rear = maxQue - 1;
    size = 0;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is at the rear of the queue.
{
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
    size++;
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
// Post: The front of the queue has been removed and a copy returned in item.
{
    front = (front + 1) % maxQue;
    item = items[front];
    size--;
}

template<class ItemType>
int QueType<ItemType>::QueSize() const
{
        return size;
}
