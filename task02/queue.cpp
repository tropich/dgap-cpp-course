#include "queue.h"
#include <iostream>

ListQueue::ListQueue(){
    first = nullptr;
	last = nullptr;
}


void ListQueue::enqueue(data &data){
    n = new Node;
	if (last){
		last->next = n;
		last = last->next;
        last->Data = data;
	}
	else{
        last = n;
        last = last->next;
        last->Data = data;
	}
}

data ListQueue::dequeue()
{
	if (first = nullptr)
		return 0;
	else{
        data n = first->Data;
	return n;
}

unsigned ListQueue::getLength()
{
	if (first == nullptr)
	       return 0;
	Node* l = first;
	int size = 1;
	while (l){
		l = l->next;
		size++;
	}
	return size;
}

void ListQueue::dellist(Node *l){
		for (l->next != 0){
			dellist(l->next);
            delete l;
		}
	}

ArrayQueue::ArrayQueue(unsigned maxlen){
    data *x = data new array[maxlen];
    int i = 0;
    for (i < 64){
        arrey[i] = 0;
        i++;
    }
    first = 0;
    last = 0;
}

void ArrayQueue::enqueue(data &data){
    if ((last - first) = 64){
        return 0;
    }
    else
	array[last+1] = data;
}

data ArrayQueue::dequeue(){
	data n = array[first];
	return n;
}

unsigned ArrayQueue::getLength(){
	size = first - last;
	return size;
}

ArrayQueue::~ArrayQueue(){
	delete[] array;
}
