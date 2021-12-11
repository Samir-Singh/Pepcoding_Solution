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

node *addFirst()
{
    int data;
    cin>>data;
    node *head = NULL;
    
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL)
            head = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
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
int main()
{
    node *head = addFirst();
    printList(head);
}