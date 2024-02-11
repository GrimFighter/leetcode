class Solution
{
    public:
       string largestOddNumber(string num) {
        int i = num.size() - 1;
        string res = "";

        if ((num.back() - '0') % 2 != 0) { // Check if the last digit is odd
            return num;
        }

        for (i = i - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                res = num.substr(0, i + 1);
                break;
            }
        }

        return res;
    }
};