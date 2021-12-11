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

void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node *removeAt(node *head, int idx)
{
    if(head == NULL)
    {
        cout<<"Invalid Arguments"<<endl;
        return head;
    }
    if(idx == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node *p = head;
    node *q = head->next;
    int i = 0;
    
    while(i < idx-1)
    {
        p = p->next;
        q = q->next;
        if(q == NULL)
        {
            cout<<"Invalid Arguments"<<endl;
            return head;
        }
    }
    
    node *temp = q;
    p->next = q->next;
    delete temp;
    return head;
}
int main()
{
    int idx;
    node *head = takeInput();
    cin>>idx;
    head = removeAt(head, idx);
    printList(head);
}