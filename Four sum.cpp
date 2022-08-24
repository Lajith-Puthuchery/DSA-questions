#include <iostream>
using namespace std;
#include <vector>

int main() {
	// your code goes here
	int n,t;
	cin>>n>>t;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++)
	{
	    cin>>arr[i];
	}
	int result=0;
	for(int i=n-1; i>=3; i--)
	{
	    for(int j=n-2; j>=2; j--)
	    {
	        int low=0, high=j-1;
	        while(low<=high)
	        {
	            int sum=arr[i]+arr[j]+arr[low]+arr[high];
	            if(sum==t)
	            {
	                result++;
	                low++;
	                high--;
	            }
	            else if(sum<t)
	                low++;
	           else
	            high--;
	        }
	    }
	}
	cout<<result;
	return 0;
}
