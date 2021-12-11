#include<bits/stdc++.h>
using namespace std;
int power(int x, int n)
{
    if(n == 0)
        return 1;
    int so = power(x, n/2);
    int ans = so*so;
    if(n%2 != 0)
        ans = x*ans;
    return ans;
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<power(x,n);
}