class CustomStack {
public:
    vector<int> stack, inc;
    int maxsize;
    CustomStack(int maxSize) {
        maxsize =  maxSize;
    }
    
    void push(int x) {
        if(stack.size() < maxsize) {
            stack.push_back(x);
            inc.push_back(0);
        }
            
    }
    
    int pop() {
        if(stack.size()==0)
            return -1;
        int top = stack.back();
        int topinc = inc.back();
        int n = stack.size();
        stack.pop_back();
        inc.pop_back();
        if(n>1) {
            inc.back()+=topinc;
        }
        return top+topinc;        
    }
    
    void increment(int k, int val) {
        if(stack.size() == 0)
            return;
        int pos = min(k-1, (int)stack.size()-1);
        inc[pos] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */