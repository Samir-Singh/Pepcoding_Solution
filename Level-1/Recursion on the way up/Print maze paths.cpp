#include<bits/stdc++.h>
using namespace std;
void print_maze_paths(int sr, int sc, int dr, int dc, string ans)
{
    if(sr == dr && sc == dc)
    {
        cout<<ans<<" ";
        return;
    }
    
    if(sr > dr || sc > dc)
        return;
    
    print_maze_paths(sr, sc+1, dr, dc, ans+"h");
    print_maze_paths(sr+1, sc, dr, dc, ans+"v");
}
int main()
{
    int dr,dc;
    dr = dc = 2;
    print_maze_paths(1,1,dr,dc,"");
}