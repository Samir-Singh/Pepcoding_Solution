#include<bits/stdc++.h>
using namespace std;
int precedence(char a)
{
    if(a == '*' || a == '/')
        return 2;
    else
        return 1;
}

int operation(int a, int b, char op)
{
    if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else if(op == '*')
        return a*b;
    else
        return a/b;
}

long long int infixEvaluation(string str)
{
    stack<long long int> oprand;
    stack<char> oprtor;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == ' ')
            continue;
            
        else if(str[i] == '(')
            oprtor.push(str[i]);
            
        else if(isdigit(str[i]))
            oprand.push(str[i]-'0');
            
        else if(str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-')
        {
            while(!oprtor.empty() && oprtor.top()!='(' && (precedence(str[i]) <= precedence(oprtor.top())))
            {
                int b = oprand.top();
                oprand.pop();
                int a = oprand.top();
                oprand.pop();
                char op = oprtor.top();
                oprtor.pop();
                
                int temp = operation(a,b,op);
                oprand.push(temp);
            }
            oprtor.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!oprtor.empty() && oprtor.top() != '(')
            {
                int b = oprand.top();
                oprand.pop();
                int a = oprand.top();
                oprand.pop();
                char op = oprtor.top();
                oprtor.pop();
                
                int temp = operation(a,b,op);
                oprand.push(temp);
            }
            oprtor.pop();
        }
    }
    
    while(!oprtor.empty())
    {
        int b = oprand.top();
        oprand.pop();
        int a = oprand.top();
        oprand.pop();
        char op = oprtor.top();
        oprtor.pop();
                
        int temp = operation(a,b,op);
        oprand.push(temp);
    }
    
    return oprand.top();
}

int main()
{
    string str = "3 / (6 * 8 - 4) + 9";
    cout<<infixEvaluation(str);
}
