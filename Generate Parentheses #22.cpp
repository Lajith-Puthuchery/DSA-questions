class Solution {
public:
    bool check(string s) 
    { 
        int n=s.size(); 
        stack<char> st; 
        for(int i=0;i<s.size();i++) 
        { 
            if(s[i]=='(')
                st.push('('); 
            else if(!st.empty() && st.top()=='(')
                st.pop();
            else
                return false;
        } 
        return st.empty();
    } 
     
    void perm(vector<string> &result, int n, string s) 
    { 
            if(s.size()==(2*n))
            { 
                if(check(s)) 
                    result.push_back(s); 
                return; 
            } 
            perm(result, n, s+'('); 
            perm(result, n, s+')'); 
                 
    } 
    
    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        string s = ""; 
        perm(result, n, s); 
        return result;    
    }
};