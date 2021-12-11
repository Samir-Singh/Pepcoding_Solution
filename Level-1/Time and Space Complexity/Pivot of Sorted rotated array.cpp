#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int> arr)
{
    int lo,mid,hi;
    lo = 0, hi = arr.size()-1;
    
    while(lo < hi)
    {
        mid = (lo+hi)/2;
        if(arr[hi] < arr[mid])
            lo = mid+1;
        else
            hi = mid;
    }
    
    return arr[lo];
}
int main()
{
    vector<int> arr = {5,4,1,2,3};
    cout<<findPivot(arr);
}