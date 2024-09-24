class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // int i = 0, j = 0;
        // ranges::sort(ransomNote);
        // ranges::sort(magazine);

        // for (; i < magazine.length(); ++i) {
        //     if (ransomNote[j] == magazine[i]) {
        //         ++j;
        //     }
        // }

        // return j == ransomNote.length();


        unordered_map<char, int> map;

        for(char c: magazine){
            ++map[c];
        }

        for(char c: ransomNote){
            if(map[c] <= 0){
                return false;
            }
            --map[c];
        }
        return true;
    }
};