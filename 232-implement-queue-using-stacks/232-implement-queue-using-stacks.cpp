class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();
    }
    
    void push(int x) {
        this->st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()) {
            int top = this->st1.top();
            this->st2.push(top);
            this->st1.pop();
        }
        int top = this->st2.top();
        this->st2.pop();
        while(!st2.empty()) {
            int top = this->st2.top();
            this->st1.push(top);
            this->st2.pop();
        }
        return top;
    }
    
    int peek() {
        while(!st1.empty()) {
            int top = this->st1.top();
            this->st2.push(top);
            this->st1.pop();
        }
        int top = this->st2.top();
        //this->st2.pop();
        while(!st2.empty()) {
            int top = this->st2.top();
            this->st1.push(top);
            this->st2.pop();
        }
        return top;
    }
    
    bool empty() {
        return this->st1.empty();
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