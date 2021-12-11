#include<bits/stdc++.h>
using namespace std;
vector<string> codes = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> getKeypadeCodes(string str)
{
    if(str.size() == 0)
    {
        vector<string> base_result;
        base_result.push_back("");
        return base_result;
    }
    int first_num = str.at(0)-'0';
    string rest_of_string = str.substr(1);
    
    vector<string> small_output = getKeypadeCodes(rest_of_string);
    vector<string> result;
    
    for(auto it : codes[first_num])
    {
        for(auto it2 : small_output)
            result.push_back(it + it2);
    }
    
    return result;
}
int main()
{
    string str = "2";
    vector<string> ans = getKeypadeCodes(str);
    for(auto it : ans)
        cout<<it<<" ";
}