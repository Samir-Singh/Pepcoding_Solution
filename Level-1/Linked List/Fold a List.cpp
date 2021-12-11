class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    }
    
    void reorderList(ListNode* head) 
    {
    ListNode *p = head;
    ListNode *q = head->next;
    
    while(q!=NULL && q->next!=NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    ListNode *temp = reverseList(p->next);
    p->next = NULL;
    p = head;
    q = temp;
    
    ListNode *dummy = new ListNode(-1);
    ListNode *t = dummy;
    int i=0;
    while(q != NULL)
    {
        if(i == 0)
        {
            t->next = p;
            p = p->next;
            i++;
        }
        else
        {
            t->next = q;
            q = q->next;
            i--;
        }
        t = t->next;
    }
    if(p!=NULL)
    {
        t->next = p;
        p->next = NULL;
    }
    head = dummy->next;
}
};