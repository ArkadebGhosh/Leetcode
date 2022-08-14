/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
*/
//USING 2 ARRAYS
long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> firstlessleft (n, -1);
        vector<int> firstlessright (n, n);
        stack<int> st; // Indexes of nle
        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                firstlessright[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                firstlessleft[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long long int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, (firstlessright[i] - firstlessleft[i] - 1) * arr[i]);
        }
        return ans;
    }
// USING one pass and one stack
// while arr[i] is capable of being a first lesser right to any element, calculate the area for stack tops, with nlright(top) = a[i] & nlleft(top) = (st.pop().top())
// Handle case when st is empty 

long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> st;
        long long int maxarea = 0;
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                int topidx = st.top();
                long long int topval = arr[topidx];
                st.pop();
                if(st.empty())
                maxarea = max(maxarea, i * topval);
                else {
                    maxarea = max(maxarea, (i - st.top()-1) * topval);
                }
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            long long int topval = arr[st.top()];
            st.pop();
            if(st.empty())
            maxarea = max(maxarea, topval * n);
            else
            maxarea = max(maxarea, topval * (n-st.top() - 1));
        }
        return maxarea;
    }
