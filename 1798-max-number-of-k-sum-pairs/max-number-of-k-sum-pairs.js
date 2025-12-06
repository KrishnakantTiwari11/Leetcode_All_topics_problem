/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function (nums, k) {
    const mp = {};
    let res = 0;
    nums.forEach((item) => {
      mp[item]=(mp[item] || 0)+1;
    })
    nums.forEach((item) => {
        const diff = k - item;
        if (mp[item] > 0 && mp[diff] > 0 && !(diff === item && mp[diff] <= 1)) {
            mp[item]--;
            mp[diff]--;
            res++;
        }
    })
    return res;

};