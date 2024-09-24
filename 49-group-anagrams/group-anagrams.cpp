class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;

        for( string s: strs){
            string key = s;
            ranges::sort(key);
            map[key].push_back(s);
        }

        for(auto it : map){
            ans.push_back(it.second);
        }

        return ans;
    }
};