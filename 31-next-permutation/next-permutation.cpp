class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), aloc = 0, bloc = 0, flag=0;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] < nums[i + 1]) {
                aloc = max(aloc, i);
               
                flag = 1;
            }
        }

        if (flag == 0) {
            sort(nums.begin(), nums.begin() + n);
           
        }

       else{ for (int i = aloc; i < n; i++) {
            if (nums[i] > nums[aloc]) {
                bloc = max(bloc, i);
            }
        }

        swap(nums[aloc], nums[bloc]);
        reverse((nums.begin() + aloc + 1), nums.begin() + n);
       }
    }
};