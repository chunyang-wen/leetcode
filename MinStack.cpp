class MinStack {
public:
    void push(int x) {
        sp.push(x);
        if (minSp.empty() || minSp.top() >= x)
            minSp.push(x);
    }

    void pop() {
        
        if (sp.top() == minSp.top())
            minSp.pop();
    
        sp.pop();
    }

    int top() {
        return sp.top();
    }

    int getMin() {
        return minSp.top();
    }
private:
    stack<int> sp;
    stack<int> minSp;
};