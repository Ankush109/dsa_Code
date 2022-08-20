#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int data[MAX];
    int top;
}stack;
void initialisation(stack *p)
{
    p->top=-1;
}
int is_empty(stack p)
{
    return (p.top==-1);
}
int is_full(stack p)
{
    return(p.top==MAX-1);
}
void push(stack*p,int n)
{
    if(p->top!=MAX-1)
        p->data[++(p->top)]=n;
    else{
        printf("\n Stack Over Flow");
    }
}
int pop(stack *p)
{
    if(p->top!=-1)
        return(p->data[(p->top)--]);
    else{
        printf("\n Empty Stack");
    exit(1);
    }
}
void main()
{
    stack s;
    initialisation(&s);
    push(&s,4);
    push(&s,7);
    push(&s,9);
    push(&s,14);
    push(&s,16);
    push(&s,18);
    push(&s,24);
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
}