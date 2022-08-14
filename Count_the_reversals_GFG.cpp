/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/
int countRev (string s)
{
    int rev = 0;
    stack<char> st;
    for(int i = 0; i<s.size(); i++) {
        if(st.empty() && s[i] == '}') {
            ++rev;
            st.push('{');
        }
        else if(!st.empty() && st.top() == '{' && s[i] == '}') {
            st.pop();
        }
        else
        st.push('{');
    }
    if(st.size()%2 == 0) {
        return rev + st.size()/2;
    }
    return -1;
}
