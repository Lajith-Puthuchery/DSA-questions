class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int max = nums[0];
        int min = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]<0)
            {
                swap(max,min);
            }
            max = std::max(nums[i],nums[i]*max);
            min = std::min(nums[i],nums[i]*min);
            ans = std::max(max,ans);
        }
        return ans;
    }
};