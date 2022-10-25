class StockPrice {
public:
    multiset<int> prices;
    unordered_map<int, int> m;
    int latest = 0;
    StockPrice() {
        // prices.clear();
        // m.clear();
        latest = 0;
    }
    
    void update(int timestamp, int price) {
        int old = -1;
        if(m.count(timestamp) == 1)
            old = m[timestamp];
        m[timestamp] = price;
        if(timestamp > latest) {
            latest = timestamp;
        }
        if(old != -1) {
            multiset<int>:: iterator it = prices.find(old);
            prices.erase(it);
        }
        prices.insert(price);
    }
    
    int current() {
        return m[latest];
    }
    
    int maximum() {
        multiset<int>:: reverse_iterator it = prices.rbegin();
        return *it;
    }
    
    int minimum() {
        multiset<int>:: iterator it = prices.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */