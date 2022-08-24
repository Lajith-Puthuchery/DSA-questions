class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) 
            return false;
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        for(int i=0; i<s.size(); i++) {
            s_map[s[i]]++;
        }
        for(int i=0; i<t.size(); i++) {
            t_map[t[i]]++;
        }
        for(int i=0; i<s.size(); i++) {
            if(s_map[s[i]]!=t_map[s[i]])
                return false;
        }
        return true;
    }
};