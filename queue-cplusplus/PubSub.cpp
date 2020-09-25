#include <iostream>
#include "PubSub.hpp"

using namespace std;

PubSub::PubSub()
{
    queueFront = 0;
    queueEnd= 0;
    counter = 0;
}

bool PubSub::isEmpty()
{
    return (counter == 0);
}

bool PubSub::isFull()
{
    return (counter == SIZE);
}

void PubSub::enqueue(std::string item)
{
    if (isFull())
    {
        cout << "Queue full, cannot add new item" << endl;
        return;
    }
    
    queue[queueEnd] = item;
    //increase the number of items in the queue by 1
    counter++;

    // Mod for circular array
    queueEnd = (queueEnd + 1)%SIZE;

}

// remove the next item from the queue
void PubSub::dequeue()
{
    // when the queue is empty
    if (isEmpty())
    {
        cout << "Queue empty, cannot dequeue an item" << endl;
        return;
    }
    
    // Mod for circular array 
    queueFront = (1 + queueFront)%SIZE;

    // decrease the number of items in the queue by 1
    counter--;
}

std::string PubSub::peek()
{
    if (isEmpty())
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
    return queue[queueFront];

}

int PubSub::queueSize()  //changed
{
    return counter;
}  