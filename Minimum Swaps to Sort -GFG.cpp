//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    map<int,int> pos;
	    vector<int> sorted = nums;
	    sort(sorted.begin(), sorted.end());
	    for(int i=0; i<nums.size(); i++)
	    {
	        pos[sorted[i]]=i;
	    }
	    int count=0;
	    int i=0;
	    while(i<nums.size())
	    {
	        if(nums[i]!=sorted[i])
	        {
	            swap(nums[i], nums[pos[nums[i]]]);
	            count++;
	        }
	        else
	            i++;
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends