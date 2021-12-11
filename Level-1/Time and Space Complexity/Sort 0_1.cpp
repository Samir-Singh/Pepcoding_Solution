#include<bits/stdc++.h>
using namespace std;
void segregate_array(vector<int> &arr)
{
    int i,j;
    i = j = 0;
    
    while(i < arr.size())
    {
        if(arr[i] == 1)
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
    vector<int> arr = {1,1,0,1,0,1,1,0,1,0,0,0,1};
    segregate_array(arr);
    for(auto it : arr)
        cout<<it<<" ";
}