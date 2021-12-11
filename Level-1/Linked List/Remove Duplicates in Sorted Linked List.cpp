class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *t = dummy;
        ListNode *p = head;
        
        while(p != NULL)
        {
            if(t->val != p->val)
            {
                t->next = p;
                t = t->next;
            }
            p = p->next;
        }
        t->next = NULL;
            
        return dummy->next;
    }
};