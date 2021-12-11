#include<bits/stdc++.h>
using namespace std;
int digitFrequency(int n, int k)
{
    int count = 0;
    while(n > 0)
    {
        int temp = n%10;
        if(temp == k)
            count++;
        n = n/10;
    }
    return count;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    /* CODE HERE BELOW */
    int n,k;
    cin>>n>>k;
    cout<<digitFrequency(n,k);
}