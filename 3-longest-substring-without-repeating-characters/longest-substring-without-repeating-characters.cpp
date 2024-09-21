class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int n = s.size(), l = 0, r, ans = 0;

        for (r = 0; r < n; r++) {
            count[s[r]]++;

            while (count[s[r]] > 1) {
                count[s[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
