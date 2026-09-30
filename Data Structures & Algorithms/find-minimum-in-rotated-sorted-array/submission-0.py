class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)

        left_idx = 0
        right_idx = n - 1

        while left_idx < right_idx:
            mid_idx = (left_idx + right_idx) // 2

            if nums[mid_idx] == nums[right_idx]:
                return nums[left_idx]
            elif nums[mid_idx] < nums[right_idx]:
                right_idx = mid_idx
            else:
                left_idx = mid_idx + 1
        
        return nums[left_idx]