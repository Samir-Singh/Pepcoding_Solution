class myQueue
{
    int *arr;
    int f;
    int r;
    int s;
    int os;
public:
    myQueue(int size)
    {
        arr = new int[size];
        s = size;
        f = -1;
        r = -1;
        os = 0;
    }
    
    void push(int data)
    {
        if(os == s)
        {
            int *newArr = new int[2*s];
            int j = 0;
            for(int i=f; i<os; i++)
            {
                newArr[j] = arr[i];
                j++;
            }
            for(int i=0; i<=r; i++)
            {
                newArr[j] = arr[i];
                j++;
            }
            delete [] arr;
            arr = newArr;
            f = 0;
            s = 2*s;
        }
        r = (r+1)%s;
        arr[r] = data;
        os++;
        if(f == -1)
            f = 0;
    }
    
    void pop()
    {
        if(os == 0)
            cout<<"Queue Underflow !"<<endl;
        else
        {
            f = (f+1)%s;
            os--;
        }
    }
    
    void front()
    {
        if(os == 0)
        {
            cout<<"Queue Underflow !"<<endl;
            return;
        }
        cout<<arr[f]<<endl;
    }
    
    void size()
    {
        cout<<os<<endl;
    }
    
    void display()
    {
        if(os == 0)
            cout<<"Queue Underflow !"<<endl;
        else
        {
            int i = f;
            while(i != r)
            {
                cout<<arr[i]<<" ";
                i = (i+1)%s;
            }
            cout<<arr[r];
        }
        cout<<endl;
    }
};