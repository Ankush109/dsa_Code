#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    //  linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    // linkedListTraversal(f);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    node *next;
} Node;
typedef struct Queue
{

    Node *front, *rear;
} Queue;
Node *newNode(int k)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    temp->data = k;

    temp->next = NULL;

    return temp;
}
Queue *createQueue()
{

    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->front = q->rear = NULL;

    return q;
}

void enQueue(Queue *q, int k)
{

    // Create a new LL node

    Node *temp = newNode(k);

    if (q->rear == NULL)
    {

        q->front = q->rear = temp;

        return;
    }
    q->rear->next = temp;

    q->rear = temp;
}
int deQueue(Queue *q)
{
    if (q->front == NULL)

        return;

    Node *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)

        q->rear = NULL;
    return temp->data;

    free(temp);
}
void main()
{
    Queue *q = createQueue();
    /*if (isEmptyQueue(q))
        printf("\n Empty Queue...");*/
/*  printf("\n 1. Enqueue");
  printf("\n 2. Dequeue");
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
          enQueue(q, n);

          break;

      case 2:
          printf("\n The popped element is: %d", deQueue(q));
          break; // break is optional
                 /* case 3:
                      display(&s);
                      break;*/
/*case 4:
exit(1);
break;
default:
break;
}
}
while (1)
    ;
}

    /*int main()
    {

        Queue *q = createQueue();

        enQueue(q, 10);

        enQueue(q, 20);

        deQueue(q);

        deQueue(q);

        enQueue(q, 30);

        enQueue(q, 40);

        enQueue(q, 50);

        deQueue(q);

        printf("Queue Front : %d \n", q->front->data);

        printf("Queue Rear : %d", q->rear->data);

        return 0;
    }*/