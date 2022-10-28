#include <stdio.h>
#include <stdlib.h>
#define bool int
typedef struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
} TNode;
void initialise_tree(TNode **aar)
{
    *aar = NULL;
}
struct sNode
{
    TNode *t;
    struct sNode *next;
};
void push(struct sNode **top_ref, TNode *t);
TNode *pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);
void inorder(TNode *root)
{
    TNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}
void preorder(TNode *root)
{
    TNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            printf("%d ", current->data);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}
void push(struct sNode **top_ref, TNode *t)
{
    struct sNode *new_TNode = (struct sNode *)malloc(sizeof(struct sNode));
    if (new_TNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
        -
    }
    new_TNode->t = t;
    new_TNode->next = (*top_ref);
    (*top_ref) = new_TNode;
}
bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}
TNode *pop(struct sNode **top_ref)
{
    TNode *res;
    struct sNode *top;
    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
void rec_insert(TNode **aar, int n)
{
    if (*aar == NULL)
    {
        *aar = (TNode *)malloc(sizeof(TNode));
        (*aar)->data = n;
        (*aar)->left = (*aar)->right = NULL;
    }
    else if (n < (*aar)->data)
    {
        rec_insert(&((*aar)->left), n);
    }
    else
    {
        rec_insert(&((*aar)->right), n);
    }
}
TNode *deleteIterative(TNode *root, int data)
{
    TNode *curr = root;
    TNode *prev = NULL;
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr == NULL)
    {
        return root;
    }
    if (curr->left == NULL || curr->right == NULL)
    {
        TNode *newCurr;
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
        if (prev == NULL)
            return newCurr;
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
        free(curr);
    }
    else
    {
        TNode *p = NULL;
        TNode *temp;
        temp = curr->right;
