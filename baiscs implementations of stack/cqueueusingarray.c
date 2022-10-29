#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct queue
{
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} CQUEUE;
void initialiseCQueue(CQUEUE *);
int addCQueue(int, CQUEUE *);
int deleteCQueue(int *, CQUEUE *);
int checkEmpty(CQUEUE);
int checkFull(CQUEUE);
void initialiseCQueue(CQUEUE *q)
{
    q->front = -1;
    q->rear = -1;
}
int checkFull(CQUEUE q)
{
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == MAX_QUEUE_SIZE - 1))

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
int enqueue(CQUEUE *q, int item)
{

    if (checkFull(*q))
    {
        printf("\n Queue Overflow...");
        return 0;
    }

    else
    {
        if (q->front == -1) /*When the first item is
       inserted in the Queue. */
            q->front = 0;
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->arr[q->rear] = item;
        return 1; /* Successful Addition*/
    }
}
int dequeue(CQUEUE *q)
{
    /* Empty Queue*/
    if (checkEmpty(*q))
    {
        printf("\n Empty Queue...");
        // data = NULL;
        return 0; /* Empty Queue*/
    }
    /* Non-empty Queue*/
    else
    {
        int data = q->arr[q->front];
        if (q->front == q->rear)
            initialiseCQueue(q);
        else
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return data;
    }
}
void main()
{
    CQUEUE q;
    int data;
    initialiseCQueue(&q);
    if (checkEmpty(q))
        printf("\n Empty Queue...");
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Display");
    printf("\n 4. Exit");

    do
    {

        printf("\n Enter your choice: ");
        int ch;
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n Enter the element to be enqueue: ");
            int n;
            scanf("%d", &n);
            enqueue(&q, n);

            break;

        case 2:
            printf("\n The popped element is: %d", dequeue(&q));
            break; // break is optional
                   /* case 3:
                        display(&s);
                        break;*/
        case 4:
            exit(1);
            break;
        default:
            break;
        }
    } while (1);
}
/*while (deleteCQueue(&data, &cq) == 1)
    printf("\n Data: %d", data);
printf("\n Empty Queue...");*/