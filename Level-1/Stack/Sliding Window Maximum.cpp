// Approach1 : Using two loops but gives TLE on leetcode
// TC : O(N^2);
// SC : O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> newarr;
        for(int i=0; i<=nums.size()-k; i++)
        {
            int ans = INT_MIN;
            for(int j=i; j<=i+k-1; j++)
                ans = max(ans, nums[j]);
            newarr.push_back(ans);
        }
        return newarr;
    }
};

// Approach2 : Using next_greater_right logic
// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<int> next_greater_right(vector<int> arr)
    {
        stack<int> st;
        vector<int> ans(arr.size());
        st.push(arr.size()-1);
        ans[arr.size()-1] = arr.size();
        for(int i=arr.size()-2; i>=0; i--)
        {
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if(st.empty())
                ans[i] = arr.size();
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> nge = next_greater_right(nums);
        vector<int> ans;
        
        int j = 0;
        for(int i=0; i<=nums.size()-k; i++)
        {
            if(j < i)
                j = i;
            while(nge[j] < i+k)
                j = nge[j];
            ans.push_back(nums[j]);
        }
        return ans;
    }
};