class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> index;
        for(int i = 0; i<target.size(); i++)
            index[target[i]] = i;
        vector<int> tails;
        for(int i = 0; i<arr.size(); i++) {
            if(index.count(arr[i])) {
                if(tails.size() == 0 || index[arr[i]] > tails.back()) {
                    tails.push_back(index[arr[i]]);
                }
                else {
                    int lb = lower_bound(tails.begin(), tails.end(), index[arr[i]]) - tails.begin();
                    tails[lb] = index[arr[i]];
                }
            }
        }
        return target.size() - tails.size();
    }
};