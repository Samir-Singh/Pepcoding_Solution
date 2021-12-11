#include<bits/stdc++.h>
using namespace std;
void flood_fill(vector<vector<int>> &vec, int sr, int sc, string ans)
{
    if(sr == vec.size()-1 && sc == vec[0].size()-1)
    {
        cout<<ans<<" ";
        return;
    }
    if(sr < 0 || sc < 0 || sr == vec.size() || sc == vec[0].size() || vec[sr][sc] == -1 || vec[sr][sc] == 1)
        return;
        
    vec[sr][sc] = 1;
    flood_fill(vec, sr-1, sc, ans+"T");
    flood_fill(vec, sr, sc-1, ans+"L");
    flood_fill(vec, sr+1, sc, ans+"D");
    flood_fill(vec, sr, sc+1, ans+"R");
    vec[sr][sc] = 0;
}
int main()
{
    vector<vector<int>> vec{
        {0,-1,0,0,0,0,0},
        {0,-1,0,-1,-1,-1,0},
        {0,0,0,0,0,0,0},
        {-1,0,-1,-1,0,-1,-1},
        {-1,0,-1,-1,0,-1,-1},
        {-1,0,0,0,0,0,0}
    };
    
    flood_fill(vec, 0, 0, "");
}