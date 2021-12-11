class MinStack {
    stack<int> allData;
    stack<int> minData;
public:
    MinStack() {}
    
    void push(int val) {
        allData.push(val);
        if(minData.empty()||val <= minData.top())
            minData.push(val);
    }
    
    void pop() {
        if(allData.top() == minData.top())
            minData.pop();
        allData.pop();
    }
    
    int top() {
        return allData.top();
    }
    
    int getMin() {
        return minData.top();
    }
};