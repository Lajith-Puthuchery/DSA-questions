//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void rearrange(int arr[], int n) {
	    // code here
        vector<int> pos;
        vector<int> neg;
        vector<int> result;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>=0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }
        int i;
        for(i=0; i<pos.size() && i<neg.size(); i++)
        {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }
        while(i<pos.size())
        {
            result.push_back(pos[i]);
            i++;
        }
        while(i<neg.size())
        {
            result.push_back(neg[i]);
            i++;
        }
        for(int i=0; i<n; i++)
        {
            arr[i]=result[i];
        }
        
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends