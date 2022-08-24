class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,int> m;
        for(auto x: emails) {
            string local;
            for(int i=0; x[i]!='@' && x[i]!='+'; i++) {
                if(x[i]=='.') {
                    continue;
                }
                local += x[i];
            }
            int pos = x.find('@');
            string domain = x.substr(pos);
            m[local+domain]++;
        }
        return m.size();
    }
};