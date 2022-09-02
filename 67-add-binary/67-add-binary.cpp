class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int n = a.size();
        int m = b.size();
        int ptr1 = 0, ptr2 = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        while(ptr1 < n || ptr2 < m) {
            int d1 = ptr1<n ? a[ptr1] - '0': 0;
            int d2 =  ptr2<m ? b[ptr2] - '0': 0;
            int sum;
            if(d1+d2+carry == 0) {
                sum = 0;
                carry  = 0;
            }
            else if(d1+d2+carry==2) {
                sum = 0;
                carry = 1;
            }
            else if(d1+d2+carry == 1) {
                sum = 1;
                carry=0;
            }
            else {
                sum = 1;
                carry = 1;
            }
            // cout<<sum<<" "<<carry<<endl;
            result+=to_string(sum);
            ++ptr1;
            ++ptr2;
        }
        if(carry == 1)
            result+='1';
        reverse(result.begin(), result.end());
        return result;
    }
};