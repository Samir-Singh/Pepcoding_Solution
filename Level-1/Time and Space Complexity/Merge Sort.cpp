#include<bits/stdc++.h>
using namespace std;
void merge_array(vector<int> &arr, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid+1;
    int k = lo;
    int brr[arr.size()];
    
    while(i <= mid && j <= hi)
    {
        if(arr[i] <= arr[j])
        {
            brr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= hi)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }
    
    for(int i=lo; i<=hi; i++)
        arr[i] = brr[i];
}
void merge_sort(vector<int> &arr, int lo, int hi)
{
    if(lo < hi)
    {
        int mid = (lo+hi)/2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid+1, hi);
        merge_array(arr, lo, mid, hi);
    }
}
int main()
{
    vector<int> arr = {12,45,13,57,3,56,46,67,23,53,78};
    merge_sort(arr, 0, arr.size()-1);
    for(auto it : arr)
        cout<<it<<" ";
}