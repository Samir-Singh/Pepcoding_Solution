#include<bits/stdc++.h>
using namespace std;
int maxArray(vector<int> arr, int idx)
{
    if(idx == arr.size()-1)
        return arr[idx];
    int max;
    int temp = maxArray(arr, idx+1);
    if(temp > arr[idx])
        max = temp;
    else
        max = arr[idx];
    return max;
}
int main()
{
    vector<int> arr = {15,30,40,4,11,9};
    cout<<maxArray(arr, 0);
}