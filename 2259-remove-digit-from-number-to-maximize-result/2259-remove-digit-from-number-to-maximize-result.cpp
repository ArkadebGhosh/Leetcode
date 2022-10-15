class Solution {
public:
    string removeDigit(string number, char digit) {
        // vector<string> possible;
        // for(int i = 0; i<number.size(); i++) {
        //     if(number[i] == digit) {
        //         string str = "";
        //         for(int j = 0; j < number.size(); j++) {
        //             if(j!=i)
        //                 str+=number[j];
        //         }
        //         possible.push_back(str);
        //     }
        // }
        // sort(possible.begin(), possible.end());
        // return possible.back();
        int n = number.size();
        int idx = -1;
        int lastidx = 0;
        for(int i = 0; i<n; i++) {
            if(i<n-1 && number[i] == digit && number[i+1] > number[i]) {
                idx = i;
                break;
            }
            if(number[i] == digit)
                lastidx = i;
        }
        if(idx == -1)
            idx = lastidx;
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(i!=idx)
                ans+=number[i];
        }
        return ans;
    }
};