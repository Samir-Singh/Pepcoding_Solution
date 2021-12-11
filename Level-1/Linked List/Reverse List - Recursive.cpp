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
    if(head == NULL || head->next == NULL)
        return head;
    node *p = reverseList(head->next);
    node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    
    return p;
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
    head = reverseList(head);
    printList(head);
}