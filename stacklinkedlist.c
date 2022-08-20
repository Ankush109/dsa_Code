#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int data;
    struct linked_list* nxt;
}stack;
void initialisation(stack **aa_top)
{
    *aa_top=NULL;
}
void push(stack**aa_top, int n)
{
    stack *t;
    t=(stack *)malloc(sizeof(stack));
    t->data=n;
    t->nxt=*aa_top;
    *aa_top=t;
}
int pop(stack **aa_top)
{
    int n;
    stack *t;
        if(*aa_top!=NULL)
        {
            t=*aa_top;
            n=t->data;
            *aa_top=t->nxt;
            free(t);
            return(n);
        }
        else{
            printf("\n Empty Stack");
        exit(1);
        }
}
int is_empty(stack *aa_top)
{
    return(aa_top==NULL);
}
void main()
{
    stack *s=NULL;
    initialisation(&s);
    push(&s,2);
    push(&s,3);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    push(&s,8);
    push(&s,9);
    push(&s,10);
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
    printf("\n%d", pop(&s));
}
