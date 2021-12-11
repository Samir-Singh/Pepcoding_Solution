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

int getFirst(node *head)
{
    if(head == NULL)
        return -1;
    return head->data;
}

int getLast(node *head)
{
    if(head == NULL)
        return -1;
        
    node *temp = head;
    while(temp->next)
        temp = temp->next;
        
    return temp->data;
}

int getAt(node *head, int ind)
{
    if(head == NULL)
        return -1;
    node *temp = head;
    while(ind--)
    {
        temp = temp->next;
        if(temp == NULL)
            return -1;
    }
    
    return temp->data;
}

int main()
{
    node *head = takeInput();
    cout<<getFirst(head)<<endl;
    cout<<getLast(head)<<endl;
    cout<<getAt(head, 4)<<endl;
}