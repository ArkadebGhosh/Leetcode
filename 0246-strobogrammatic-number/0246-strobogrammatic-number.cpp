class Solution {
public:
    
    bool isStrobogrammatic(string num) {
        string cpy = num;
        reverse(num.begin(), num.end());
        string ans = "";
        for(auto &c: num) {
            if(c == '9')
                ans += '6';
            else if(c=='6')
                ans += '9';
            else if(c=='8')
                ans += '8';
            else if(c=='1')
                ans += '1';
            else if(c=='0')
                ans += '0';
            else
                return false;
        }
        if(ans.compare(cpy) == 0)
            return true;
        return false;
    }
};