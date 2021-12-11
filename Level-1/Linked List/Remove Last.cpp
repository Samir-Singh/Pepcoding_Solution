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

node *removeLast(node *head)
{
    if(head == NULL)
    {
        cout<<"list is empty"<<endl;
        return head;
    }
    
    if(head->next == NULL)
    {
        node *temp = head;
        head = NULL;
        delete temp;
        return head;
    }
    node *p = head;
    
    while(p->next->next != NULL)
        p = p->next;
    
    node *temp = p->next;
    p->next = NULL;
    delete temp;
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
    node *head = takeInput();
    head = removeLast(head);
    head = removeLast(head);
    head = removeLast(head);
    printList(head);
}