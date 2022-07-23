class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left= 0;
        int right = s.size()-1;
        int swaps = 0;
        while(left<right) {
            int r = right;
            while(s.at(left) != s.at(r))
                --r;
            if(left == r) {
                swap(s[r], s[r+1]);
                ++swaps;
                r = right;
            }
            else {
                while(r<right) {
                    swap(s[r], s[r+1]);
                    ++r;
                    ++swaps;
                }
                ++left;
                --right;
            }
        }
        return swaps;
    }
};