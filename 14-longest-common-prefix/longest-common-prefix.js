/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    let res = -1;
    let index = 0;
    let len = strs.length;
    if (len === 1) return strs[0];
    outerLoop: while (true) {
        for (let i = 0; i < len - 1; i++) {
            if (strs[i] === "" || (strs[i][index] === undefined || strs[i + 1][index] === undefined) || strs[i][index] !== strs[i + 1][index]) {
                break outerLoop;
            }
        }
        index++;
    }
    return strs[0].substring(0, index);

};