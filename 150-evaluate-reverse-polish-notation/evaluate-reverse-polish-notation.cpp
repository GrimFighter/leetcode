class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stack;

        unordered_map<string, function<long(long, long)>> op{
            {"+", plus<long>()},
            {"-", minus<long>()},
            {"*", multiplies<long>()},
            {"/", divides<long>()}};

        for (string token : tokens) {
            if (op.contains(token)) {
                long b = stack.top();
                stack.pop();
                long a = stack.top();
                stack.pop();
                stack.push(op[token](a, b));
            } else {
                stack.push(stoi(token));
            }
        }

        return stack.top();
    }
};