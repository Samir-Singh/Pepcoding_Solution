#include<bits/stdc++.h>
using namespace std;
void print_stair_paths(int n, string ans)
{
    if(n == 0)
    {
        cout<<ans<<" ";
        return;
    }
    if(n < 0)
        return;
        
    for(int i=1; i<=3; i++)
        print_stair_paths(n-i, ans+to_string(i));
}
int main()
{
    int n = 3;
    print_stair_paths(n, "");
}