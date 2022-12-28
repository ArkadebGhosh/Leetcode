class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int start = 0, end = 0;
        int n = arr.size();
        vector<int> pos(n);
        for(int i = 0; i<n; i++)
            pos[arr[i]] = i;
        end = pos[0];
        int chunks = 0;
        while(start < n) {
            // start == end
            if(arr[start] > end)
                end = arr[start];
            ++start;
            if(start > end) {
                ++chunks;
                if(start < n)
                    end = pos[start];
            }
        }
        return chunks;
    }
};