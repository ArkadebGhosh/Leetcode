class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxleft;
        
        int l = height.size();
        vector<int> maxright(l,0);
        maxleft.push_back(height[0]);
        for(int i = 1; i < l; i++) 
            maxleft.push_back(max(maxleft[i-1], height[i]));
        maxright[l-1] = (height[l-1]);
        for(int i = l-2; i >= 0; i--) 
            maxright[i] = (max(maxright[i+1], height[i]));
        int ans = 0;
        
        for(int i = 0; i<l; i++) {
            int left = i-1>=0 ? maxleft[i-1] : 0;
            int right = i+1<l ? maxright[i+1] : 0;
            ans += max(0, min(left, right) - height[i]);
        }
        return ans;
    }
};