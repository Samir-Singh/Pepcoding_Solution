class Solution {
public:
int isCounterPresent(char a, char b)
{
    if(a == '(' && b == ')') return 1;
    if(a == '{' && b == '}') return 1;
    if(a == '[' && b == ']') return 1;
    
    return 0;
}
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s)
        {
            if(it == '(' || it == '{' || it == '[')
                st.push(it);
            else if(it == ')' || it == '}' || it == ']')
            {
                if(st.empty())
                    return 0;
                char top = st.top();
                if(!isCounterPresent(top,it)) return 0;
                else st.pop();
            }
        }
        if(!st.empty()) return 0;
        return 1;
    }
};