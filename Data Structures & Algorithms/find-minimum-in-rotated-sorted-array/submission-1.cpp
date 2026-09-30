class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int left_idx = 0;
        int right_idx = n - 1;

        while (left_idx < right_idx) {
            int mid_idx = left_idx + (right_idx - left_idx) / 2;

            if (nums[mid_idx] < nums[right_idx]) {
                right_idx = mid_idx;
            } else {
                left_idx = mid_idx + 1;
            }
        }

        return nums[left_idx];
    }
};
