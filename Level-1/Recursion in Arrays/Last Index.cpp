#include<bits/stdc++.h>
using namespace std;
int lastInd(vector<int> arr, int idx, int x)
{
    if(idx == arr.size()-1)
    {
        if(arr[idx] == x)
            return idx;
        return -1;
    }
    int temp = lastInd(arr, idx+1, x);
    
    if(temp == -1)
    {
        if(arr[idx] == x)
            return idx;
        return -1;
    }
    
    return temp;
}
int main()
{
    vector<int> arr = {2,3,6,9,8,3,2,3,6,4};
    cout<<lastInd(arr, 0, 3);
}