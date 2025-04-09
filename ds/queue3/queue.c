#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq)
{
	pq->front = pq->rear = 0;
}

void push(Queue *pq, int data)
{
	assert(pq->rear != QUEUESIZE);

	pq->array[pq->rear] = data;
	++pq->rear;
}

int pop(Queue *pq)
{
	assert(pq->front != pq->rear);

	int index = pq->front;
	++pq->front;
	
	return pq->array[index];
}

