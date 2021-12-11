class Solution {
public:
    ListNode *mergeList(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *t = dummy;
        ListNode *p = head1;
        ListNode *q = head2;
        
        while(p && q)
        {
            if(p->val < q->val)
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
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *p = head;
        ListNode *q = head->next;
        
        while(q && q->next)
        {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;
        
        return mergeList(sortList(head), sortList(q));
    }
};