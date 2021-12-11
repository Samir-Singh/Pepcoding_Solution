#include<bits/stdc++.h>
using namespace std;
void next_greater_ele_right(vector<int> &arr)
{
    stack<int> st;
    int temp;
    st.push(arr[arr.size()-1]);
    arr[arr.size()-1] = -1;

    for(int i=arr.size()-2; i>=0; i--)
    {
        while(st.size() > 0 && st.top() <= arr[i])
            st.pop();
        if(st.size() == 0)
        {
            temp = arr[i];
            arr[i] = -1;
        }
        else
        {
            temp = arr[i];
            arr[i] = st.top();
        }
        st.push(temp);
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