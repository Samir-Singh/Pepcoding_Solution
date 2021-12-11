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

class stack
{
    node *head;
    int count;
public:
    stack()
    {
        head = NULL;
        count = 0;
    }
    
    void push(int data)
    {
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
        count++;
    }
    
    void pop()
    {
        if(head == NULL)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    
    void top()
    {
        if(head == NULL)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<head->data<<endl;
    }
    
    int size()
    {
        return count;
    }
};
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
    cout<<st.size();
}