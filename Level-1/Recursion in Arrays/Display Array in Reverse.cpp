#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> arr, int idx)
{
    if(idx == arr.size())
        return;
    displayArray(arr, idx+1);
    cout<<arr[idx]<<" ";
}
int main()
{
    vector<int> arr = {10,20,30,40,50};
    displayArray(arr,0);
}