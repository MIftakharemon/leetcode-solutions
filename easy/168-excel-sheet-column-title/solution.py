class Solution:
    def convertToTitle(self, n: int) -> str:
        r = []
        while n > 0:
            n -= 1
            r.append(chr(65 + n % 26))
            n //= 26
        return ''.join(reversed(r))