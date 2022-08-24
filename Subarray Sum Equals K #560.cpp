class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixsum;
        int sum=0;
        int n=nums.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(sum==k)
                count++;
            if(prefixsum.find(sum-k)!=prefixsum.end())
                count+=prefixsum[sum-k];
            prefixsum[sum]++;
        }
        return count;
    }
};