class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string>ans;
        
        if(s.length() <  10) return {};
        
        for(int i=0;i<s.length()-9;i++)
        {
            seen[s.substr(i, 10)]++;
        }
        
        for(auto it: seen)
        {
            if(it.second>1)
            {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};