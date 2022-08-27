class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> memo(n, vector<int>(2001, -1));
        unordered_map<int, int> stone_index;
        for(int i = 0; i<stones.size(); i++) {
            stone_index[stones[i]] = i;
        }
        int crossed = check(stones, 0, 1, memo, stone_index);
        return (crossed == 1) ? true: false;
    }
    
    int check(vector<int> &stones, int start, int jump, vector<vector<int>> &memo, unordered_map<int, int> &stone_index) {
        
        // cout<<start<<" "<<jump<<endl;
        if(memo[start][jump] != -1)
            return memo[start][jump];
        
        if(jump == 0) {
            memo[start][jump] = 0;
            // cout<<"***"<<endl;
            return 0;
        }
        
        int nextstone = stones[start]+jump;
        // cout<<"Nextstone: "<<nextstone<<endl;
        int nextindex = -1;
        if(stone_index.count(nextstone)) {
            nextindex = stone_index[nextstone];
            if(nextindex == stones.size()-1) {
                memo[start][jump] = 1;
                return 1;
            }
            memo[start][jump] = 
                (check(stones, nextindex, jump-1, memo, stone_index)
                || check(stones, nextindex, jump, memo, stone_index)
                || check(stones, nextindex, jump+1, memo, stone_index)) ? 1 : 0;
            return memo[start][jump];
        }
        // cout<<"Stones doesnt exists for "<<start<<" "<<jump<<" "<<nextstone<<endl;
        memo[start][jump] = 0;
        return 0;
    }
};