int getNthFromLast(Node *head, int n)
{
       Node *p = head;
       Node *q = head;
       int i=1;
       while(q != NULL && i<n)
       {
           q = q->next;
           i++;
       }
        
       if(q == NULL)
            return -1;
            
       while(q->next != NULL)
       {
           p = p->next;
           q = q->next;
       }
       
       return p->data;
}