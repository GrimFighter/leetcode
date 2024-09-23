class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0, end = 0, far = 0;

        for (int i = 0; i < nums.size(); ++i) {
            far = max(far, i + nums[i]);

            if (end == nums.size() - 1) {
                break;
            }
            if (i == end) {
                end = far;
                ++jumps;
            }
        }
        return jumps;
    }
};