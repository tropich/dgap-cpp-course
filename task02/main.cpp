#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    char c;
    std::cout << "Type of queue (a - array, l - list): ";
    std::cin >> c;

    BasicQueue *queue = NULL;
    if (c == 'a')
        queue = new ArrayQueue;
    else if (c == 'l')
        queue = new ListQueue;
    else {
        std::cout << "Bad type, exit" << std::endl;
        return 1;
    }

    int i = 0;
    data b = 6;
    for  (i < 23){
        queue->enqueue(b);
        i++;
    }
    queue->enqueue(2);
    cout << queue->dequeue() << endl;
    cout << queue->getLength() << endl;
    delete queue;
    return 0;
}

