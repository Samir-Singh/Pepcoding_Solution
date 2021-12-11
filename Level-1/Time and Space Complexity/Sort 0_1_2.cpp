#include<bits/stdc++.h>
using namespace std;
void segregate_array(vector<int> &arr)
{
    int i,j,k;
    k = arr.size()-1;
    i = j = 0;
    
    while(i <= k)
    {
        if(arr[i] == 1)
            i++;
        else if(arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            swap(arr[i], arr[k]);
            k--;
        }
    }
}
int main()
{
    vector<int> arr = {1,1,0,1,0,1,1,0,1,0,0,0,1,2,2};
    segregate_array(arr);
    for(auto it : arr)
        cout<<it<<" ";
}