#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Node Class Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {

        temp = temp->next;
        l++;
        /* code */
    }
    return l;
}
int intersection(node *&head, node *&head2)
{
    int l1 = length(head);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return 1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(-1);
    node *p3 = dummynode;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
}
void insertattail(node *&head1, int val)
{
    node *n = new node(val);
    if (head1 == NULL)
    {
        head1 = n;
        return;
    }
    node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    node *head1 = NULL;
    node *head2 = NULL;

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    for (int i = 0; i < 5; i++)
    {
        insertattail(head1, arr1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        insertattail(head2, arr2[i]);
    }
    // insertattail(head1, 5);
    // insertattail(head1, 5);
    // insertattail(head1, 5);
    // insertattail(head2, 4);
    // insertattail(head2, 9);
    // insertattail(head2, 3);
    // insertattail(head2, 1);
    // intersect(head1, head2, 3);
    // display(head1);
    // display(head2);
    // cout << intersection(head1, head2) << endl;
    // return 0;
    display(head1);
    display(head2);
    node *newhead = merge(head1, head2);
    display(newhead);
}