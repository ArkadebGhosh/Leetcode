class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int tsize = 0;
    
    MedianFinder() {
        tsize = 0;
    }
    
    void addNum(int num) {
        if(tsize == 0) {
            left.push(num);
            ++tsize;
            return;
        }
        double m = findMedian();
        if(num > m) {
            right.push(num);
            if(right.size() > left.size()) {
                int ele = right.top();
                right.pop();
                left.push(ele);
            }
        }
        else
        {
            left.push(num);
            if(left.size() - right.size() > 1) {
                int ele = left.top();
                left.pop();
                right.push(ele);
            }
        }
        ++tsize;
    }
    
    double findMedian() {
        if(tsize%2 == 1)
            return left.top();
        else
            return (double)(left.top() + right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */