class Solution:
    def titleToNumber(self, t: str) -> int:
        r = 0
        for c in t:
            r = r * 26 + (ord(c) - 64)
        return r