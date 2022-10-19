class Solution {
public:
    
    static bool cmp(int x, int y)
    {
        string a = to_string(x);
        string b = to_string(y);
        
        if (a.size() > b.size() && a.compare(0, b.size(), b) == 0) {
            string x = a.substr(b.size());
            return (x + b) < (b + x);
        }
        
        if (a.size() < b.size() && b.compare(0, a.size(), a) == 0) {
            string x = b.substr(a.size());
            return (x + a) > (a + x);
        }
        
        else return a < b;
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