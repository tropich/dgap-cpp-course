
#pragma once

typedef int data;

class BasicQueue
{
public:

    // Add element to the end
    virtual void enqueue(data &) = 0;

    // Return first element
    virtual data dequeue() = 0;

    // Get total count of elements
    virtual unsigned getLength() = 0;

};

class ListQueue: public BasicQueue
{
public:
    ListQueue();

    /*
     * Fully implement class:
     * - declarations here
     * - definitions in queue.cpp
     * Could have infinite size
     */
};

class ArrayQueue: public BasicQueue
{
public:
    ArrayQueue(unsigned max_size = 64);

    /*
     * Fully implement class:
     * - declarations here
     * - definitions in queue.cpp
     * Only finite size implementation is required
     */
};

