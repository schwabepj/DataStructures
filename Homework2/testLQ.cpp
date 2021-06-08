#include "LinkedQueue.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedQueue<int> A;
    A.enqueue(7); A.printQ();
    A.enqueue(5); A.printQ();
    A.enqueue(3); A.printQ();
    A.enqueue(1); A.printQ();
    A.dequeue(); A.printQ();
    A.dequeue(); A.printQ();

    LinkedQueue<string> B;
    B.enqueue("John"); B.printQ();
    B.enqueue("Ricardo"); B.printQ();
    B.enqueue("Eric"); B.printQ();
    B.dequeue(); B.printQ();
    B.enqueue("Claire"); B.printQ();
    B.dequeue(); B.printQ();

    return 0;
}
