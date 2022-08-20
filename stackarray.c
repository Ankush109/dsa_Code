#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    int data[MAX];
    int top;
} stack;
void initialisation(stack *p)
{
    p->top = -1;
}
int is_empty(stack p)
{
    return (p.top == -1);
}
int is_full(stack p)
{
    return (p.top == MAX - 1);
}
void push(stack *p, int n)
{
    if (p->top != MAX - 1)
        p->data[++(p->top)] = n;
    else
    {
        printf("\n Stack Over Flow");
    }
}
int pop(stack *p)
{
    if (p->top != -1)
        return (p->data[(p->top)--]);
    else
    {
        printf("\n Empty Stack");
        exit(1);
    }
}
void display(stack *p)
{
    int i;
    if (is_empty(*p))
        printf("\n Empty Stack");
    else
    {
        printf("\n Stack Elements are: ");
        for (i = p->top; i >= 0; i--)
            printf("%d ", p->data[i]);
    }
}
void main()
{
    stack s;
    initialisation(&s);
    do
    {
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        int ch;
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n Enter the element to be pushed: ");
            int n;
            scanf("%d", &n);
            push(&s, n);

            break;

        case 2:
            printf("\n The popped element is: %d", pop(&s));
            break; // break is optional
        case 3:
            display(&s);
            break;
        case 4:
            exit(1);
            break;
        default:
            break;
        }
    } while (1);
}