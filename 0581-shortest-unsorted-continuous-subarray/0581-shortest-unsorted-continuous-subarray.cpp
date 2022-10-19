class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Sorting (O(nlogn))
//         vector<int> copy = nums;
//         sort(nums.begin(), nums.end());
//         int start = -1;
//         int end = -1;
//         int n = nums.size();
//         for(int i = 0; i<n; i++) {
//             if(copy[i] != nums[i]) {
//                 start = i;
//                 break;
//             }
//         }
        
//         for(int i = n-1; i>=0; i--) {
//             if(copy[i] != nums[i]) {
//                 end = i;
//                 break;
//             }
//         }
//         if(start == -1)
//             return 0;
//         return end - start + 1;
        
        //Stack (O(n))
        stack<int> st;
        int n = nums.size();
        st.push(0);
        int start = n;
        for(int i = 1; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                start = min(start, st.top());
                st.pop();
            }
            st.push(i);
        }
        if(start == n)
            return 0;
        while(!st.empty())
            st.pop();
        int end = -1;
        st.push(n-1);
        for(int i = n-2; i>=0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                end = max(end, st.top());
                st.pop();
            }
            st.push(i);
        }
        return end-start+1;
    }
};