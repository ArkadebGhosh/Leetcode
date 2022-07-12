class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> allowed;
        for(int i = 1; i<=26; i++) {
            allowed.insert(to_string(i));
        }
        int start = 0;
        int end = s.size()-1;
        int l = s.size();
        vector<vector<int>> memo(l+1, vector<int>(l+1, -1));
        return decode(s, start, end, allowed, memo);
    }
    
    int decode(string &s, int start, int end, unordered_set<string> &allowed, vector<vector<int>> &memo) {
        if(start == end && s.at(start) == '0')
            return 0;
        else if(start >= end)
            return 1;
        
        string extone = s.substr(start, 1);
        int part1 = 0, part2 = 0;
        if(allowed.count(extone) > 0) {
            if(memo[start+1][end] != -1)
                part1 = memo[start+1][end];
            else
                part1 = decode(s, start+1, end, allowed, memo);
        }
        string exttwo = "";
        if(start < end) {
            exttwo = s.substr(start, 2);
            if(allowed.count(exttwo) > 0) {
                if(memo[start+2][end] != -1)
                    part2 = memo[start+2][end];
                else
                    part2 = decode(s, start+2, end, allowed, memo);
            }
        }
        memo[start][end] = part1 + part2;
        return memo[start][end];
    }
};