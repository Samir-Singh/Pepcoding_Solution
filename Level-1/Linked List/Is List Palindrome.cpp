#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeInput()
{
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    
    return head;
}

node *reverseList(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int isPalindrome(node *head)
{
    node *p = head;
    node *q = head->next;
    while(q!=NULL && q->next!=NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    node *temp = reverseList(p->next);
    p = head;
    q = temp;
    
    while(q!=NULL)
    {
        if(p->data != q->data)
            return 0;
        p = p->next;
        q = q->next;
    }
    
    return 1;
}
void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    node *head = takeInput();
    cout<<isPalindrome(head);
}