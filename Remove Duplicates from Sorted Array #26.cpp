class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<2) {
            return n;
        }
        int count = 1;
        for(int i=0, j=1; j<n; ) {
            if(nums[i]==nums[j]) {
                j++;
            }
            else {
                nums[i+1] = nums[j];
                i++;
                j++;
                count++;
            }
        }
        return count;
    }
};