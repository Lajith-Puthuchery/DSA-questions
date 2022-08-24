class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum=0;
        int min=INT_MAX;
        int n=nums.size();
        int start=0;
        for(int end=0; end<n; end++)
        {
            currSum+=nums[end];
            while(currSum>=target)
            {
                if(end-start+1<min)
                    min=end-start+1;
                currSum-=nums[start];
                start++;
            }
        }
        return min==INT_MAX ? 0 : min;
    }
};