#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "CircleList.h"

template <typename Object>
class LinkedQueue {

public:

LinkedQueue();
int size() const;
bool empty() const;
const Object& front() const;
void enqueue(const Object& e);
void dequeue();
void printQ();

private:

CircleList<Object> C;
int n;

};

#endif

