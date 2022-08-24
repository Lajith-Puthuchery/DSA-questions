class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int after[n];
        int before[n];
        int max_before=height[0];
        int max_after=height[n-1];
        for(int i=1; i<n-1; i++) {
            before[i] = max(max_before,height[i-1]);
            max_before = before[i];
        }
        for(int i=n-2; i>0; i--) {
            after[i] = max(max_after,height[i+1]);
            max_after = after[i];
        }
        int ans=0;
        for(int i=1; i<n-1; i++) {
            int block = min(before[i],after[i]) - height[i];
            if(block>0) {
                ans = ans + block;
            }
        }
        return ans;
    }
};