#include<bits/stdc++.h>
using namespace std;
void print_subsequence(string str, string ans)
{
    if(str.size() == 0)
    {
        cout<<ans<<" ";
        return;
    }
    char first_char = str[0];
    string rest_of_string = str.substr(1);
    print_subsequence(rest_of_string, ans);
    print_subsequence(rest_of_string, ans+first_char);
}
int main()
{
    string str = "abc";
    print_subsequence(str, "");
}