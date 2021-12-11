// Approach1 : Gives TLE
// TC : O(N^2)
// SC : O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1)
            return heights[0];
        
        int ans = INT_MIN;
        int count,l,r;
        for(int i=0; i<heights.size(); i++)
        {
            count = 0;
            l = r = i;
            while(l-1 >=0 && heights[l-1] >= heights[i])
            {
                count++;
                l--;
            }
            while(r+1 < heights.size() && heights[r+1] >= heights[i])
            {
                count++;
                r++;
            }
            
            ans = max(ans, heights[i]*(count+1));
        }
        
        return ans;
    }
};

// Approach2 : finding next smaller on left & next smaller on right
// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<int> next_small_left(vector<int> arr)
{
    stack<int> st;
    vector<int> newarr(arr.size());
    st.push(0);
    newarr[0] = -1;
    
    for(int i=1; i<=arr.size()-1; i++)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
            
        if(st.empty())
            newarr[i] = -1;
        else
            newarr[i] = st.top();
        st.push(i);
    }
    
    return newarr;
}
vector<int> next_small_right(vector<int> arr)
{
    stack<int> st;
    vector<int> newarr(arr.size());
    st.push(arr.size()-1);
    newarr[arr.size()-1] = arr.size();
    
    for(int i=arr.size()-2; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(!st.empty())
            newarr[i] = st.top();
        else
            newarr[i] = arr.size();
        st.push(i);
    }
    
    return newarr;
}
    int largestRectangleArea(vector<int>& arr) {
        vector<int> nsl = next_small_left(arr);
        vector<int> nsr = next_small_right(arr);
    
        int ans = INT_MIN;
        for(int i=0; i<arr.size(); i++)
            ans = max(ans, (nsr[i]-nsl[i]-1)*arr[i]);
    
        return ans;
    }
};