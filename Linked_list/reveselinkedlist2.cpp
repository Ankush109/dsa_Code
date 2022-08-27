/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode * prev1 =NULL;
        int index=0;
        ListNode * nodeatleftindex=head;
        while(curr){
            
            index++;
            if(index==left){
                nodeatleftindex=curr;
                while(index<=right)
                {
                    ListNode * nextptr =curr->next;
                    curr->next=prev1;
                    prev1=curr;
                    curr=nextptr;
                    index++;
                }
              if(prev==NULL){
                 head=prev1;
                  
              }
                else{
                      prev->next=prev1;
                }
                 nodeatleftindex->next=curr;
            }else{
                prev=curr;
                curr=curr->next;
                
            }
        }
        return head;
        
    }
}