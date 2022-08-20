#include <stdio.h>
#define MAX_QUEUE_SIZE 10
typedef struct queue
{
    int elements[MAX_QUEUE_SIZE];
    int front, rear;
} CQUEUE;
void initialiseCQueue(CQUEUE *);
int addCQueue(int, CQUEUE *);
int deleteCQueue(int *, CQUEUE *);
int checkEmpty(CQUEUE);
int checkFull(CQUEUE);
void initialiseCQueue(CQUEUE *aq)
{
    aq->front = -1;
    aq->rear = -1;
}
int checkFull(CQUEUE q)
{
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == MAX_QUEUE_SIZE - 1))
        /*In both these cases the location of the front is
        exactly next to the location of the rear.*/
        return 1;
    else
        return 0;
}
int checkEmpty(CQUEUE q)
{
    if (q.front == -1)
        return 1;
    else
        return 0;
}
int addCQueue(int item, CQUEUE *aq)
{
    /*There is no space in Queue for the new Item.
    Item can not be added in the Queue.*/
    if (checkFull(*aq))
    {
        printf("\n Queue Overflow...");
        return 0; /* Unsuccessful Addition*/
    }
    /* Spaces are available in Queue for the new
    Item. */
    else
    {
        if (aq->front == -1) /*When the first item is
       inserted in the Queue. */
            aq->front = 0;
        aq->rear = (aq->rear + 1) % MAX_QUEUE_SIZE;
        aq->elements[aq->rear] = item;
        return 1; /* Successful Addition*/
    }
}
int deleteCQueue(int *data, CQUEUE *aq)
{
    /* Empty Queue*/
    if (checkEmpty(*aq))
    {
        printf("\n Empty Queue...");
        data = NULL;
        return 0; /* Empty Queue*/
    }
    /* Non-empty Queue*/
    else
    {
        *data = aq->elements[aq->front];
        if (aq->front == aq->rear)
            initialiseCQueue(aq);
        else
            aq->front = (aq->front + 1) % MAX_QUEUE_SIZE;
        return 1; /* Successful retrieval of data*/
    }
}
void main()
{
    CQUEUE cq;
    int data;
    initialiseCQueue(&cq);
    addCQueue(10, &cq);
    addCQueue(11, &cq);
    addCQueue(12, &cq);
    addCQueue(13, &cq);
    addCQueue(14, &cq);
    addCQueue(15, &cq);
    addCQueue(16, &cq);
    while (deleteCQueue(&data, &cq) == 1)
        printf("\n Data: %d", data);
    printf("\n Empty Queue...");
}