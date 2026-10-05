from collections import deque

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answers = [[]]
        for num in nums:
            answers += [subset + [num] for subset in answers]


        return answers