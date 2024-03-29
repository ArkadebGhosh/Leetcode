// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n, -1);
        stack<long long> st;
        
        st.push(0);
        
        for(int i = 1; i<n; i++) {
            long long top = st.top();
            long long curr = arr[i];
            if(curr <= arr[top])
            st.push(i);
            else {
                while(!st.empty() && arr[st.top()] < curr) {
                    ans[st.top()] = curr;
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends