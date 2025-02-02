"""
    https://leetcode.com/problems/jewels-and-stones/
"""

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        counter = 0
        for i in S:
            if i in J:
                counter += 1
        return counter
