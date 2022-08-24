class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int left, right;
        for(int i=0; i<nums.size()-2; i++) {
            while(i>0 && i<nums.size()-2 && nums[i]==nums[i-1]) {
                i++;
            }
            left = i+1;
            right = nums.size()-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) {
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]) {
                        right--;
                    }
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};