/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    const build = (str) => {
        const stack = [];
        for (const c of str) {
            if (c === '#') stack.pop();
            else stack.push(c);
        }
        return stack.join('');
    };
    return build(s) === build(t);
};