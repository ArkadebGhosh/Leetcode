class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int valdec = -1;
        int n = tops.size();
        vector<int> ftop(7, 0);
        vector<int> fbottom(7, 0);
        int same = 0;
        for(int i = 0; i<n; i++) {
            ftop[tops[i]]++;
            fbottom[bottoms[i]]++;
            if(valdec == -1 && tops[i] == bottoms[i]) {
                ++same;
                valdec = tops[i];
            }
            else if(tops[i] == bottoms[i] && tops[i]!=valdec)
                return -1;
            else if(tops[i] == bottoms[i])
                ++same;
        }
        
        // cout<<valdec<<" "<<same<<endl;
        
        if(valdec!=-1) {
            if(ftop[valdec] + fbottom[valdec] - same == n)
                return min(ftop[valdec] - same, fbottom[valdec] - same);
            return -1;
        }
            
        for(int i = 1; i<=6; i++) {
            if(ftop[i] + fbottom[i] == n)
                return min(ftop[i], fbottom[i]);
        }
        return -1;
    }
};