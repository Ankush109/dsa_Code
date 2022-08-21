#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *new = malloc(sizeof(struct node));
    new->coeff = co;
    new->expo = ex;
    new->next = NULL;
    if (head == NULL || ex > head->expo)
    {
        new->next = head;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= ex)
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}
struct node *create(struct node *head)
{
    int n, i;
    float coeff;
    int expo;
    printf("\n Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("\n Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
        printf("\n No Polynomial.");
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
void polyadd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("\n The resultant polynomial is: ");
    display(head3);
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("\n Enter first polynomial: ");
    head1 = create(head1);
    printf("\n Enter second polynomial: ");
    head2 = create(head2);
    polyadd(head1, head2);
    return 0;
}