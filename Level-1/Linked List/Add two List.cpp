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

node *addList(node *head1, node *head2)
{
    node *t1 = head1;
    node *t2 = head2;
    node *head = NULL;
    int carry = 0;
    
    while(t1 || t2 || carry)
    {
        int sum = 0;
        if(t1)
        {
            sum += t1->data;
            t1 = t1->next;
        }
        if(t2)
        {
            sum += t2->data;
            t2 = t2->next;
        }
        if(carry)
        {
            sum += carry;
        }
        
        node *newNode = new node(sum%10);
        carry = sum/10;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    
    return head;
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
    node *head1 = takeInput();
    node *head2 = takeInput();
    node *head = addList(head1, head2);
    printList(head);
}