#include<bits/stdc++.h>
using namespace std;
vector<string> get_subsequence(string str)
{
    if(str.size() == 0)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    char first_char = str.at(0);
    string rest_of_string = str.substr(1);
    vector<string> small_output = get_subsequence(rest_of_string);
    
    vector<string> myresult;
    for(auto it : small_output)
    {
        myresult.push_back("" + it);
        myresult.push_back(first_char + it);
    }
    
    return myresult;
}
int main()
{
    string str = "abc";
    vector<string> ans = get_subsequence(str);
    for(auto it : ans)
        cout<<it<<" ";
}