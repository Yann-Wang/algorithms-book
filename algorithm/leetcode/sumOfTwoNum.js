var twoSum = function(nums, target) {
    var numsMap = {};
    nums.forEach(function(item) {
        numsMap[item] = 1;
    });

    for (var i=0, another; i<nums.length; i++) {
        another = target - nums[i];
        if (numsMap[another] && nums[i] !== another) {
            break;
        }
    }

    return [nums[i], another];
};

var result = twoSum([2,7,11,15], 9);
console.log(result);
