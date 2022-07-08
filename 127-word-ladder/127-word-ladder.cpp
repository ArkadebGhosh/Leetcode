class Solution {
public:
    bool owd(string a, string b) {
        if(a.size()!=b.size())
            return false;
        int c = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a.at(i) != b.at(i))
                ++c;
            if(c==2)
                return false;
        }
        if(c==1)
            return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> hash(wordList.begin(), wordList.end());
        wordList.push_back(beginWord);
        queue<pair<string, int>> q;
        q.push(make_pair(wordList[n], 0));
        hash.erase(beginWord);
        while(!q.empty()) {
            pair<string, int> frontp = q.front();
            string node = frontp.first;
            int depth = frontp.second;
            if(node == endWord)
                return depth+1;
            for(int i = 0; i < node.size(); i++) {
                string neigh = node;
                char org = neigh[i];
                for(char j = 'a'; j <= 'z'; j++) {
                    if(j != org)
                        neigh[i] = j;
                    if(hash.count(neigh) > 0) {
                        q.push(make_pair(neigh, depth+1));
                        hash.erase(neigh);
                    }
                        
                }   
            }
            q.pop();
        }
        return 0;
    }
};