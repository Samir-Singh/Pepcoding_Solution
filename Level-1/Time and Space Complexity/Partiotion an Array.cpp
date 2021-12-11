#include<bits/stdc++.h>
using namespace std;
void partition(vector<int> &arr, int pivot)
{
    int i,j;
    i = j = 0;
    
    while(i < arr.size())
    {
        if(arr[i] > pivot)
            i++;
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}
int main()
{
    vector<int> arr = {7,9,4,8,3,6,2,1};
    int pivot = 5;
    partition(arr, pivot);
    for(auto it : arr)
        cout<<it<<" ";
}