#include "queue.h"
#include <cassert>

const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
: arr_(), front_(0), rear_(0)
{
    assert(arr_);    
}

Queue::~Queue()
{
    delete [] arr_;
}

bool Queue::empty() const
{
    return front_ == rear_;
}

bool Queue::full() const
{
    return rear_ == arr_.size;
}

bool Queue::size() const
{
    return arr_.size();
}

bool Queue::remain() const
{
    return arr_.size() - rear_;
}

void Queue::push(int data)
{
    assert(!full());
    arr_[rear_] = data;
    ++rear_;
}

int Queue::pop()
{
    assert(!empty());

    int index = front_;
    ++front_;
    return arr_[1];
}