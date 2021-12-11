#include<bits/stdc++.h>
using namespace std;
vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{
    if(sr == dr && sc == dc)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    
    vector<string> ans;
    
    // horizontal paths
    for(int i = 1; i<=dc-sc; i++)
    {
        vector<string> hpaths = get_maze_paths(sr, sc+i, dr, dc);
        for(auto it : hpaths)
            ans.push_back("h" + to_string(i) + it);
    }
    
    // vertical paths
    for(int i = 1; i<=dr-sr; i++)
    {
        vector<string> vpaths = get_maze_paths(sr+i, sc, dr, dc);
        for(auto it : vpaths)
            ans.push_back("v" + to_string(i) + it);
    }
    
    // diagonal paths
    for(int i = 1; i<=dc-sc && i<=dr-sr; i++)
    {
        vector<string> dpaths = get_maze_paths(sr+i, sc+i, dr, dc);
        for(auto it : dpaths)
            ans.push_back("d" + to_string(i) + it);
    }
    
    return ans;
}
int main()
{
    int dr,dc;
    dr = dc = 2;
    vector<string> ans = get_maze_paths(1,1,dr,dc);
    for(auto it : ans)
        cout<<it<<"  ";
}