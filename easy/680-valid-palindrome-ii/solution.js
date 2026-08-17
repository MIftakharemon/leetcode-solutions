/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    const isPalin = (l, r) => {
        while (l < r) {
            if (s[l] !== s[r]) return false;
            l++;
            r--;
        }
        return true;
    };
    let left = 0, right = s.length - 1;
    while (left < right) {
        if (s[left] !== s[right]) return isPalin(left + 1, right) || isPalin(left, right - 1);
        left++;
        right--;
    }
    return true;
};