#ifndef QUEUE_H
#define QUEUE_H
// #define QUEUE_SIZE 100

// extern const int QUEUE_SIZE;

class Queue
{
private:
    static const int QUEUE_SIZE;

    int *pArr_;
    int size_;
    int front_;
    int rear_;

    Queue(const Queue& );
    Queue& operator=(const Queue& );

public:
    // Queue();
    explicit Queue(int size = QUEUE_SIZE);
    ~Queue();

    bool empty() const;
    bool full() const;
    bool size() const;
    bool remain() const;

    void push(int data);
    int pop();

    // int size
};

#endif