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

node *oddEvenList(node *head)
{
    node *evenNode = new node(-1);
    node *oddNode = new node(-1);
    node *t1 = evenNode;
    node *t2 = oddNode;
    node *p = head;
    
    while(p != NULL)
    {
        if(p->data%2 == 0)
        {
            t1->next = p;
            t1 = t1->next;
        }
        else
        {
            t2->next = p;
            t2 = t2->next;
        }
        p = p->next;
    }
    
    if(t1->data == -1)
        return oddNode->next;
    if(t2->data == -1)
        return evenNode->next;
        
    t2->next = evenNode->next;
    t1->next = NULL;
    return oddNode->next;
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
    head = oddEvenList(head);
    printList(head);
}