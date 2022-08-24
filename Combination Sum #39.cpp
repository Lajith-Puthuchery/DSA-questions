class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<vector<int>> result;
        vector<int> curr;
        combination(candidates,target,curr,0,0,result);
        return result;
    }
    
    void combination(vector<int>& candidates, int target, vector<int>& curr, int currsum, int currindex, vector<vector<int>>& result) {
        if(target==currsum) {
            result.push_back(curr);
            return;
        }
        
        if(currsum>target) {
            return ;
        }
        
        for(int i=currindex; i<candidates.size(); i++) {
            curr.push_back(candidates[i]);
            currsum+=candidates[i];
            combination(candidates,target,curr,currsum,i,result);
            curr.pop_back();
            currsum-=candidates[i];
        }
    }
};