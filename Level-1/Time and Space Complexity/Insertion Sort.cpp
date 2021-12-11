#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &vec)
{
    int i,j;
    for(i=1; i<=vec.size()-1; i++)
    {
        int temp = vec[i];
        for(j=i-1; j>=0; j--)
        {
            if(vec[j] > temp)
                vec[j+1] = vec[j];
            else
                break;
        }
        vec[j+1] = temp;
    }
}
int main()
{
    vector<int> vec = {5,9,8,2,1};
    insertionSort(vec);
    for(auto it : vec)
        cout<<it<<" ";
}