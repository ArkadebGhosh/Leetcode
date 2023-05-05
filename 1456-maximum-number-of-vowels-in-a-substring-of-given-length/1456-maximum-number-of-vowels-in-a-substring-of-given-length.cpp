class Solution {
public:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int ans = 0;
        int start = 0;
        int curr = 0;
        for(int i = 0; i<s.size(); i++) {
            int size = i-start+1;
            if(size > k) {
                if(isVowel(s[start]))
                --curr;
                ++start;
            }
            if(isVowel(s[i]))
                ++curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};