class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        --end;
        if(m.size() == 0) {
            m[start] = end;
            return true;
        }
        
        map<int, int>:: iterator it = m.lower_bound(start);
        if(it != m.end()) {
            int low = (*it).first;
            int high = (*it).second;
            if(low <= end) {
                return false;
            }
        }
        if(it!=m.begin()) {
            --it;
            int low = (*it).first;
            int high = (*it).second;
            if(high >= start) {
                return false;
            }
        }
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */