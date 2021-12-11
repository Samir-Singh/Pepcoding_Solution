#include<bits/stdc++.h>
using namespace std;
int findCelebrity(vector<vector<int>> vec)
{
    stack<int> st;
    for(int i=0; i<=vec.size()-1; i++)
        st.push(i);
    
    while(st.size() >= 2)
    {
        int j = st.top(); st.pop();
        int i = st.top(); st.pop();
        
        if(vec[i][j] == 0) // means j is not celebrity
            st.push(i);
        else if(vec[i][j] == 1) // means i is not celebrity
            st.push(j);
    }
    
    // st.top() has potential to become celebrity
    for(int i=0; i<vec.size(); i++)
    {
        if(i != st.top())
        {
            if((vec[i][st.top()] == 0) || (vec[st.top()][i] == 1))
                return -1;
        }
    }
    
    return st.top();
}
int main()
{   
    vector<vector<int>> vec
    {
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0}
    };
    
    cout<<findCelebrity(vec);
}