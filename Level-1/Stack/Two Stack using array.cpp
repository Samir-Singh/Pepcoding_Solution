class myStack
{
    int *arr;
    int s;
    int os;
    int tos1;
    int tos2;
public:
    myStack(int size)
    {
        arr = new int[size];
        s = size;
        os = 0;
        tos1 = -1;
        tos2 = size;
    }
    
    void push1(int data)
    {
        if(os == s)
        {
            cout<<"Stack1 is Full !"<<endl;
            return;
        }
        tos1++;
        arr[tos1] = data;
        os++;
    }
    
    void push2(int data)
    {
        if(os == s)
        {
            cout<<"Stack is Full !"<<endl;
            return;
        }
        tos2--;
        arr[tos2] = data;
        os++;
    }
    
    void top1()
    {
        if(tos1 == -1)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        cout<<arr[tos1]<<endl;
    }
    
    void top2()
    {
        if(tos2 == s)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        cout<<arr[tos2]<<endl;
    }
    
    void pop1()
    {
        if(tos1 == -1)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        cout<<arr[tos1]<<endl;
        tos1--;
    }
    
    void pop2()
    {
        if(tos2 == s)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        cout<<arr[tos2]<<endl;
        tos2++;
    }
    
    void size1()
    {
        cout<<(tos1+1)<<endl;
    }
    
    void size2()
    {
        cout<<(s-tos2)<<endl;
    }
};