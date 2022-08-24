class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0;
        int arr[10000];
        int i;
        int j;
        for(i=0, j=0;i<m && j<n; k++) {
            if(nums1[i]>nums2[j]) {
                arr[k]=nums2[j];
                j++;
            }
            else {
                arr[k]=nums1[i];
                i++;
            }
        }
        if(i==m) {
            while(j<n) {
                arr[k]=nums2[j];
                k++;
                j++;
            }
        }
        else if(j==n) {
            while(i<m) {
                arr[k]=nums1[i];
                k++;
                i++;
            }
        }      
        for(int i=0; i<k; i++) {
            nums1[i]=arr[i];
        }
    }
};