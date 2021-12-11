#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> arr, int idx)
{
    if(idx == arr.size())
        return;
    cout<<arr[idx]<<" ";
    displayArray(arr, idx+1);
}
int main()
{
    vector<int> arr = {10,20,30,40,50};
    displayArray(arr,0);
}