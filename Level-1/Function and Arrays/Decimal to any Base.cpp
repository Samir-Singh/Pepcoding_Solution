#include<bits/stdc++.h>
using namespace std;
int conversion(int n, int b)
{
    int p = 1;
    int ans = 0;
    while(n > 0)
    {
        int digit = n%b;
        ans += digit * p;
        p = p * 10;
        n = n/b;
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    /* CODE HERE BELOW */
    int n,b;
    cin>>n>>b;
    cout<<conversion(n,b);
}