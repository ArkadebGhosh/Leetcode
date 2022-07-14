// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char> st;
        
        int l = s.size();
        for(int i = 0; i<l; i++) {
            char ch = s.at(i);
            if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
            else {
                if(st.empty())
                return false;
                char top = st.top();
                if(ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[') {
                    st.pop();
                }
                else
                return false;
            }
        }
        
        if(st.empty())
        return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends