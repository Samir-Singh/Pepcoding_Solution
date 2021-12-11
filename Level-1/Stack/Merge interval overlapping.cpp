class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<pair<int,int>> st;
        vector<vector<int>> ans;
        st.push({intervals[0][0], intervals[0][1]});
        
        for(auto it : intervals)
        {
            if(it.front() <= st.top().second)
                st.top().second = max(st.top().second, it.back());
            else
            {
                ans.push_back({st.top().first, st.top().second});
                st.push({it.front(), it.back()});
            }
        }
        
        ans.push_back({st.top().first, st.top().second});
        
        return ans;
    }
};