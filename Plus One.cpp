class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result;
        if(digits[n-1]!=9) {
            digits[n-1] += 1;
                for(auto x : digits) {
                    result.push_back(x);
                }
        }
        else {
            int i = n-1;
            while(digits[i] == 9 && i!=0) {
                digits[i] = 0;
                i--;
            }
            if(i==0 && digits[i]==9) {
                result.push_back(1); 
                digits[0] = 0;
                for(auto x : digits) {
                    result.push_back(x);
                }
            }
            else {
                digits[i] += 1;  
                for(auto x : digits) {
                    result.push_back(x);
                }
            }
        }
        return result;
    }
};