class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> group;
        string str;
        for(int i=0; i<strs.size(); i++) {
            str = strs[i];
            sort(str.begin(),str.end());
            group[str].push_back(strs[i]);
        }
        for(auto x: group) {
            result.push_back(x.second);
        }
        return result;
    }
};