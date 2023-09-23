import sys

class Solution:
    def maxProfit(self, stockStory) -> int:
        bTest = bCheck = sys.maxsize
        profST = proLT = 0
        for p in stockStory:
            bTest = min(bTest, p)
            profST = max(profST, p - bTest)
            bCheck = min(bCheck, p - profST)
            proLT = max(proLT, p - bCheck)
        return proLT

test = Solution()
res = test.maxProfit([3, 3, 5, 0, 0, 3, 1, 4])
print(res)