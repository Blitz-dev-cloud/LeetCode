class MyQueue {
private:
    stack<int> s;
    stack<int> a;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(!s.empty()) {
            a.push(s.top());
            s.pop();
        }
        int res = a.top();
        a.pop();
        while(!a.empty()) {
            s.push(a.top());
            a.pop();
        }
        return res;
    }
    
    int peek() {
        while(!s.empty()) {
            a.push(s.top());
            s.pop();
        }
        int res = a.top();
        while(!a.empty()) {
            s.push(a.top());
            a.pop();
        }
        return res;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */