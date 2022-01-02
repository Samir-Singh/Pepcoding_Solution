#include<bits/stdc++.h>
using namespace std;
int isDuplicate(string str)
{
    stack<char> st;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            st.push(str[i]);

        else if(str[i]==')')
        {
            int flag = 0;
            while(!st.empty() && st.top() != '(')
            {
                if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
                    flag = 1;
                st.pop();
            }

            if(flag == 0)
                return 1;

            st.pop();
        }
    }

    return 0;
}

int main()
{
    string str = "(a + b) + ((c + d))";
    cout<<isDuplicate(str);
}
