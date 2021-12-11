#include<bits/stdc++.h>
using namespace std;
void prefixEvaluation(string str)
{
    stack<int> value;
    stack<string> infix;
    stack<string> postfix;
    
    for(int i=str.size()-1; i>=0; i--)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int val1 = value.top(); value.pop();
            int val2 = value.top(); value.pop();
            if(str[i] == '+') value.push(val1+val2);
            else if(str[i] == '-') value.push(val1-val2);
            else if(str[i] == '*') value.push(val1*val2);
            else value.push(val1/val2);
            
            string inval1 = infix.top(); infix.pop();
            string inval2 = infix.top(); infix.pop();
            string inval = "";
            inval += '(';
            inval += inval1;
            inval += str[i];
            inval += inval2;
            inval += ')';
            infix.push(inval);
            
            string postval1 = postfix.top(); postfix.pop();
            string postval2 = postfix.top(); postfix.pop();
            string postval = "";
            postval += postval1;
            postval += postval2;
            postval += str[i];
            postfix.push(postval);
        }
        else
        {
            string ans = "";
            ans += str[i];
            infix.push(ans);
            postfix.push(ans);
            value.push(str[i]-'0');
        }
    }
    
    cout<<value.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<postfix.top();
}
int main()
{
    string str = "-+2/*6483";
    prefixEvaluation(str);
}