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

node *kReverse(node *head, int k)
{
    node *p = head;
    for(int i=1; i<=k; i++)
    {
        if(p == NULL)
            return head;
        p = p->next;
    }
    
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    
    while(curr != p)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head->next = kReverse(p, k);
    return prev;
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
    head = kReverse(head, 3);
    printList(head);
}