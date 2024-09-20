class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);

            }

            else {
                if (stack.empty() || s[i] == ')' && stack.top() != '(' ||
                    s[i] == '}' && stack.top() != '{' ||
                    s[i] == ']' && stack.top() != '[') {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};