#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUESIZE 100

class Queue
{
private:	//int array[QUEUESIZE];
	int *pArr;
	int size;
	int front;
	int rear;

public:	
	// void initQueue(Queue *pq, int size);
	Queue(int size);
	// void cleanupQueue(Queue *pq);
	~Queue();

	void push(int data);
	int pop();
};


#endif
