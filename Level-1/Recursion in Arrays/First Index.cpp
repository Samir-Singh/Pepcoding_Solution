#include<bits/stdc++.h>
using namespace std;
int firstInd(vector<int> arr, int idx, int x)
{
    if(idx == arr.size()-1)
    {
        if(arr[idx] == x)
            return idx;
        return -1;
    }
    
    if(arr[idx] == x)
        return idx;
        
    return firstInd(arr, idx+1, x);
}
int main()
{
    vector<int> arr = {2,3,6,9,8,3,2,6,2,4};
    cout<<firstInd(arr, 0, 2);
}