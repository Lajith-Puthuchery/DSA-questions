class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> is(m+1, vector<int> (n+1, 0));
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==t[j-1])
                    is[i][j]=1+is[i-1][j-1];
                else
                    is[i][j]=max(is[i][j-1], is[i-1][j]);
            }
        }
        return is[m][n]==m;
    }
};