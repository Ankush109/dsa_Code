#include <stdio.h>
#include <stdlib.h>
/* ==DEFINITION OF SELF-REFERENTIAL STRUCTURE ==*/
typedef struct s_linked_list
{
    int data;
    struct s_linked_list *nxt;
} S_LINKED_LIST;
void initialisation(S_LINKED_LIST **aa_head)
{
    *aa_head = NULL;
}
void insertion_serial_order(S_LINKED_LIST **aa_head, int n)
{
    S_LINKED_LIST *t, *prv, *cur;
    t = (S_LINKED_LIST *)malloc(sizeof(S_LINKED_LIST));
    t->data = n;
    for (cur = *aa_head, prv = NULL; cur; cur = cur->nxt)
        prv = cur;
    t->nxt = cur;
    if (prv)
        prv->nxt = t;
    else
        *aa_head = t;
}
void display(S_LINKED_LIST *a_head)
{
    for (; a_head; a_head = a_head->nxt)
        printf("\t % d", a_head->data);
    printf("\n");
}
void deletion(S_LINKED_LIST **aa_head, int n)
{
    S_LINKED_LIST *prv, *cur;
    int found = 0;
    for (cur = *aa_head, prv = NULL; cur; cur = cur->nxt)
    {
        if (prv != NULL && n == cur->data)
        {
            found = 1;
            prv->nxt = cur->nxt;
            free(cur);
            return;
        }
        else if (prv == NULL && n == cur->data)
        {
            found = 1;
            *aa_head = cur->nxt;
            free(cur);
            return;
        }
        else
            prv = cur;
    }
    if (!found)
        printf("\n Data not found\n");
}
int main()
{
    S_LINKED_LIST *L1 = NULL;
    initialisation(&L1);
    printf("Insertion in serial order:");
    insertion_serial_order(&L1, 4);
    insertion_serial_order(&L1, 5);
    insertion_serial_order(&L1, 1);
    insertion_serial_order(&L1, 7);
    insertion_serial_order(&L1, 0);
    display(L1);
    printf("Deleting an Element:");
    deletion(&L1, 4);
    display(L1);
}