#include<iostream>
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

class queue
{
    node *head;
    node *tail;
    int count;
public:
    queue()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    
    void enqueue(int data)
    {
        node *newNode = new node(data);
        count++;
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
    }
    
    void dequeue()
    {
        if(head == NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    
    int front()
    {
        return head->data;
    }
    
    int size()
    {
        return count;
    }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
}