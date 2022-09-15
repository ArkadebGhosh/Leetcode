class Solution {
public:
    int minimumDeletions(string s) {
        int numb = 0, del = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == 'b')
                ++numb;
            else {
                del = min(numb, del+1);
            }
        }
        return del;
    }
};