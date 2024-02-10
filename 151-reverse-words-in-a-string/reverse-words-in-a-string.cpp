class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        string result;

        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                tokens.push_back(token);
        }}

        // Iterate backwards and concatenate words with spaces
        for (int x = tokens.size() - 1; x >= 0; x--) {
            result += tokens[x];
            if (x != 0) {
                result += ' '; // Add space unless it's the last word
            }
        }

        return result;
    
    }
};