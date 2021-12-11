class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        
        int ans;
        i++;
        while(!st.empty() && price >= st.top().first)
            st.pop();
        
        if(!st.empty())
            ans = i-st.top().second;
        else
            ans = i;
        st.push({price,i});
        return ans;
    }
};
