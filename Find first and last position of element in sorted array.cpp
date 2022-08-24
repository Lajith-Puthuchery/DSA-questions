class Solution {
public:
    int bsearch(vector<int>& nums, int target, bool leftmost)
    {
        int low=0, high=nums.size()-1;
        int i = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                i = mid;
                if(leftmost)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return i;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        int leftmost = bsearch(nums, target, true);
        int rightmost = bsearch(nums, target, false);
        ans.push_back(leftmost);
        ans.push_back(rightmost);
        return ans;
    }
}