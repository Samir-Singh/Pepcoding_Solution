#include<bits/stdc++.h>
using namespace std;
vector<int> merge_arrray(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans(arr1.size() + arr2.size());
    int i,j,k;
    i = j = k = 0;
    
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] <= arr2[j])
        {
            ans[k] = arr1[i];
            i++;
        }
        else
        {
            ans[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    while(i < arr1.size())
    {
        ans[k] = arr1[i];
        i++;
        k++;
    }
    
    while(j < arr2.size())
    {
        ans[k] = arr2[j];
        j++;
        k++;
    }
    
    return ans;
}
int main()
{
    vector<int> arr1 = {2,5,12,18,20};
    vector<int> arr2 = {7,9,11,15,25,28,30,35};
    vector<int> ans = merge_arrray(arr1, arr2);
    for(auto it : ans)
        cout<<it<<" ";
}