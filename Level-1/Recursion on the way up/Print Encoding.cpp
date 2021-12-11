#include<bits/stdc++.h>
using namespace std;
vector<string> codes = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
void print_encoding(string str, string ans)
{
    if(str.size() == 0)
    {
        cout<<ans<<" ";
        return;
    }
    
    int first_num = stoi(str.substr(0,1));
    if(first_num == 0)
        return;
    string remaining_string1 = str.substr(1);
    print_encoding(remaining_string1, ans+codes[first_num]);
    
    if(str.size() >= 2)
    {
        int first_two_number = stoi(str.substr(0,2));
        if(first_two_number <= 26)
        {
            string remaining_string2 = str.substr(2);
            print_encoding(remaining_string2, ans+codes[first_two_number]);
        }
    }
}
int main()
{
    string str = "11106";
    print_encoding(str, "");
}