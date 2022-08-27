class Solution
{
public:
    // 1->2->3->4->NULL (val = 3 )
    // 1->1->1>NULL

    // node *
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        if (head == NULL)
        {
            return head;
        }
        ListNode *res = head;
        while (res->next != NULL)
        {
            if (res->next->val == val)
            {
                res->next = res->next->next;
            }
            else
            {
                res = res->next;
            }
        }

        return head;
    }
};