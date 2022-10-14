

class Solution {
public:
    struct comp
    {
        bool operator() (pair<int, string> &a, pair<int, string> &b)
        {
            return a.first > b.first || (a.first == b.first && a < b);
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto &word: words)
            m[word]+=1;
        for(auto &it: m) {
            string word = it.first;
            int freq = it.second;
            // cout<<word<<" "<<freq<<endl;
            if(pq.size() < k) {
                pq.push({freq, word});
            }
            else {
                int topfreq = pq.top().first;
                string topword = pq.top().second;
                // cout<<"topword: "<<topword<<" ,topfreq: "<<topfreq<<endl;
                if(topfreq < freq || (topfreq == freq && topword > word)) {
                    pq.pop();
                    pq.push({freq, word});
                }
            }
        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};