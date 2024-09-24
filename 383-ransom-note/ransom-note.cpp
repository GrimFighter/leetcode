class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0, j = 0;
        ranges::sort(ransomNote);
        ranges::sort(magazine);

        for (; i < magazine.length(); ++i) {
            if (ransomNote[j] == magazine[i]) {
                ++j;
            }
        }

        return j == ransomNote.length();
    }
};