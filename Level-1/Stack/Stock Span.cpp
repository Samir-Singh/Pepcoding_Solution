#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> arr)
{
    stack<int> st;
    vector<int> newarr(arr.size());
    newarr[0] = 1;
    st.push(0);
    
    for(int i=1; i<=arr.size()-1; i++)
    {
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
            
        if(!st.empty())
            newarr[i] = i-st.top();
        else
            newarr[i] = i+1;
        
        st.push(i);
    }
    
    return newarr;
}
int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    arr = stockSpan(arr);
    for(auto it : arr)
        cout<<it<<" ";
}