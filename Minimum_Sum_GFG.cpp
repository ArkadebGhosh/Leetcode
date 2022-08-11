/*
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.
*/

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string num1 = "";
        string num2 = "";
        sort(arr, arr+n);
        for(int i = 0; i<n; i++) {
            num1 = num1 + to_string(arr[i]);
            ++i;
            if(i>=n)
            break;
            num2 = num2 + to_string(arr[i]);
        }
        return add(num1, num2);
    }
    
    string add(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int p1 = 0, p2 = 0;
        int carry = 0;
        string ans = "";
        while(p1 < s1.size() || p2 < s2.size()) {
            int d1 = (p1 < s1.size())? s1[p1] - '0': 0;
            int d2 = (p2 < s2.size())? s2[p2] - '0': 0;
            int sum = (d1+d2+carry)%10;
            carry = (d1+d2+carry)/10;
            ans+= to_string(sum);
            ++p1;
            ++p2;
        }
        if(carry>0)
        ans+=to_string(carry);
        int i = 0;
        reverse(ans.begin(), ans.end());
        while(ans[i] == '0') 
        ++i;
        return ans.substr(i);
    }
};
