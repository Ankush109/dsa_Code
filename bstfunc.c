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
void rec_insert(BS_TREE **aar, int n)
{
    if (*aar == NULL)
    {
        *aar = (BS_TREE *)malloc(sizeof(BS_TREE));
        (*aar)->data = n;
        (*aar)->left = (*aar)->right = NULL;
    }
    else if (n < (*aar)->data)
        rec_insert(&((*aar)->left), n);
    else
        rec_insert(&((*aar)->right), n);
}
int recursive_search(BS_TREE *ar, int n)
{
    if (ar != NULL)
    {
        if (ar->data == n)
        {
            printf("\n Data found...");
            return (1);
        }
        else if (n > ar->data)
            recursive_search(ar->right, n);
        else
            recursive_search(ar->left, n);
    }
    else
    {
        printf("\n Data not found..");
        return (0);
    }
}
void mirror_image(BS_TREE **aar)
{
    BS_TREE *t;
    if (*aar != NULL)
    {
        mirror_image(&(*aar)->left);
        mirror_image(&(*aar)->right);
        t = (*aar)->left;
        (*aar)->left = (*aar)->right;
        (*aar)->right = t;
    }
}
int total_nodes(BS_TREE *t)
{
    if (t == NULL)
        return 0;
    else
        return (total_nodes(t->left) + total_nodes(t->right) + 1);
}
int leaf_nodes(BS_TREE *t)
{
    if (t == NULL)
        return 0;
    else if (t->left == NULL && t->right == NULL)
        return 1;
    else
        return (leaf_nodes(t->left) + leaf_nodes(t->right));
}
int internal_nodes(BS_TREE *t)
{
    if ((t == NULL) || (t->left == NULL && t->right == NULL))
        return 0;
    else
        return (internal_nodes(t->left) + internal_nodes(t->right) + 1);
}
BS_TREE *find_smallest(BS_TREE *t)
{
    if ((t == NULL) || t->left == NULL)
        return t;
    else
        return find_smallest(t->left);
}
BS_TREE *find_largest(BS_TREE *t)
{
    if ((t == NULL) || t->right == NULL)
        return t;
    else
        return find_largest(t->right);
}
void remove_tree_memory(BS_TREE **aar)
{
    if (*aar != NULL)
    {
        remove_tree_memory(&(*aar)->left);
        remove_tree_memory(&(*aar)->right);
        free(*aar);
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
    printf("\nInorder:\n");
    inorder(B);
    printf("\nPostorder:\n");
    postorder(B);

    display(B, a);
}