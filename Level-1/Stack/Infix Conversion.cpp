#include<bits/stdc++.h>
using namespace std;
int precedence(char a)
{
    if(a == '+' || a == '-') return 1;
    else return 2;
}
void infixConversion(string str)
{
    stack<string> prefix;
    stack<string> postfix;
    stack<char> optor;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
            optor.push(str[i]);

        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            string ans = "";
            ans += str[i];
            prefix.push(ans);
            postfix.push(ans);
        }

        else if(str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i] == '/')
        {
            while(!optor.empty() && optor.top() != '(' && precedence(optor.top()) >= precedence(str[i]))
            {
                char op = optor.top(); optor.pop();
                string preval2 = prefix.top(); prefix.pop();
                string preval1 = prefix.top(); prefix.pop();
                string preval = "";
                preval += op;
                preval += preval1;
                preval += preval2;
                prefix.push(preval);

                string postval2 = postfix.top(); postfix.pop();
                string postval1 = postfix.top(); postfix.pop();
                string postval = "";
                postval += postval1;
                postval += postval2;
                postval += op;
                postfix.push(postval);
            }
            optor.push(str[i]);
        }

        else if(str[i] == ')')
        {
            while(optor.top() != '(')
            {
                char op = optor.top(); optor.pop();
                string preval2 = prefix.top(); prefix.pop();
                string preval1 = prefix.top(); prefix.pop();
                string preval = "";
                preval += op;
                preval += preval1;
                preval += preval2;
                prefix.push(preval);

                string postval2 = postfix.top(); postfix.pop();
                string postval1 = postfix.top(); postfix.pop();
                string postval = "";
                postval += postval1;
                postval += postval2;
                postval += op;
                postfix.push(postval);
            }
            optor.pop();
        }
    }

    while(!optor.empty())
    {
        char op = optor.top(); optor.pop();
        string preval2 = prefix.top(); prefix.pop();
        string preval1 = prefix.top(); prefix.pop();
        string preval = "";
        preval += op;
        preval += preval1;
        preval += preval2;
        prefix.push(preval);

        string postval2 = postfix.top(); postfix.pop();
        string postval1 = postfix.top(); postfix.pop();
        string postval = "";
        postval += postval1;
        postval += postval2;
        postval += op;
        postfix.push(postval);
    }

    cout<<prefix.top()<<endl;
    cout<<postfix.top();
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    /* CODE HERE BELOW */
    string str = "a*(b-c)/d+e";
    infixConversion(str);
}