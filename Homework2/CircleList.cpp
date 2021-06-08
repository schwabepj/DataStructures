#include <iostream>
#include "CircleList.h"
using namespace std;

template <typename Object>
CircleList<Object>::CircleList(){
 cursor = NULL;
}

template <typename Object>
CircleList<Object>::~CircleList() 
{ while(!empty()) remove(); }

template <typename Object>
bool CircleList<Object>::empty() const
{
return cursor == NULL;
}

template <typename Object>
const Object& CircleList<Object>::back() const
{
return cursor->elem;
}

template <typename Object>
const Object& CircleList<Object>::front() const
{
return cursor->next->elem;
}

template <typename Object>
void CircleList<Object>::advance() {
cursor = cursor->next;
}

template <typename Object>
void CircleList<Object>::Add(const Object& e) {
CNode* v = new CNode;
v->elem = e;
if (cursor == NULL) {
 v->next = v;
 cursor = v;
}
else {
 v->next = cursor->next;
 cursor->next = v;
}

}

template <typename Object>
void CircleList<Object>::remove() {
 CNode* old = cursor->next;
 if (old == cursor){
  cursor = NULL;
 }
 else{
  cursor->next = old->next;
 }
 delete old;
}

