#include<bits/stdc++.h>
using namespace std;
vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{
    if((sr == dr) && (sc == dc))
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    
    vector<string> rightpaths, downpaths;
    
    if(sc < dc)
        rightpaths = get_maze_paths(sr, sc+1, dr, dc);
    if(sr < dr)
        downpaths = get_maze_paths(sr+1, sc, dr, dc);
    
    vector<string> paths;
    for(auto it : rightpaths)
        paths.push_back("R" + it);
    for(auto it2 : downpaths)
        paths.push_back("D" + it2);
        
    return paths;
}
int main()
{
    int dr,dc;
    dr = dc = 3;
    vector<string> ans = get_maze_paths(1,1,dr,dc);
    for(auto it : ans)
        cout<<it<<" ";
}