class Solution {
public:
    string convert(string s, int numRows) {
        int n = numRows;
        string ans= "";
        int increment = 2*(n-1);
        if(n==1) {       //base case
            return s;
        }
        for(int row=0; row<n; row++) {
            for(int alpha=row; alpha<s.size(); alpha+=increment) {
                ans+=s[alpha];
                if(row>0 && row<n-1 && alpha+increment-2*row < s.size()) {
                    ans+=s[alpha+increment-2*row];
                }
            }
        }
        return ans;
    }
};