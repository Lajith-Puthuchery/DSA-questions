//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergesort(long long arr[], long long temp[], long long low, long long high)
    {
        long long int mid, inv=0;
        if(low<high)
        {
            mid=(low)+(high-low)/2;
            inv+=mergesort(arr, temp, low, mid);
            inv+=mergesort(arr, temp, mid+1, high);
            inv+=merge(arr, temp, low, mid+1, high);
        }
        return inv;
    }
    
    long long int merge(long long arr[], long long temp[], long long low, long long mid, long long high)
    {
        int i=low, j=mid, k=low;
        long long int inv=0;
        while((i<=mid-1) && (j<=high))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                inv+=(mid-i);
            }
        }
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=high)
        {
            temp[k++]=arr[j++];
        }
        for(i=low; i<=high; i++)
        {
            arr[i]=temp[i];
        }
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergesort(arr, temp, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends