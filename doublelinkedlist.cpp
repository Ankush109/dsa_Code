#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *kappend(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count = l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
void inserathead(node *&head, int val)

{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        inserathead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
}
void deletion(node *&head, int pos)
{

    if (pos == 1)
    {
        deleteathead(head);
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main()
{

    // node *head = NULL;
    // insertattail(head, 2);
    // insertattail(head, 3);
    // insertattail(head, 4);
    // insertattail(head, 5);
    // insertattail(head, 6);
    // insertattail(head, 7);
    // insertattail(head, 8);
    // // display(head);
    // // inserathead(head, 6);
    // // deletion(head, 4);
    // // display(head);
    // deleteathead(head);
    // display(head);
    // return 0;

    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 6; i++)
    {
        insertattail(head, arr[i]);
    }
    display(head);
    node *newehead = kappend(head, 3);
    display(head);
}