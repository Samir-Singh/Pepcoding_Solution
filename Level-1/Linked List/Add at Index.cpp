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

node *addAt(node *head, int pos, int val)
{
    if(pos < 0)
    {
        cout<<"Invalid Arguments"<<endl;
        return head;
    }
    if(pos == 0)
    {
        node *newNode = new node(val);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        int i=1;
        node *temp = head;
        while(i < pos)
        {
            temp = temp->next;
            i++;
            if(temp == NULL)
            {
                cout<<"Invalid Arguments"<<endl;
                return head;
            }
        }
        
        node *newNode = new node(val);
        newNode->next = temp->next;
        temp->next = newNode;
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
    node *head = takeInput();
    head = addAt(head, 0, 34);
    head = addAt(head, -1, 34);
    head = addAt(head, 3, 54);
    printList(head);
}


















