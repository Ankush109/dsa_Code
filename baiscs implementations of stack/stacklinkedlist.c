#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} stack;

stack *top = NULL;

void linkedListTraversal(stack *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *top)
{
    stack *p = (stack *)malloc(sizeof(stack));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack **top, int x)
{
    if (isFull(*top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack *n = (stack *)malloc(sizeof(stack));
        n->data = x;
        n->next = *top;
        *top = n;
        // return top;
    }
}
/*stack *push(stack *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack *n = (stack *)malloc(sizeof(stack));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}*/

int pop(stack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        stack *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    push(&top, 78);
    push(&top, 7);
    push(&top, 8);
    push(&top, 9);

    // linkedListTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct ll
{
    int data;
    struct ll *nxt;
} stack;
void initialisation(stack **s)
{
    *s = NULL;
}
void push(stack **s, int n)
{
    stack *t;
    t = (stack *)malloc(sizeof(stack));
    t->data = n;
    t->nxt = *s;
    *s = t;
}
int pop(stack **s)
{
    int n;
    stack *t;
    if (*s != NULL)
    {
        t = *s;
        n = t->data;
        *s = t->nxt;
        free(t);
        return (n);
    }
    else
    {
        printf("\n Empty Stack");
        exit(1);
    }
}
int is_empty(stack *s)
{
    return (s == NULL);
}


void main()
{
    stack *s = NULL;
    initialisation(&s);
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
            printf("\n Enter the element to be pushed: ");
            int n;
            scanf("%d", &n);
            push(&s, n);

            break;

        case 2:
            printf("\n The popped element is: %d", pop(&s));
            break; // break is optional
                   /* case 3:
                        display(&s);
                        break;*/
/*  case 4:
      exit(1);
      break;
  default:
      break;
  }
} while (1);
}
*/
/*#include <bits/stdc++.h>
using namespace std;

class stack
{
public:
    int data;
    stack *next;

    stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    stack *head;
    int size;

    Stack(int size)
    {
        this->size = size;
        this->head = NULL;
    }

    void push(int data)
    {
        int cnt = 0;
        stack *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        if (cnt < size)
        {
            // insert at head
            stack *newstack = new stack(data);
            if (head == NULL)
            {
                head = newstack;
                return;
            }
            else
            {
                newstack->next = head;
                head = newstack;
            }
        }
        else
            cout << "Stack Overflow" << endl;
    }
    void peak()
    {
        if (head == NULL)
            cout << "stack is empty" << endl;
        else
        {
            cout << head->data << endl;
        }
    }

    void pop()
    {
        if (head == NULL)
            cout << "Stack underflow" << endl;
        else
        {
            stack *temp = head;
            cout << "poped element is: " << temp->data << endl;
            head = head->next;
            delete temp;
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};
*/