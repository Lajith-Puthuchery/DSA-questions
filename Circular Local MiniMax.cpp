#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> arr;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        if(n%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else 
        {
            sort(arr.begin(), arr.end());
            vector<int> finarr;
            for(int i=0; i<n/2; i++)
            {
                finarr.push_back(arr[i]);
                finarr.push_back(arr[i+n/2]);
            }
            int flag=0;
            if(finarr[0]>=finarr[n-1])
            {
                flag=1;
            }
            for(int i=1; i<n-1; i+=2)
            {
                if(finarr[i]<=finarr[i-1] || finarr[i]<=finarr[i+1])
                {
                    flag=1;                   
                }
            }
            if(flag==1)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                cout<<"YES"<<endl;
                for(auto x: finarr)
                {
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}