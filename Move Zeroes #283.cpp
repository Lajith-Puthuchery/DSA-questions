class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        for(int j=0; j<n; j++)
        {
            if(nums[j]!=0)
                nums[k++]=nums[j];
        }
        for(;k<n; k++)
        {
            nums[k]=0;
        }
    }
};