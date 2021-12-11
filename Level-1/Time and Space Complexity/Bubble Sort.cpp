#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &vec)
{
    for(int i=1; i<=vec.size()-1; i++)
    {
        for(int j=0; j<vec.size()-i; j++)
        {
            if(vec[j] > vec[j+1])
                swap(vec[j],vec[j+1]);
        }
    }
}
int main()
{
    vector<int> vec = {5,9,8,2,1};
    bubbleSort(vec);
    for(auto it : vec)
        cout<<it<<" ";
}