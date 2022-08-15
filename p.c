#include <stdio.h>
#include <stdlib.h>
#define max 100
#define n 10
void qinsert(int *q, int *front, int *rear, int x)
{
    if (*rear >= n - 1)
        printf("\n Queue Overflow");
    else
    {
        *rear = *rear + 1;
        q[*rear] = x;
        if (*front = -1)
            *front = 0;
    }
}
void qdelete(int *q, int *front, int *rear)
{
    if (*front == -1 || *front > *rear) // ei line e bhul chilo :)
        printf("\n Queue Underflow");
    else
    {
        printf("\n The deleted element is : %d", q[*front]);
        if (*front == *rear)
            *front = *rear = -1;
        *front = *front + 1;
    }
}
void display(int *q, int *front, int *rear)
{
    int i;
    for (i = *front; i <= *rear; i++)
    {
        printf("\t %d", q[i]);
    }
}
void main()
{
    int queue[max];
    int front = -1;
    int rear = -1;
    int ch;
    printf("\n QUEUE OPERATIONS");
    printf("\n 1.Queue Insert");
    printf("\n 2. Display");
    printf("\n 3.Queue Delete");
    printf("\n 4.EXIT");
    while (1)
    {
        printf("\n Choose your operation:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int x;
            printf("\n Enter the element to be inserted :");
            scanf(" %d", &x);
            qinsert(queue, &front, &rear, x);
            break;
        }
        case 2:
        {
            display(queue, &front, &rear);
            break;
        }
        case 3:
        {
            qdelete(queue, &front, &rear);
            break;
        }
        case 4:
            exit(0);
        default:
            printf("\n Invalid Choice");
        }
    }
}