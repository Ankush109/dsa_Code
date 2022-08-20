#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct bs_tree
{
    int data;
    struct bs_tree *left, *right;
} BS_TREE;
int height(BS_TREE *t)
{
    if (t == NULL)
        return 0;
    else
        return (1 + max(height(t->left), height(t->right)));
}
void initialise_tree(BS_TREE **aar)
{
    *aar = NULL;
}

int max(int x, int y)
{
    return ((x > y) ? x : y);
}
void insertion_iterative(BS_TREE **aar, int n)
{
    BS_TREE *t, *par, *cur;
    t = (BS_TREE *)malloc(sizeof(BS_TREE));
    t->data = n;
    t->left = t->right = NULL;
    if (*aar == NULL)
        *aar = t;
    else
    {
        par = NULL;
        cur = *aar;
        while (cur != NULL)
        {
            par = cur;
            if (n < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (n < par->data)
            par->left = t;
        else
            par->right = t;
    }
}
void preorder(BS_TREE *ar)
{

    if (ar)
    {

        printf("%d\n", ar->data);
        preorder(ar->left);
        preorder(ar->right);
    }
}
void inorder(BS_TREE *ar)
{

    if (ar)
    {

        inorder(ar->left);
        printf("%d\n", ar->data);

        inorder(ar->right);
    }
}
void postorder(BS_TREE *ar)
{

    if (ar)
    {

        postorder(ar->left);

        postorder(ar->right);
        printf("%d\n", ar->data);
    }
}
void display(BS_TREE *t, int a)
{
    int i;
    if (!t)
        return;
    display(t->right, a + 1);
    for (i = 0; i < a; ++i)
    {
        printf(" ");
    }
    printf("%d\n", t->data);
    display(t->left, a + 1);
}
void main()
{
    int h;
    BS_TREE *B = NULL;
    initialise_tree(&B);
    int a;
    int i;
    printf("Enter no of elements to insert in binary tree ");
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        int data;
        printf("Enter data u want to insert in binary tree : ");
        scanf("%d", &data);
        insertion_iterative(&B, data);
    }

    h = height(B);
    printf("Height : %d\n", h);

    printf("Preorder:\n");
    preorder(B);
    printf("Inorder:\n");
    inorder(B);
    printf("Postorder: \n");
    postorder(B);

    display(B, a);
}