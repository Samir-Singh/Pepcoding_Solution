#include<bits/stdc++.h>
using namespace std;
void evalandconversion(string str)
{
    stack<int> val;
    stack<string> infix;
    stack<string> prefix;
    
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int val2 = val.top(); val.pop();
            int val1 = val.top(); val.pop();
            
            if(str[i] == '+') val.push(val1+val2);
            else if(str[i] == '-') val.push(val1-val2);
            else if(str[i] == '*') val.push(val1*val2);
            else val.push(val1/val2);
            
            
            string infixval2 = infix.top(); infix.pop();
            string infixval1 = infix.top(); infix.pop();
            string infixans = "";
            infixans += '(';
            infixans += infixval1;
            infixans += str[i];
            infixans += infixval2;
            infixans += ')';
            infix.push(infixans);
            
            string preval2 = prefix.top(); prefix.pop();
            string preval1 = prefix.top(); prefix.pop();
            string preval = "";
            preval += str[i];
            preval += preval1;
            preval += preval2;
            prefix.push(preval);
        }
        else
        {
            string ans = "";
            ans += str[i];
            val.push(str[i]-'0');
            infix.push(ans);
            prefix.push(ans);
        }
    }
    
    cout<<val.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<prefix.top();
}
int main()
{
    string str = "264*8/+3-";
    evalandconversion(str);
}