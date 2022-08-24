class Solution {
public:
    int memo[1000][1000] = {0};
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        if(memo[m][n]==0)
            memo[m][n] = uniquePaths(m, n-1) + uniquePaths(m-1, n); 
        return memo[m][n];
    }
};