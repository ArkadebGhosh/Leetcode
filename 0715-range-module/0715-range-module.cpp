class RangeModule {
public:
    map<int, int> m; // first -> Begin, second -> End
    RangeModule() {
        m.clear();
    }
    
    void addRange(int left, int right) {
        if(m.size() == 0) {
            m[left] = right - 1;
            return;
        }            
        removeRange(left, right);
        --right;
        map<int, int>:: iterator it, it2;
        it = m.lower_bound(left);
        it2 = it;
        if(it == m.begin()) {
            m[left] = right;
        }
        else {
            --it;
            int low = (*it).first;
            int high = (*it).second;
            if(high == left-1) {
                m[low] = max(high, right);
                left = low;
            }
            else {
                m[left] = right;
            }
        }
        if(it2 == m.end())
            return;

        if((*it2).first == right+1 ) {
            m[left] = (*it2).second;
            m.erase((*it2).first);
        }
    }
    
    bool queryRange(int left, int right) {
        --right;
        map<int, int>:: iterator it = m.lower_bound(left);
        if(((*it).first) == left && ((*it).second) >= right) {
            return true;
        }
        else if((*it).first > left && (*it).first <= right) {
            return false;
        }
        else if (it != m.begin()) {
            --it;
            if((*it).second >= right)
                return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        if(m.size() == 0)
            return;
        --right;
        map<int, int>:: iterator it, it2;
        it= m.lower_bound(left);
        it2 = it;
        while(it != m.end()) {
            int low = (*it).first;
            int high = (*it).second;
            ++it;
            if(low > right)
                break;
            if(high <= right) 
                m.erase(low);
            else if(high > right) {
                m.erase(low);
                m[right+1] = high;
            }
        }
        it2 = m.lower_bound(left);
        if(it2 == m.begin()) 
            return;
        --it2;
        int low = (*it2).first;
        int high = (*it2).second;
        if(high >= left) 
            m[low] = left - 1;

        if(high > right) 
            m[right+1] = high;
        
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */