class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        while(a!=b) {
            if(a>b) {
                ans+='a';
                a--;
                if(a>0) {
                    ans+='a';
                    a--;
                }
                if(b>0) {
                    ans+='b';
                    b--;
                }
            }
            else {
                ans+='b';
                b--;
                if(b>0) {
                    ans+='b';
                    b--;
                }
                if(a>0) {
                    ans+='a';
                    a--;
                }
            }
        }
        
        if(a==b && a!=0) {
            string add = "ab";
            if(ans.size() && ans[ans.size()-1] == 'a')
                add = "ba";
            for(int i = 1; i<=a; i++)
                ans+=add;
        }
        return ans;
    }
};