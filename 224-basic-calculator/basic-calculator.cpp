class Solution {
public:
    int calculate(string s) {

        if(s.size() == 1) return stoi(s);
        int num = 0, ans = 0, sign = 1;

        stack<int> stack{{sign}};

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '(') {
                stack.push(sign);
            } else if (c == ')') {
                stack.pop();
            } else if (c == '+' || c == '-') {
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * stack.top();
                num = 0;
            }
        }
        return ans + sign * num;
    }
};