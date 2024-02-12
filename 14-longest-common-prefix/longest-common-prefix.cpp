class Solution
{
    public:
       string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0]; // Initialize prefix as the first string
        
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j); // Update prefix to the common substring
            if (prefix.empty()) break; // If prefix becomes empty, break early
        }
        
        return prefix;
    }
};
