#include<bits/stdc++.h>
using namespace std;
int conversion(int n, int b)
{
    int ans = 0;
    int p = 1;
    while(n > 0)
    {
        int digit = n%10;
        digit = digit * p;
        p = p*b;
        ans = ans + digit;
        n = n/10;
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