class myStack
{
    int *arr;
    int tos;
    int s;
public:
    myStack(int cap)
    {
        s = cap;
        arr = new int[cap];
        tos = -1;
    }
    
    void push(int data)
    {
        if(tos == s-1)
        {
            cout<<"Stack Overflow !"<<endl;
            return;
        }
        else
        {
            tos++;
            arr[tos] = data;
        }
    }
    
    void pop()
    {
        if(tos == -1)
        {
            cout<<"Stack Underflow !"<<endl;
            return;
        }
        else
            tos--;
    }
    
    int top()
    {
        if(tos == -1)
        {
            cout<<"Stack Underflow !"<<endl;
            return -1;
        }
        else
            return arr[tos];
    }
    
    int size()
    {
        return (tos+1);
    }
    
    void display()
    {
        if(tos == -1)
        {
            cout<<"Stack Underflow !"<<endl;
            return;
        }
        else
        {
            for(int i=tos; i>=0; i--)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};