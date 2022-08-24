#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0; i<n; i++)
        {
            int ele;
            cin>>ele;
            arr.push_back(ele);
        }
        float sum=0;
        for(auto x: arr)
        {
            sum+=x;
        }
        for(int i=0; i<n; i++)
        {
            float par_sum=sum-arr[i];
            if(par_sum/(n-1)==arr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}