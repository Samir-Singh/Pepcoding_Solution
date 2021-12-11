class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        
        ListNode *p = l1; 
        ListNode *q = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *t = dummy;
        
        while(p && q)
        {
            if(p->val <= q->val)
            {
                t->next = p;
                p = p->next;
            }
            else
            {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        
        if(p)
            t->next = p;
        else
            t->next = q;
        
        return dummy->next;
    }
};