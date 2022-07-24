#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val) // constructor
    {
        data = val;
        next = NULL;
    }
};
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
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
void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void insertathead(node *&head, int val)
{

    node *n = new node(val);
    n->next = head;
    head = n;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
node *reverse(node *&head)
{
    node *prevpter = NULL;
    node *currentptr = head;
    node *nextptr;
    while (currentptr != NULL)
    {
        nextptr = currentptr->next;  // 1 -> 2
        currentptr->next = prevpter; // prev=1 cur=2
        prevpter = currentptr;
        currentptr = nextptr;
    }
    return prevpter;
}
node *reverserecursion(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverserecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}
node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {

        head->next = reversek(nextptr, k);
    }
    return prevptr;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);
    insertattail(head, 9);
    display(head);
    insertathead(head, 69);
    display(head);
    cout << search(head, 5);
    deleteathead(head);
    display(head);
    // node *newhead = reverserecursion(head);
    // display(newhead);
    int k = 2;
    node *newhead = reversek(head, k);
    display(newhead);
    return 0;
}
