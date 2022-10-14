class Logger {
public:
    
    unordered_map<string, int> hash;
    Logger() {
        hash.clear();        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(hash.count(message) == 0) {
            hash[message] = timestamp;
            return true;
        }
        if(timestamp - hash[message] >= 10) {
            hash[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */