class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        if(nums[0]<nums[nums.size()-1])
            return nums[0];
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]>=nums[0]) 
                low=mid+1;
            else
                high=mid-1;
        }
        return nums[low];
    }
};