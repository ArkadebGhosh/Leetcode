class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int currans = 0;
        int newpick = -1;
        int oldpick = -1;
        
        for(int i = 0; i<n; i++) {
            if(newpick == -1) {
                newpick = i;
                ++currans;
            }
            else if(fruits[i] == fruits[newpick]) {
                newpick = i;
                ++currans;
            }
            else if(oldpick == -1 || fruits[i] == fruits[oldpick]) {
                oldpick = newpick;
                newpick = i;
                ++currans;
            }
            else {
                ans = max(ans, currans);
                currans = i - oldpick;
                oldpick = newpick;
                newpick = i;
            }
        }
        ans = max(ans, currans);
        return ans;
    }
};