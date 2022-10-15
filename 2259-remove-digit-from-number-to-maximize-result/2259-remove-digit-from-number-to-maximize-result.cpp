class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> possible;
        for(int i = 0; i<number.size(); i++) {
            if(number[i] == digit) {
                string str = "";
                for(int j = 0; j < number.size(); j++) {
                    if(j!=i)
                        str+=number[j];
                }
                possible.push_back(str);
            }
        }
        sort(possible.begin(), possible.end());
        return possible.back();
    }
};