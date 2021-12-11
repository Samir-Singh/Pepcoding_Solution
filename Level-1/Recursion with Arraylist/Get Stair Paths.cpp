#include<bits/stdc++.h>
using namespace std;
vector<string> get_stairs_path(int stairs)
{
    if(stairs == 0)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    vector<string> paths1,paths2,paths3;
    
    if(stairs > 0)
    {
        paths1 = get_stairs_path(stairs-1);
        paths2 = get_stairs_path(stairs-2);
        paths3 = get_stairs_path(stairs-3);
    }
    
    vector<string> ans;
    for(auto it : paths1)
        ans.push_back("1" + it);
    for(auto it : paths2)
        ans.push_back("2" + it);
    for(auto it : paths3)
        ans.push_back("3" + it);
        
    return ans;
}
int main()
{
    int stairs = 3;
    vector<string> ans = get_stairs_path(stairs);
    for(auto it : ans)
        cout<<it<<" ";
}