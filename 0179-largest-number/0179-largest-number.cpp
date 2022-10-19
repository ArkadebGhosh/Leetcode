class Solution {
public:
    
    static bool cmp(int x, int y)
    {
        string a = to_string(x);
        string b = to_string(y);
        return a + b < b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();
        for(int i = n-1; i>=0; i--) {
            ans+=to_string(nums[i]);
        }
        int nz = 0;
        while(nz< ans.size() && ans[nz] == '0') {
            nz++;
        }
        if(nz == ans.size())
            return "0";
        return ans.substr(nz);
    }
};