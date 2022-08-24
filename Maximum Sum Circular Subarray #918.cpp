class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]>max) {
                max=nums[i];
            }   
        }
        if(max<0)
            return max;
        int max_kadane = kadane(nums);
        int max_wrap = 0;
        for(int i=0; i<nums.size(); i++) {
            max_wrap += nums[i];
                nums[i] = -nums[i];
        }
        max_wrap += kadane(nums);
        return (max_kadane > max_wrap ? max_kadane : max_wrap);
    }
    
    int kadane(vector<int>& nums) {
        int curr_sum=0, max_sum=INT_MIN;
        int start = 0;
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            if(curr_sum>max_sum)
                max_sum=curr_sum;
            while(curr_sum<0) {
                curr_sum -= nums[start];
                start++;
            }
        }
        return max_sum;
    }
};