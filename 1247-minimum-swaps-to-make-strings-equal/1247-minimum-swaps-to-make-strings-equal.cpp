class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        int n = s1.size();
        for(int i = 0; i<n; i++) {
            if(s1[i] == 'x' && s2[i] == 'y') 
                ++xy;
            else if(s1[i] == 'y' && s2[i] == 'x') 
                ++yx;
        }
        
        int swaps = 0;
        swaps = xy/2 + yx/2;
        xy = xy%2;
        yx = yx%2;
        
        if(xy != yx)
            return -1;
        else if(xy > 0)
            swaps+=2;
        return swaps;
    }
};