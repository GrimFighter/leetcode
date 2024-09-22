class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if (s.empty() || words.empty() || s.size() < words.size() * words[0].size())
            return {};

        int wordsArrLen = words.size();
        int wordLen = words[0].size();
        int totalLen = wordsArrLen * wordLen;
        vector<int> ans;
        unordered_map<string, int> count;

        // Step 1: Count the frequency of each word in words
        for (const string& word : words)
            ++count[word];

        // Step 2: Sliding window approach, starting from every possible position
        for (int i = 0; i < wordLen; ++i) {
            int left = i, matchedWords = 0;
            unordered_map<string, int> seen;
            
            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);
                
                // Step 3: If word is part of words, add to seen map
                if (count.find(word) != count.end()) {
                    ++seen[word];
                    ++matchedWords;
                    
                    // If word is seen too many times, slide window to the right
                    while (seen[word] > count[word]) {
                        string leftWord = s.substr(left, wordLen);
                        --seen[leftWord];
                        left += wordLen;
                        --matchedWords;
                    }

                    // If we matched all words, record the starting index
                    if (matchedWords == wordsArrLen)
                        ans.push_back(left);
                } else {
                    // If the word is not valid, reset and move left pointer
                    seen.clear();
                    matchedWords = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return ans;
    }
};
