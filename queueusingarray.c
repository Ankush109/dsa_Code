#include <stdio.h>
#define MAX_QUEUE_SIZE 10
typedef struct queue
{
    int elements[MAX_QUEUE_SIZE];
    int front, rear;
} QUEUE;
void initialiseQueue(QUEUE *);
int addQueue(int, QUEUE *);
int deleteQueue(int *, QUEUE *);
int isEmptyQueue(QUEUE);
int isOverflow(QUEUE);
void initialiseQueue(QUEUE *aq)
{
    aq->front = -1;
    aq->rear = -1;
}
int addQueue(int item, QUEUE *aq)
{
    if (aq->rear == MAX_QUEUE_SIZE - 1)
        return 0;
    else
    {
        aq->elements[++(aq->rear)] = item;
        return 1;
    }
}
int deleteQueue(int *data, QUEUE *aq)
{
    if (aq->front == aq->rear)
    {
        printf("\n Empty Queue...");
        aq->front = -1;
        aq->rear = -1;

        data = NULL;
        return 0;
    }
    *data = aq->elements[++(aq->front)];
    return 1;
}
int isEmptyQueue(QUEUE q)
{
    return (q.front == q.rear);
}
int isOverflow(QUEUE q)
{
    return (q.rear == MAX_QUEUE_SIZE - 1);
}
void main()
{
    QUEUE Q;
    int data;
    initialiseQueue(&Q);
    if (isEmptyQueue(Q))
        printf("\n Empty Queue...");

    addQueue(10, &Q);
    addQueue(11, &Q);
    addQueue(12, &Q);
    addQueue(13, &Q);
    addQueue(14, &Q);
    addQueue(15, &Q);
    addQueue(16, &Q);
    while (deleteQueue(&data, &Q) == 1)
        printf("\n Data  : %d", data);

    printf("\n Empty Queue...");
}