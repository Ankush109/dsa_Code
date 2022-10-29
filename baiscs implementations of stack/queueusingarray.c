#include <stdio.h>
#define MAX_QUEUE_SIZE 10
typedef struct queue
{
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} QUEUE;
void initialiseQueue(QUEUE *);
int addQueue(int, QUEUE *);
// int deleteQueue(int *, QUEUE *);
int isEmptyQueue(QUEUE);
int isOverflow(QUEUE);
void initialiseQueue(QUEUE *q)
{
    q->front = -1;
    q->rear = -1;
}
int enqueue(QUEUE *q, int item)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 0;
    else
    {
        q->arr[++(q->rear)] = item;
        return 1;
    }
}
int dequeue(QUEUE *q)
{
    if (q->front == q->rear)
    {
        printf("\n Empty Queue...");
        q->front = -1;
        q->rear = -1;

        // data = NULL;
        return 0;
    }
    int data = q->arr[++(q->front)];
    return data;
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
    QUEUE q;
    int data;
    initialiseQueue(&q);
    if (isEmptyQueue(q))
        printf("\n Empty Queue...");
    printf("\n 1. enqueue");
    printf("\n 2. dequeue");
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
/* while (deleteQueue(&data, &Q) == 1)
      printf("\n Data  : %d", data);

  printf("\n Empty Queue...");
*/
