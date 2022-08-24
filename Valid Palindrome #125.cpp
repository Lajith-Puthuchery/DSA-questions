class Solution {
public:
    bool isPalindrome(string s) {
        int low=0;
        int high=s.size()-1;
        if(s.size()==1)
            return true;
        for(int i=0; i<s.size(); i++) {
            
            s[i] = tolower(s[i]);
        }
        while(low<=high) {
            while(!((s[low]>='a' && s[low]<='z') || (s[low]>='A' && s[low]<='Z')||(s[low]>='0' && s[low]<='9'))) {
                low++;
                if(low==s.size())
                    return true;
            }
         while(!((s[high]>='a' && s[high]<='z') || (s[high]>='A' && s[high]<='Z')||(s[high]>='0' && s[high]<='9'))) {
                high--;
             if(high==-1)
                 return true;
            }       
            if(s[low]!=s[high])
                return false; 
            low++;
            high--;
        }
        return true;
    }
};