/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
*/

int findSubString(string s)
    {
        // Your code goes here
        int n = s.size();
        vector<int> freq(256, 0);
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(freq[s[i]]++ == 0)
            ++count;
        }
        freq = vector<int>(256, 0);
        int start = 0; int distinct = 0;
        int ans = n;
        for(int i = 0; i<n; i++) {
            if(freq[s[i]]++ == 0)
            ++distinct;
            while(distinct == count) {
                if(--freq[s[start]] == 0) {
                    --distinct;
                    ans = min(ans, i-start+1);
                }
                ++start;
            }
        }
        return ans;
    }
