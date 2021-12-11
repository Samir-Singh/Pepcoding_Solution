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
node *head = NULL;
node *tail = NULL;
node *takeInput()
{
    int data;
    cin>>data;
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
node *removeFirst(node *head)
{
    if(head == NULL)
        cout<<"Nothing to remove";
        
    else if(head->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
        head = head->next;
    
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
    cout<<endl;
}
int main()
{
    node *head = takeInput();
    head = removeFirst(head);
    head = removeFirst(head);
    printList(head);
}