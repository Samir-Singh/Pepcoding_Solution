#include<bits/stdc++.h>
using namespace std;
int Size;
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
        Size++;
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
    cout<<endl;
}

node *getNodeAt(node *head, int idx)
{
    node *temp = head;
    while(idx--)
        temp = temp->next;
    return temp;
}
void reverseList(node *head)
{
    int i = 0;
    int j = Size-1;
    
    while(i < j)
    {
        node *left = getNodeAt(head, i);
        node *right = getNodeAt(head, j);
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
        i++;
        j--;
    }
}

int main()
{
    node *head = takeInput();
    printList(head);
    reverseList(head);
    printList(head);
}