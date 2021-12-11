class myStack
{
    queue<int> mainQ;
    queue<int> tempQ;
    int s;
    int os;
public:
    myStack(int cap)
    {
        s = cap;
        os = 0;
    }
    
    void push(int data)
    {
        if(os == s)
        {
            cout<<"Stack is Full !"<<endl;
            return;
        }
        if(mainQ.empty())
            mainQ.push(data);
        else
        {
            while(!mainQ.empty())
            {
                tempQ.push(mainQ.front());
                mainQ.pop();
            }
            mainQ.push(data);
            while(!tempQ.empty())
            {
                mainQ.push(tempQ.front());
                tempQ.pop();
            }
        }
        os++;
    }
    
    void pop()
    {
        if(os == 0)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        mainQ.pop();
        os--;
    }
    
    void top()
    {
        if(os == 0)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        cout<<mainQ.front()<<endl;
    }
    
    void size()
    {
        cout<<os<<endl;
    }
};