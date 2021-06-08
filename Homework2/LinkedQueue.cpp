#include "LinkedQueue.h"
#include <iostream>
using namespace std;

template <typename Object>
LinkedQueue<Object>::LinkedQueue(){
C();
n = 0;
}

template <typename Object>
int LinkedQueue<Object>::size() const {
return n;
}

template <typename Object>
bool LinkedQueue<Object>::empty() const {
return n == 0;
}

template <typename Object>
const Object& LinkedQueue<Object>::front() const  {
if (C.empty())
 throw;
return C.front();
}

template <typename Object>
void LinkedQueue<Object>::enqueue(const Object& e) {
C.add(e);
C.advance();
n++;
}

template <typename Object>
void LinkedQueue<Object>::dequeue() {
if (C.empty())
 throw;
C.remove();
n--;
}

template <typename Object>
void LinkedQueue<Object>::printQ() {

for (int i = 0; i < n; i++){
cout << C.front() << endl;
C.advance();
}

}
