#include<bits/stdc++.h>
using namespace std;
int solve(int a, int b, char op)
{
    if(op == '*') return a*b;
    if(op == '/') return a/b;
    if(op == '+') return a+b;
    else return a-b;
}

int precedence(char op)
{
    if(op == '*' || op == '/') return 2;
    else return 1;
}

int infixEval(string str)
{
    stack<int> opand;
    stack<char> optor;

    for(auto it : str)
    {
        if(it == '(')
            optor.push(it);

        else if(isdigit(it))
            opand.push(it-'0');

        else if(it == '*' || it == '/' || it == '+' || it == '-')
        {
            while(!optor.empty() && optor.top() != '(' && (precedence(it) <= precedence(optor.top())))
            {
                int b = opand.top(); opand.pop();
                int a = opand.top(); opand.pop();
                char op = optor.top(); optor.pop();

                int temp = solve(a,b,op);
                opand.push(temp);
            }
            optor.push(it);
        }

        else if(it == ')')
        {
            while(!optor.empty() && optor.top() != '(')
            {
                int b = opand.top(); opand.pop();
                int a = opand.top(); opand.pop();
                char op = optor.top(); optor.pop();

                int temp = solve(a,b,op);
                opand.push(temp);
            }
            optor.pop();
        }
    }

    while(!optor.empty())
    {
        int b = opand.top(); opand.pop();
        int a = opand.top(); opand.pop();
        char op = optor.top(); optor.pop();

        int temp = solve(a,b,op);
        opand.push(temp);
    }

    return opand.top();
}

int main()
{
    string str = "2+(5-3*6/7)";
    cout<<infixEval(str);
}
