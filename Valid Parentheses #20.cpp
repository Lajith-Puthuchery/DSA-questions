class Solution {
public:
    bool isValid(string x) {
        stack<char> s;
        for(char c: x) {
            if(c=='(' || c=='[' || c=='{') {
                s.push(c);
            }
            else if(s.empty() || (s.top()=='(' && c!=')') || (s.top()=='{' && c!='}') || (s.top()=='[' && c!=']')) {
                return false;
            }
            else {
                s.pop();
            }
            
        }
        if(s.empty()) {
            return true;
        }
        return false;   
    }
};