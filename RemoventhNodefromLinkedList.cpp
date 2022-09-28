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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy_head(0);
        dummy_head.next=head;
        ListNode*slow=&dummy_head;
        ListNode*fast=&dummy_head;
        
        for(int i=1;i<=n+1;i++) // n+1 is used for knowing the length of the list it is imp
        {
            fast=fast->next;
        }
        
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy_head.next;
    }
    
};