# https://leetcode.com/problems/search-insert-position/

from typing import List

def searchInsert(nums: List[int], target: int) -> int:
    for i in range(len(nums)):
        if nums[i] >= target:
            return i
        elif i == len(nums)-1:
            return i+1

if __name__ == "__main__":
    nums = [1,2,3,45,65]
    target = 81
    output = searchInsert(nums, target)
    print(output)