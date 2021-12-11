#include<bits/stdc++.h>
using namespace std;
void numberPattern(string str)
{
    stack<int> st;
    int num=1;
    for(auto it : str)
    {
        if(it == 'd')
        {
            st.push(num);
            num++;
        }
        else if(it == 'i')
        {
            st.push(num);
            num++;
            while(!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
        }
    }
    st.push(num);
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    string str = "ddiddidd";
    numberPattern(str);
}