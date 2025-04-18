#include "queue.h"
#include <cassert>

// const int QUEUE_SIZE = 100;
const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0), rear_(0)
{
    assert(pArr_);    
}

Queue::~Queue()
{
    delete [] pArr_;
}

bool Queue::empty() const
{
    return front_ == rear_;
}

bool Queue::full() const
{
    return rear_ == size_;
}

bool Queue::size() const
{
    return size_;
}

bool Queue::remain() const
{
    return size_ - rear_;
}

void Queue::push(int data)
{
    assert(!full());
    pArr_[rear_] = data;
    ++rear_;
}

int Queue::pop()
{
    assert(!empty());

    int index = front_;
    ++front_;
    return pArr_[1];
}