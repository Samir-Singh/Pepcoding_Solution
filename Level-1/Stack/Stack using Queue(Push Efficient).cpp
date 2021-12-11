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
        mainQ.push(data);
        os++;
    }
    
    void pop()
    {
        if(os == 0)
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        while(mainQ.size() >= 2)
        {
            tempQ.push(mainQ.front());
            mainQ.pop();
        }
        mainQ.pop();
        while(!tempQ.empty())
        {
            mainQ.push(tempQ.front());
            tempQ.pop();
        }
        os--;
    }
    
    void top()
    {
        if(mainQ.empty())
        {
            cout<<"Stack is Empty !"<<endl;
            return;
        }
        while(mainQ.size() >= 2)
        {
            tempQ.push(mainQ.front());
            mainQ.pop();
        }
        int temp = mainQ.front();
        mainQ.pop();
        tempQ.push(temp);
        while(!tempQ.empty())
        {
            mainQ.push(tempQ.front());
            tempQ.pop();
        }
        cout<<temp<<endl;
    }
    
    void size()
    {
        cout<<mainQ.size()<<endl;
    }
};