class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int start=0, end=-1;
        int max_length=0;
        unordered_map<char,int> m;
        for(int i=0; i<n; i++) {
            m[s[i]]=0;
        }
        for(int i=0; i<n; i++) {
            if(m[s[i]]<1) {
                end++;
                m[s[i]]++;
            }
            else {
                while(m[s[i]]>=1) {
                    m[s[start]]--;
                    start++;
                }
                m[s[i]]++;
                end++;
            }
            max_length = std::max(max_length,end-start+1);
        }
        return max_length;
    }
};