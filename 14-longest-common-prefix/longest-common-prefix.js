/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    let words = strs;
    let firstWord = strs[0];
    let res = "";
    for (let j = 0; j < firstWord.length; j++) {
        const firstWordFirstLetter = firstWord[j];
        for (let i = 0; i < words.length; i++) {
            const currentWordFirstLetter = words[i][j];
            if (currentWordFirstLetter !== firstWordFirstLetter) {
                return res;
            }
        }
        res += firstWordFirstLetter;
    }
    return res;
};