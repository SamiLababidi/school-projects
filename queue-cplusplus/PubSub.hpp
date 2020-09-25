/****************************************************************/
/*                    PubSub Class                              */
/****************************************************************/
/*           CLASS FILE DO NOT MODIFY ANYTHING!                 */
/****************************************************************/
#pragma once

#include <string>

const int SIZE = 20;

class PubSub
{
private:
  int queueFront; //the index in queue[] that will be dequeued next
  int queueEnd; //the index in queue[] that was most recently enqueued
  int counter; //number of items in the queue
  std::string queue[SIZE];

public:
  PubSub();
  bool isEmpty();
  bool isFull();
  void enqueue(std::string item);
  void dequeue();
  std::string peek();
  int queueSize();   //changed
  int getQueueFront() { return queueFront; }
  int getQueueEnd() { return queueEnd; }
  std::string* getQueue() { return queue; }

};
