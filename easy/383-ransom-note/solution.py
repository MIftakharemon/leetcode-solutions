class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import Counter
        rc, mc = Counter(ransomNote), Counter(magazine)
        for c, count in rc.items():
            if mc[c] < count:
                return False
        return True