class minStack
{
    stack<int> os;
    int m;
public:
    void push(int data)
    {
        if(os.empty())
        {
            os.push(data);
            m = data;
        }
        else if(data < m)
        {
            os.push(2*data - m);
            m = data;
        }
        else
            os.push(data);
    }
    void pop()
    {
        if(os.top() < m)
            m = 2*m - os.top();
        os.pop();
    }
    
    void top()
    {
        if(os.top() < m)
            cout<<m<<endl;
        else
            cout<<os.top()<<endl;
    }
    
    void size()
    {
        cout<<os.size()<<endl;
    }
    
    void min()
    {
        cout<<m<<endl;
    }
};