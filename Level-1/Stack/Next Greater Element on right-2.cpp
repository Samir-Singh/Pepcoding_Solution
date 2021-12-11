#include<bits/stdc++.h>
using namespace std;
void next_greater_ele_right(vector<int> &arr)
{
    stack<int> st;
    st.push(0);
    for(int i=1; i<arr.size(); i++)
    {
        while(!st.empty() && arr[st.top()] <= arr[i])
        {
            arr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        arr[st.top()] = -1;
        st.pop();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    /* CODE HERE BELOW */
    vector<int> arr = {2,5,9,3,1,12,6,8,7};
    next_greater_ele_right(arr);
    for(auto it : arr)
        cout<<it<<" ";
}