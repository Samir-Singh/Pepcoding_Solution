#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &vec)
{
    for(int i=0; i<vec.size()-1; i++)
    {
        int min = i;
        for(int j=i+1; j<vec.size(); j++)
        {
            if(vec[j] < vec[min])
                min = j;
        }
        swap(vec[i], vec[min]);
    }
}
int main()
{
    x
    selectionSort(vec);
    for(auto it : vec)
        cout<<it<<" ";
}