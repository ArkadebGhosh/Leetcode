class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
        for(int i = 0; i<s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i<26; i++) {
            if(freq[i])
            pq.push({freq[i], (char)(i+'a')});
        }
        string ans = "";
        while(!pq.empty()) {
            if(pq.size() == 1 && pq.top().first >=2)
                return "";
            int high_freq = pq.top().first;
            char highest = pq.top().second;
            ans += highest;
            pq.pop();
            int second_freq = 0;
            char second;
            if(pq.size()) {
                second_freq = pq.top().first;
                second = pq.top().second;
                ans += second;
                pq.pop();
            }
            if(high_freq - 1)
                pq.push({high_freq - 1, highest});
            if(second_freq - 1 > 0)
                pq.push({second_freq - 1, second});
        }
        return ans;
    }
};