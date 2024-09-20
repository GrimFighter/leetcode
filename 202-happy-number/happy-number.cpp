class Solution {
public:
    bool isHappy(int n) {

        int slow = squaredSum(n);
        int fast = squaredSum(squaredSum(n));

        while (slow != fast) {
            slow = squaredSum(slow);
            fast = squaredSum(squaredSum(fast));
        }

        return slow == 1;
    }

    int squaredSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += pow(n % 10, 2);
            n = n / 10;
        }

        return sum;
    }
};