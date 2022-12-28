class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int start = 0;
        int high = INT_MIN;
        int n = arr.size();
        int chunks = 0;
        for(int i = 0; i<n; i++) {
            high = max(high, arr[i]);
            if(high == i)
                 ++chunks;
        }
        return chunks;
    }
};