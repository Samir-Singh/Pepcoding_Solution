#include<bits/stdc++.h>
using namespace std;
void print_permutation(string str, string ans)
{
    if(str.size() == 0)
    {
        cout<<ans<<" ";
        return ;
    }
    
    for(int i=0; i<str.size(); i++)
    {
        char picked_char = str[i];
        string remaining_string = str.substr(0,i) + str.substr(i+1);
        print_permutation(remaining_string, ans+picked_char);
    }
}
int main()
{
    string str = "abc";
    print_permutation(str, "");
}