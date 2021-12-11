#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int pivot)
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
    
    return j-1;
}
void quick_sort(vector<int> &arr, int lo, int hi)
{
    if(lo < hi)
    {
        int p = partition(arr, arr[hi]);
        quick_sort(arr, lo, p-1);
        quick_sort(arr, p+1, hi);
    }
}
int main()
{
    vector<int> arr = {10,16,8,12,15,6,3,9,5,20};
    quick_sort(arr,0,arr.size()-1);
    for(auto it : arr)
        cout<<it<<" ";
}