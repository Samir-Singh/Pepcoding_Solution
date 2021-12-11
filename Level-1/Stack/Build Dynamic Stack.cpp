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
            int *newArray = new int[2*s];
            for(int i=0; i<=tos; i++)
                newArray[i] = arr[i];
            arr = newArray;
            tos++;
            arr[tos] = data;
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