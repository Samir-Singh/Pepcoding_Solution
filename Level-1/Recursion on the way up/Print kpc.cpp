#include<bits/stdc++.h>
using namespace std;
vector<string> codes = {";.", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
void print_keypad(string ques, string ans)
{
    if(ques.size() == 0)
    {
        cout<<ans<<" ";
        return;
    }
    
    int first_num = ques[0]-'0';
    string remaining_string = ques.substr(1);
    
    for(auto it : codes[first_num])
        print_keypad(remaining_string, ans+it);
}
int main()
{
    string str = "78";
    print_keypad(str, "");
}